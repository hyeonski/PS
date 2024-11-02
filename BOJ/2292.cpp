#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int dist = 0;
    int i = 1;
    while (true)
    {
        for (int j = 0; j < dist * 6; ++j)
        {
            if (i == n)
            {
                break;
            }
            ++i;
        }
        if (i == n)
        {
            std::cout << dist + 1 << '\n';
            break;
        }
        ++dist;
    }
}
