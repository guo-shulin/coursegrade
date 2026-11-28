// Created: lixiaolu  2026-11-28 13:14:48

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <3249612859@qq.com>

export module cg;

import std;

//顶层分解：类型定义
export struct Grade
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
    double total; //总成绩
};

//类型别名
export using CourseGrade = std::vector<Grade>;
