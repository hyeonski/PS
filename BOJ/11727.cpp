#include <iostream>

unsigned long long int dp[1001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; std::cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = (dp[i-1] * 2 + (i % 2 ? -1 : 1)) % 10007;
    }
    std::cout << dp[n] % 10007 << '\n';
}
