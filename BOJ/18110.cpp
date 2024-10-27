#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    if (n == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int cut = (int)round(n * 0.15);
    int sum = 0;
    for (int i = cut; i < (n - cut); ++i)
    {
        sum += v[i];
    }
    std::cout << (int)round((double)sum / (n - (cut * 2))) << '\n';
}
