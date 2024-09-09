#include <iostream>
#include <algorithm>
#include <vector>

bool compare(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b)
{
    return a.first < b.first;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; std::cin >> n;
    std::vector<std::pair<int, std::string>> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first;
        std::cin >> v[i].second;
    }
    std::stable_sort(v.begin(), v.end(), compare);
    for (auto &x : v) {
        std::cout << x.first << ' ' << x.second << '\n';
    }
}