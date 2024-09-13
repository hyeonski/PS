#include <iostream>
#include <vector>
#include <algorithm>

long long int get_result(std::vector<long long int> &v, long long int length)
{
    long long int result = 0;
    for (auto &x : v)
    {
        result += (x / length);
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long long int k, n;
    std::cin >> k >> n;
    std::vector<long long int> v(k);
    for (long long int i = 0; i < k; ++i)
    {
        std::cin >> v[i];
    }
    long long int maxi = v[0];
    for (long long int i = 1; i < k; ++i)
    {
        if (maxi < v[i]) {
            maxi = v[i];
        }
    }
    long long int start = 1, end = maxi, mid, max = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (get_result(v, mid) >= n)
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
