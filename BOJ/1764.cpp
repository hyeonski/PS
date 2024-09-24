#include <iostream>
#include <set>
#include <list>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::multiset<std::string> set;
    int n, m;
    std::cin >> n >> m;
    std::string buf;
    for (int i = 0; i < n + m; ++i)
    {
        std::cin >> buf;
        set.insert(buf);
    }
    std::list<std::string> out;
    auto it = ++set.begin();
    for (auto it2 = set.begin(); it != set.end(); ++it, ++it2)
    {
        if (*it == *it2)
        {
            out.push_back(*it);
        }
    }
    std::cout << out.size() << '\n';
    for (auto &x : out)
    {
        std::cout << x << '\n';
    }
}