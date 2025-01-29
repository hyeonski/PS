#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> left, right;
    int n;
    std::cin >> n;
    left.reserve(n);
    right.reserve(n);
    int t;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> t;
        left.push_back(t);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> t;
        right.push_back(t);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            t = left[i] - right[j];
            if (-4 <= t && t <= 4)
            {
                ++cnt;
            }
        }
    }
    std::cout << cnt << '\n';
}
