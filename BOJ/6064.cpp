#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    std::pair<int, int> cal;
    int m, n, x, y, k;
    while (t--)
    {
        std::cin >> m >> n >> x >> y;
        cal = {1, 1};
        k = 1;
        while (cal.first != x && cal.second != y)
        {
            ++cal.first;
            ++cal.second;
            ++k;
        }
        while (true)
        {
            if (k > m * n)
            {
                std::cout << -1 << '\n';
                break;
            }
            if (cal.first == x && cal.second == y)
            {
                std::cout << k << '\n';
                break;
            }
            if (cal.first == x)
            {
                cal.second = ((cal.second + m - 1) % n) + 1;
                k += m;
            }
            else
            {
                cal.first = ((cal.first + n - 1) % m) + 1;
                k += n;
            }
        }
    }
}
