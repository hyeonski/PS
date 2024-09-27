#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string buf;
    std::getline(std::cin, buf);
    buf.erase(0, buf.find_first_not_of(' '));
    buf.erase(buf.find_last_not_of(' ') + 1);
    int cnt = 0;
    for (auto &x : buf)
    {
        if (x == ' ')
        {
            ++cnt;
        }
    }
    std::cout << (buf != "" ? cnt + 1 : 0) << '\n';
}
