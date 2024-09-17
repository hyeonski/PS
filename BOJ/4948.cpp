#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    bool isprime;
    int cnt;
    while (true)
    {
        std::cin >> n;
        if (n == 0)
        {
            break;
        }
        cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
        {
            isprime = true;
            if (i == 2)
            {
                ++cnt;
            }
            else
            {
                for (int j = 2; j <= (int)(sqrt(i) + 1); ++j)
                {
                    if (i % j == 0)
                    {
                        isprime = false;
                        break;
                    }
                }
                if (isprime)
                {
                    ++cnt;
                }
            }
        }
        std::cout << cnt << '\n';
    }
}
