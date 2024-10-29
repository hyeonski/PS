#include <iostream>
#include <queue>
#include <vector>

char map[100][100];
int n;

int bfs()
{
    int cnt = 0;
    std::vector<std::vector<bool>> v(n, std::vector<bool>(n, false));
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!v[i][j])
            {
                std::queue<std::pair<int, int>> q;
                q.push({i, j});
                v[i][j] = true;
                while (!q.empty())
                {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    if (x > 0 && !v[x - 1][y] && map[x - 1][y] == map[x][y])
                    {
                        q.push({x - 1, y});
                        v[x - 1][y] = true;
                    }
                    if (x < n - 1 && !v[x + 1][y] && map[x + 1][y] == map[x][y])
                    {
                        q.push({x + 1, y});
                        v[x + 1][y] = true;
                    }
                    if (y > 0 && !v[x][y - 1] && map[x][y - 1] == map[x][y])
                    {
                        q.push({x, y - 1});
                        v[x][y - 1] = true;
                    }
                    if (y < n - 1 && !v[x][y + 1] && map[x][y + 1] == map[x][y])
                    {
                        q.push({x, y + 1});
                        v[x][y + 1] = true;
                    }
                }
                ++cnt;
            }
        }
    }

    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    std::string buf;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf;
        for (int j = 0; j < n; ++j)
        {
            map[i][j] = buf[j];
        }
    }
    int r1 = bfs();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == 'G')
            {
                map[i][j] = 'R';
            }
        }
    }
    int r2 = bfs();
    std::cout << r1 << ' ' << r2 << '\n';
}
