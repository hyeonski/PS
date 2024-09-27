#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; std::cin >> n;
    unsigned long long int dp[100];
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    std::cout << dp[n] << '\n';
}
