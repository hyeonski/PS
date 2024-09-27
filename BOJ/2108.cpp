#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int cnt[8001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        ++cnt[v[i] + 4000];
        sum += v[i];
    }
    std::sort(v.begin(), v.end());
    int max = 0;
    std::vector<int> max_n;
    for (int i = 0; i <= 8000; ++i)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            max_n.clear();
            max_n.push_back(i - 4000);
        }
        else if (cnt[i] == max)
        {
            max_n.push_back(i - 4000);
        }
    }
    std::cout << static_cast<int>(round(sum / static_cast<double>(n))) << '\n';
    std::cout << v[n / 2] << '\n';
    std::cout << (max_n.size() == 1 ? max_n[0] : max_n[1]) << '\n';
    std::cout << v[n - 1] - v[0] << '\n';
}
