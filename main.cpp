import std;
import cg.data;
import cg.input;

int main()
{
    Grade g{};
    read(g);
    std::println("语文：{}，数学：{}，英语：{}", g.chinese, g.math, g.english);
    return 0;
}
