#include <iostream>

int adjmat[101][101];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> adjmat[i][j];
            if (adjmat[i][j] == 0)
            {
                adjmat[i][j] = 99999;
            }
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (adjmat[i][j] > adjmat[i][k] + adjmat[k][j])
                {
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (adjmat[i][j] != 99999)
            {
                std::cout << 1 << ' ';
            }
            else
            {
                std::cout << 0 << ' ';
            }
        }
        std::cout << '\n';
    }
}