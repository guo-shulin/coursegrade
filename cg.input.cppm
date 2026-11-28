export module cg.input;
import cg.data;
import std;

export void read(Grade &g)
{
    std::cout << "请输入语文、数学、英语分数：";
    std::cin >> g.chinese >> g.math >> g.english;
}
