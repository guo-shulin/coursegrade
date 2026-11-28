// Created: lixiaolu  2026-11-28 13:17:36

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <3249612859@qq.com>

module cg.input; //声明为cg.input模块的实现单元

import std;
import cg;

std::istream& operator>>(std::istream& is, Grade& g)
{
    std::print("  Reading a student grade... ");
    if (is >> g.name >> g.midterm >> g.final)
    {
        if (!is.eof() && is.fail())
            throw std::invalid_argument("Incorrect name, midterm and final grade.");

        if (is)
        {
            for (double h; is >> h;) g.homework.push_back(h);

            if (!is.eof() && is.fail())
                throw std::invalid_argument("Incorrect homework grade.");

            if (is.eof() && g.homework.size() != 0)
            {
                is.clear();
                std::print("Done!  {}\n", g.name);
            }
        }
    }
    if (!is) std::print("Error!\n");
    return is;
}

//第二层未知计算的具体实现
void read(CourseGrade& cg)
{
    std::print("Reading all student grades (name midterm final homework) from a file... \n");
    std::ifstream ifs("../../coursegrade.dat");
    if (!ifs) throw std::runtime_error("fail to open file");

    std::string line;
    std::istringstream iss;
    while (std::getline(ifs, line))
    {
        iss.str(line);
        Grade g;
        if (iss >> g)
        {
            cg.push_back(g);
        } else
        {
            iss.clear();
        }
    }
    if (ifs.eof()) std::print("Reading done!\n\n");
}