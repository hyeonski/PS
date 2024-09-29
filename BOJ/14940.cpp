#include <iostream>
#include <queue>

int map[1000][1000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, sr, sc;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 2)
            {
                sr = i;
                sc = j;
            }
        }
    }

    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    int r, c;
    int nr, nc;
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && map[nr][nc] == 1)
            {
                map[nr][nc] = map[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] >= 2)
            {
                std::cout << map[i][j] - 2 << " ";
            }
            else if (map[i][j] == 0)
            {
                std::cout << 0 << " ";
            }
            else if (map[i][j] == 1)
            {
                std::cout << -1 << " ";
            }
        }
        std::cout << '\n';
    }
}
