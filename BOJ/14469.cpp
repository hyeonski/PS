#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::pair<int, int>> cow;
    int n;
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        cow.push_back({a, b});
    }
    std::sort(cow.begin(), cow.end());
    int time = 0;
    for (auto it = cow.begin(); it != cow.end(); ++it)
    {
        if (time < it->first)
        {
            time = it->first + it->second;
        }
        else
        {
            time += it->second;
        }
    }
    std::cout << time << '\n';
}
