#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b)
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

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
    }
    std::sort(v.begin(), v.end(), compare);
    int cnt = 0, last;
    last = 0;
    for (auto &x : v)
    {
        if (x.first < last)
        {
            continue;
        }
        last = x.second;
        ++cnt;
    }
    std::cout << cnt << '\n';
}
