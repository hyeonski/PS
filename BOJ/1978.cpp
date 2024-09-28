#include <iostream>
#include <cmath>
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int in, root, cnt = 0;
    bool isprime;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        if (in == 1)
        {
            continue;
        }
        if (in == 2)
        {
            ++cnt;
            continue;
        }
        root = sqrt(in) + 1;
        isprime = true;
        for (int j = 2; j <= root; ++j)
        {
            if (in % j == 0)
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
    std::cout << cnt << '\n';
}