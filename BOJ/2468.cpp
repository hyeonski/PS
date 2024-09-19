#include <iostream>
#include <list>

int area[100][100];
bool check[100][100];
std::list<std::pair<int, int>> location[101];
int max = 0;
int n;

void dfs(int x, int y)
{
    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {-1, 1, 0, 0};

    int nx, ny;
    check[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !check[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    int hmax = 0, hmin = 100;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> tmp;
            area[i][j] = tmp;
            check[i][j] = true;
            if (hmax < tmp)
            {
                hmax = tmp;
            }
            if (hmin > tmp)
            {
                hmin = tmp;
            }
            location[tmp].push_back({i, j});
        }
    }

    for (int i = hmax - 1; i >= hmin - 1; --i)
    {
        for (int j = hmax; j > i; --j)
        {
            for (auto &x : location[j])
            {
                check[x.first][x.second] = false;
            }
        }
        int cnt = 0;
        for (int j = hmax; j > i; --j)
        {
            for (auto &x : location[j])
            {
                if (!check[x.first][x.second])
                {
                    dfs(x.first, x.second);
                    ++cnt;
                }
            }
        }
        if (cnt > max)
        {
            max = cnt;
        }
    }
    std::cout << max << '\n';
}