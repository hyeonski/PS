#include <iostream>
#include <queue>

int map[600][600];
bool v[600][600];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string buf;
    int sx, sy;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf;
        for (int j = 0; j < m; ++j)
        {
            if (buf[j] == 'I')
            {
                sx = i;
                sy = j;
            }
            map[i][j] = buf[j];
        }
    }

    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {-1, 1, 0, 0};
    int cnt = 0;
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    v[sx][sy] = true;
    std::pair<int, int> cur;
    int nx, ny;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (map[cur.first][cur.second] == 'P')
        {
            ++cnt;
        }
        for (int i = 0; i < 4; ++i)
        {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && map[nx][ny] != 'X')
            {
                q.push({nx, ny});
                v[nx][ny] = true;
            }
        }
    }
    if (cnt == 0)
    {
        std::cout << "TT\n";
    }
    else
    {
        std::cout << cnt << '\n';
    }
}
