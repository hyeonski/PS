#include <iostream>
#include <queue>
#include <vector>

int box[101][101][101];
int m, n, h, max = 1;
std::queue<std::vector<int>> q;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> m >> n >> h;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                std::cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    q.push({i, j, k});
                }
            }
        }
    }

    int i, j, k, l;
    while (!q.empty())
    {
        i = q.front()[0];
        j = q.front()[1];
        k = q.front()[2];
        q.pop();
        l = box[i][j][k];
        if (l > max)
        {
            max = l;
        }
        if (i > 0 && box[i - 1][j][k] == 0)
        {
            box[i - 1][j][k] = l + 1;
            q.push({i - 1, j, k});
        }
        if (i < h - 1 && box[i + 1][j][k] == 0)
        {
            box[i + 1][j][k] = l + 1;
            q.push({i + 1, j, k});
        }
        if (j > 0 && box[i][j - 1][k] == 0)
        {
            box[i][j - 1][k] = l + 1;
            q.push({i, j - 1, k});
        }
        if (j < n - 1 && box[i][j + 1][k] == 0)
        {
            box[i][j + 1][k] = l + 1;
            q.push({i, j + 1, k});
        }
        if (k > 0 && box[i][j][k - 1] == 0)
        {
            box[i][j][k - 1] = l + 1;
            q.push({i, j, k - 1});
        }
        if (k < m - 1 && box[i][j][k + 1] == 0)
        {
            box[i][j][k + 1] = l + 1;
            q.push({i, j, k + 1});
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if (box[i][j][k] == 0)
                {
                    std::cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    std::cout << max - 1 << '\n';
}