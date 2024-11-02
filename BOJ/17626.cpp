#include <iostream>
#include <algorithm>

int dp[50001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        dp[i * i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            dp[i] = dp[1] + dp[i - 1];
            for (int j = 2; j * j <= i; j++)
            {
                dp[i] = std::min(dp[i], dp[j * j] + dp[i - j * j]);
            }
        }
    }
    std::cout << dp[n] << '\n';
    return 0;
}
