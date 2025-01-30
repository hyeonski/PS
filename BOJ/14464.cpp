#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int c, n;
    std::cin >> c >> n;
    std::vector<int> chicken(c);
    std::vector<std::pair<int, int>> cow(n);
    std::vector<bool> check(n, false);
    int a, b;
    for (int i = 0; i < c; ++i)
    {
        std::cin >> a;
        chicken[i] = a;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        cow[i] = {a, b};
    }
    std::sort(chicken.begin(), chicken.end());
    std::sort(cow.begin(), cow.end(), compare);
    int cnt = 0, now;
    for (int i = 0; i < c; ++i)
    {
        now = chicken[i];
        for (int j = 0; j < n; ++j)
        {
            if (cow[j].first <= now && now <= cow[j].second && check[j] == false)
            {
                ++cnt;
                check[j] = true;
                break;
            }
        }
    }
    std::cout << cnt << '\n';
}
