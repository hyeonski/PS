#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    std::vector<int> dp(n);
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = std::max(v[2] + std::max(v[0], v[1]), dp[1]);
    for (int i = 3; i < n; ++i)
    {
        dp[i] = std::max(v[i] + std::max(v[i - 1] + dp[i - 3], dp[i - 2]), dp[i - 1]);
    }
    std::cout << dp[n - 1] << '\n';
}