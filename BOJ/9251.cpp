#include <iostream>
#include <algorithm>

int dp[1001][1001];

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    for (std::string::size_type i = 1; i <= a.size(); ++i)
    {
        for (std::string::size_type j = 1; j <= b.size(); ++j)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    std::cout << dp[a.size()][b.size()] << '\n';
}
