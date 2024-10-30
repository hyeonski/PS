#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    if (n <= 2)
    {
        std::cout << n << '\n';
        return 0;
    }
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    int num[2] = {v[0], v[1]};
    int max = 2;
    int len = 2;
    for (int i = 2; i < n; ++i)
    {
        if (v[i] != num[0] && v[i] != num[1])
        {
            if (max < len)
            {
                max = len;
            }
            len = 2;
            num[0] = v[i - 1];
            num[1] = v[i];
            for (int j = i - 2; j >= 0; --j)
            {
                if (v[j] == v[i - 1])
                {
                    ++len;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            ++len;
        }
    }
    if (max < len)
    {
        max = len;
    }
    std::cout << max << '\n';
}