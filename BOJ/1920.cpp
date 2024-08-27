#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::set<int> s;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        s.insert(tmp);
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> tmp;
        if (s.find(tmp) != s.end())
        {
            std::cout << 1 << "\n";
        }
        else
        {
            std::cout << 0 << "\n";
        }
    }
}
