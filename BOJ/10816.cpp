#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::unordered_map<int, int> map;
    int n; std::cin >> n;
    int k;
    while (n--)
    {
        std::cin >> k;
        auto it = map.find(k);
        if (it == map.end())
        {
            map[k] = 1;
        }
        else
        {
            ++it->second;
        }
    }
    int m; std::cin >> m;
    while (m--)
    {
        std::cin >> k;
        auto it = map.find(k);
        if (it == map.end())
        {
            std::cout << 0 << ' ';
        }
        else
        {
            std::cout << it->second << ' ';
        }
    }
    std::cout << '\n';
}
