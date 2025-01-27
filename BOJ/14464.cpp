#include <iostream>
#include <list>
#include <algorithm>

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
    int cnt = 0;
    int min = 2147483647;
    for (auto it = chicken.begin(); it != chicken.end(); ++it)
    {
        min = 2147483647;
        auto idx = cow.begin();
        for (auto it2 = cow.begin(); it2 != cow.end(); ++it2)
        {
            if (it2->first <= *it && *it <= it2->second && min >= (it2->second - it2->first))
            {
                if (min == (it2->second - it2->first))
                {
                    if (idx->first > it2->first)
                    {
                        idx = it2;
                    }
                }
                else
                {
                    min = (it2->second - it2->first);
                    idx = it2;
                }
            }
        }
        if (min != 2147483647)
        {
            ++cnt;
            cow.erase(idx);
        }
    }
    std::cout << cnt << '\n';
}
