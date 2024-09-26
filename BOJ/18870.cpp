#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::pair<int, int> &a, std::pair<int, int> &b)
{
    return a.first < b.first;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> v1(n);
    std::vector<std::pair<int, int>> v2(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v1[i];
        v2[i] = {v1[i], i};
    }
    std::sort(v2.begin(), v2.end(), compare);
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0 && v2[i].first != v2[i - 1].first)
        {
            ++idx;
        }
        v1[v2[i].second] = idx;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << v1[i] << ' ';
    }
    std::cout << '\n';
}
