#include <iostream>
#include <unordered_map>

int main()
{
    int t, n;
    std::cin >> t;
    std::string cloth, type;
    while (t--)
    {
        std::unordered_map<std::string, int> map;
        std::cin >> n;
        while (n--)
        {
            std::cin >> cloth >> type;
            ++map[type];
        }
        int res = 1;
        for (auto &x : map)
        {
            res *= (x.second + 1);
        }
        std::cout << res - 1 << '\n';
    }
}