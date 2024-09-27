#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    int r;
    std::string s;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> r >> s;
        for (auto &x : s)
        {
            for (int j = 0; j < r; ++j)
            {
                std::cout << x;
            }
        }
        std::cout << '\n';
    }
}
