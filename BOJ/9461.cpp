#include <iostream>


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    unsigned long long int dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    int n, t, last = 3;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> n;
        if (n > last)
        {
            for (int j = last + 1; j <= n; ++j)
            {
                dp[j] = dp[j-2] + dp[j-3];
            }
            last = n;
        }
        std::cout << dp[n] << '\n';
    }
}