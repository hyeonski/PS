#include <iostream>

unsigned long long int dp[100001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> dp[i];
        dp[i] = dp[i] + dp[i-1];
    }
    int i, j;
    for (int k = 0; k < m; ++k)
    {
        std::cin >> i >> j;
        std::cout << dp[j] - dp[i-1] << '\n';
    }
}
