//
// Created: hxd  2026-11-28 18:22:55

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <xxx@qq.com>

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
    return 0;
}
