#include <iostream>
#include <vector>

int n, m;
int map[500][500];
bool v[500][500];
int max = 0;

void dfs(std::vector<std::pair<int, int>> &path, int sum)
{
    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {-1, 1, 0, 0};
    if (path.size() == 4)
    {
        if (sum > max)
        {
            max = sum;
        }
        return;
    }
    int nx, ny;
    for (auto &p : path)
    {
        for (int i = 0; i < 4; ++i)
        {
            nx = p.first + dx[i];
            ny = p.second + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny])
            {
                v[nx][ny] = true;
                path.push_back({nx, ny});
                dfs(path, sum + map[nx][ny]);
                path.pop_back();
                v[nx][ny] = false;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::vector<std::pair<int, int>> path;
            path.reserve(4);
            path.push_back({i, j});
            v[i][j] = true;
            dfs(path, map[i][j]);
            v[i][j] = false;
        }
    }
    std::cout << max << '\n';
}
