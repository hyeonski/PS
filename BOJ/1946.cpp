#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    int n, f, iv, cnt, max;

    while (t--)
    {
        std::cin >> n;
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> f >> iv;
            v[i] = {f, iv};
        }
        std::sort(v.begin(), v.end());
        cnt = 1;
        max = v[0].second;
        for (int i = 1; i < n; ++i)
        {
            if (max > v[i].second)
            {
                ++cnt;
                max = v[i].second;
            }
        }
        std::cout << cnt << '\n';
    }
}
