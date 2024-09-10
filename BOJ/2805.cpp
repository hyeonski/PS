#include <iostream>
#include <vector>
#include <algorithm>

long long int get_result(std::vector<long long int> &v, long long int height)
{
    long long int result = 0;
    for (auto &x : v)
    {
        if (x > height)
        {
            result += (x - height);
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long long int n, m;
    std::cin >> n >> m;
    std::vector<long long int> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    long long int start = 0, end = v[n - 1], mid, result, max = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        result = get_result(v, mid);
        if (result >= m)
        {
            start = mid + 1;
            if (mid > max)
            {
                max = mid;
            }
        }
        else
        {
            end = mid - 1;
        }
    }
    std::cout << max << '\n';
}
