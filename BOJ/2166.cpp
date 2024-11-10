#include <iostream>
#include <vector>

int n;
std::vector<std::pair<int, int>> v;

long double solve(int i, int j)
{
    long double a = v[0].first, b = v[0].second;
    long double c = v[i].first, d = v[i].second;
    long double e = v[j].first, f = v[j].second;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back({a, b});
    }

    long double ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ans += solve(i, i + 1);
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << std::abs(ans) << '\n';
}
