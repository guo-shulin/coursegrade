// A program that calculates the scores of all students in a course
// Created: Wei Gong  2026-11-16 16:43:44

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <open-src@qq.com>

// CourseGrade calculation using a top-down, stepwise refinement approach

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <print>

#include <istream>
using std::istream;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <algorithm>
using std::ranges::stable_sort;

#include <ranges>
#include <numeric>
#include <exception>
using std::exception;
using std::runtime_error;
using std::domain_error;
using std::invalid_argument;

// 顶层分解
// 注意：修复了 incomplete type 报错，把完整定义提到了前面
struct Grade
{
    string name;
    double midterm = 0;
    double final = 0;
    vector<double> homework;
    double total = 0;
};
using CourseGrade = vector<Grade>;

extern void read(CourseGrade& cg);
extern void computeSort(CourseGrade& cg);
extern void printResult(CourseGrade& cg); // 修复：避免与 std::print 冲突

// 第1次重构，添加错误处理
int main()
{
    CourseGrade courseGrade;
    try {
        read(courseGrade);
        computeSort(courseGrade);
        printResult(courseGrade);
    } catch (const exception& e) {
        std::print("error: {}\n", e.what());
    } catch (...) {
        std::print("Other error!\n");
    }

    return 0;
}

// 第二层分解，添加错误检测
extern istream& operator>>(istream& is, Grade& g);
void read(CourseGrade& cg)
{
    std::print("Reading all student grades (name midterm final homework) from a file... \n");
    ifstream ifs("../../coursegrade.dat");
    if(!ifs) throw runtime_error("fail to open file");

    string line;
    istringstream iss;
    while (std::getline(ifs, line)) {
        iss.clear(); // 关键：每次循环前清空流状态
        iss.str(line);
        Grade g;
        if (iss >> g) {
            cg.push_back(g);
        } else {
            iss.clear();
        }
    }
    if(ifs.eof()) std::print("Reading done!\n\n");
}

extern double score(Grade& g);
void computeSort(CourseGrade& cg)
{
    std::print("Processing all student grades... \n");
    for(auto& g: cg){
        g.total = score(g);
    }
    stable_sort(cg, [](auto& g1, auto& g2){
        return g1.total <= g2.total;
    });
    std::print("Processing done!\n\n");
}

void printResult(CourseGrade& cg)
{
    std::print("Course: {}\nCredit: {}\n", "software construction and implementation", 5);
    std::print("name      total\n");
    for(auto &g: cg){
        std::print("{:<10}{:<.1f}\n", g.name, g.total);
    }
}

// 第三层分解，添加错误检测
istream& operator>>(istream& is, Grade& g)
{
    std::print("  Reading a student grade... ");
    if (is) is >> g.name >> g.midterm >> g.final;
    if(!is.eof()&&is.fail())
        throw invalid_argument("Incorrect name, midterm and final grade.");

    if (is) {
        g.homework.clear(); // 防止重用对象时数据叠加
        for (double h; is >> h;)
            g.homework.push_back(h);

        if(!is.eof() && is.fail())
            throw invalid_argument("Incorrect homework grade.");

        if(is.eof() && g.homework.size() != 0) {
            is.clear();
            std::print("Done!  {}\n", g.name);
        }
    }
    if (!is) std::print("Error!\n");
    return is;
}

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<std::ranges::forward_range R>
    requires Numeric<std::ranges::range_value_t<R>>
double median(R&& data);

double score(Grade& g)
{
    return 0.2 * g.midterm + 0.4 * g.final + 0.4 * median(g.homework);
}

// 第四层分解
template <std::ranges::forward_range R>
    requires Numeric<std::ranges::range_value_t<R>>
double median(R&& data)
{
    // 修复：GCC11 不支持 std::ranges::to，改为手动拷贝构造
    std::vector<double> temp(data.begin(), data.end());

    if (temp.empty())
        throw std::domain_error("median of an empty range");

    auto size = std::ssize(temp);
    auto mid = temp.begin() + size / 2;

    // nth_element 使用 Quickselect 算法计算无序范围中值，Avg. TC = O(N)
    std::ranges::nth_element(temp, mid);

    if (size % 2 != 0) {
        return *mid;
    }

    auto left_max = std::ranges::max_element(temp.begin(), mid);
    return std::midpoint(*left_max, *mid);
}

