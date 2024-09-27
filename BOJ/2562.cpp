#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int max = 0, max_i = -1;
    int t;
    for (int i = 0; i < 9; ++i)
    {
        std::cin >> t;
        if (max < t)
        {
            max = t;
            max_i = i;
        }
    }
    std::cout << max << '\n' << max_i + 1 << '\n';
}
