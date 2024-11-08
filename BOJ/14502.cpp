#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int n, m;

void bfs(std::vector<std::vector<int>> &map, std::vector<std::vector<bool>> &v, int a, int b)
{
    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {-1, 1, 0, 0};
    std::queue<std::pair<int, int>> q;
    q.push({a, b});
    v[a][b] = true;
    int x, y, nx, ny;
    while (!q.empty())
    {
        std::tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && map[nx][ny] == 0)
            {
                q.push({nx, ny});
                v[nx][ny] = true;
                map[nx][ny] = 2;
            }
        }
    }
}

int getcnt(std::vector<std::vector<int>> map)
{
    std::vector<std::vector<bool>> v(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 2)
            {
                bfs(map, v, i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 0)
            {
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

    std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
        }
    }

    std::vector<std::pair<int, int>> walls(n * m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            walls[i * m + j] = {i, j};
        }
    }
    int max = 0, cnt = 0;
    for (int i = 0; i < n * m; ++i)
    {
        if (map[walls[i].first][walls[i].second] == 0)
        {
            map[walls[i].first][walls[i].second] = 1;
            for (int j = i + 1; j < n * m; ++j)
            {
                if (map[walls[j].first][walls[j].second] == 0)
                {
                    map[walls[j].first][walls[j].second] = 1;
                    for (int k = j + 1; k < n * m; ++k)
                    {
                        if (map[walls[k].first][walls[k].second] == 0)
                        {
                            map[walls[k].first][walls[k].second] = 1;
                            cnt = getcnt(map);
                            map[walls[k].first][walls[k].second] = 0;
                            if (max < cnt)
                            {
                                max = cnt;
                            }
                        }
                    }
                    map[walls[j].first][walls[j].second] = 0;
                }
            }
            map[walls[i].first][walls[i].second] = 0;
        }
    }
    std::cout << max << '\n';
}