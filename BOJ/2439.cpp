#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            std::cout << ' ';
        }
        for (int j = 0; j <= i; ++j)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
