#include <iostream>

int main()
{
        std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int arr[15];
    int t, k, n;
    std::cin >> t;
    while (t--)
    {
        std::cin >> k >> n;
        for (int i = 0; i <= n; ++i)
        {
            arr[i] = i;
        }
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                arr[j] = arr[j] + arr[j - 1];
            }
        }
        std::cout << arr[n] << '\n';
    }
}