#include <iostream>
#include <queue>

int box[1000][1000];
int m, n, max = 1;
std::queue<std::pair<int, int>> q;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    int i, j, k;
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        k = box[i][j];
        if (k > max)
        {
            max = k;
        }
        if (i > 0 && box[i - 1][j] == 0)
        {
            box[i - 1][j] = k + 1;
            q.push({i - 1, j});
        }
        if (i < n - 1 && box[i + 1][j] == 0)
        {
            box[i + 1][j] = k + 1;
            q.push({i + 1, j});
        }
        if (j > 0 && box[i][j - 1] == 0)
        {
            box[i][j - 1] = k + 1;
            q.push({i, j - 1});
        }
        if (j < m - 1 && box[i][j + 1] == 0)
        {
            box[i][j + 1] = k + 1;
            q.push({i, j + 1});
        }
    }

    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (box[i][j] == 0)
            {
                std::cout << -1 << '\n';
                return 0;
            }
        }
    }
    std::cout << max - 1 << '\n';
}