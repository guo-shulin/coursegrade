<<<<<<< HEAD
import std;
import cg.data;
import cg.input;

int main()
{
    Grade g{};
    read(g);
    std::println("语文：{}，数学：{}，英语：{}", g.chinese, g.math, g.english);
=======
// Created: lixiaolu  2026-11-28 13:12:48

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <3249612859@qq.com>

import std;

import cg;
import cg.input;

int main() {
    CourseGrade courseGrade;
    try
    {
        //调用cg.input模块提供的read服务
        read(courseGrade);

    } catch (const std::exception& e)
    {
        std::print("error: {}\n", e.what());
    }
    catch (...)
    {
        std::print("Other error!\n");
    }
>>>>>>> origin/ours
    return 0;
}
