#include <iostream>

unsigned long long int dp[1000001];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] % 15746;
    }
    std::cout << dp[n] % 15746 << '\n';
}
