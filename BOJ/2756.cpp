#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    unsigned long long int sum = 0;
    std::vector<unsigned long long int> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        sum += v[i];
    }
    std::sort(v.begin(), v.end());
    std::vector<int> c(*(v.end() - 1) + 1);
    for (int i = 0; i < n; ++i)
    {
        c[v[i]] += 1;
    }

    unsigned long long int cnt = 0;
    if (sum - v[n - 1] - v[n - 2] == v[n - 3] * 2)
    {
        ++cnt;
    }

    unsigned long long int k = (sum - v[n - 1]) - v[n - 2] * 2;
    auto lt = std::lower_bound(v.begin(), v.end() - 2, k);
    auto ut = std::upper_bound(v.begin(), v.end() - 2, k);
    cnt += (ut - lt);

    int i = 0;
    unsigned long long int l, odd_cnt = 0;
    while (i < n - 1)
    {
        k = v[i];
        l = (sum - k) - v[n - 1] * 2;
        if (k != l)
        {
            lt = std::lower_bound(v.begin(), v.end() - 1, l);
            if (*lt == l)
            {
                int a = std::max(c[k], c[l]);
                int b = std::min(c[k], c[l]);
                int temp;
                if (a == 1 && b == 1)
                {
                    temp = 1;
                }
                else
                {
                    temp = (a * (a + 1)) / 2 - (b * (b + 1)) / 2;
                }
                cnt += (temp / 2);
                if (temp % 2)
                {
                    ++odd_cnt;
                }
            }
        }
        else
        {
            if (c[k] > 1)
            {
                cnt += (c[k] * (c[k] - 1)) / 2;
            }
        }
        i += c[k];
    }
    cnt += (odd_cnt / 2);
    std::cout << cnt << "\n";
}
