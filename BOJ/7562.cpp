#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using tp = std::tuple<int, int, int>;

int bfs(int l, int cx, int cy, int gx, int gy)
{
    static int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    static int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    std::queue<tp> q;
    std::vector<std::vector<bool>> v(l, std::vector<bool>(l, false));
    q.push({cx, cy, 0});
    v[cx][cy] = true;
    int nx, ny, depth = -1;
    while (!q.empty())
    {
        std::tie(cx, cy, depth) = q.front();
        if (cx == gx && cy == gy)
        {
            return depth;
        }
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            nx = dx[i] + cx;
            ny = dy[i] + cy;
            if (0 <= nx && nx < l && 0 <= ny && ny < l && !v[nx][ny])
            {
                q.push({nx, ny, depth + 1});
                v[nx][ny] = true;
            }
        }
    }
    return depth;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int k, l, cx, cy, gx, gy;
    std::cin >> k;
    while (k--)
    {
        std::cin >> l >> cx >> cy >> gx >> gy;
        std::cout << bfs(l, cx, cy, gx, gy) << '\n';
    }
}
