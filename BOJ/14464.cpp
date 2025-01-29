#include <iostream>
#include <list>
#include <algorithm>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::list<int> chicken;
    std::list<std::pair<int, int>> cow;
    int c, n;
    std::cin >> c >> n;
    int a, b;
    for (int i = 0; i < c; ++i)
    {
        std::cin >> a;
        chicken.push_back(a);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        cow.push_back({a, b});
    }
    chicken.sort();
    cow.sort(compare);
    int cnt = 0;
    auto chit = chicken.begin();
    auto coit = cow.begin();
    while (chit != chicken.end())
    {
        coit = cow.begin();
        while (coit != cow.end() && coit->second < *chit)
        {
            ++coit;
        }
        cow.erase(cow.begin(), coit);
        if (cow.empty())
        {
            break;
        }
        int min = 2147483647;
        auto target = cow.end();
        while (coit != cow.end() && coit->first <= *chit && coit->second >= *chit)
        {
            if (coit->second < min)
            {
                min = coit->second;
                target = coit;
            }
            ++coit;
        }
        if (target != cow.end())
        {
            cow.erase(target);
            ++cnt;
        }
        ++chit;
    }
    std::cout << cnt << '\n';
}
