#include <iostream>
#include <queue>
#include <tuple>

bool map[100][100];
bool v[100][100];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string buf;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf;
        for (int j = 0; j < m; ++j)
        {
            map[i][j] = buf[j] - '0';
        }
    }
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    std::queue<std::tuple<int, int, int>> q;
    q.push({0, 0, 1});
    v[0][0] = true;
    int x, y, d, nx, ny;
    while (!q.empty())
    {
        std::tie(x, y, d) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] && !v[nx][ny])
            {
                q.push({nx, ny, d + 1});
                v[nx][ny] = true;
            }
        }
    }
    std::cout << d << '\n';
}