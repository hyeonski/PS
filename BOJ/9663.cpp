#include <iostream>

int n;
int cnt;
bool map[15][15];

void backtrack(int depth)
{
    if (depth == n)
    {
        ++cnt;
        return;
    }
    bool pos;
    int ld, rd;
    for (int i = 0; i < n; ++i)
    {
        pos = true;
        for (int j = 0; j < depth; ++j)
        {
            ld = i - (depth - j);
            rd = i + (depth - j);

            if (map[j][i] || (0 <= ld && ld < n && map[j][ld]) || (0 <= rd && rd < n && map[j][rd]))
            {
                pos = false;
                break;
            }
        }
        if (pos)
        {
            map[depth][i] = true;
            backtrack(depth + 1);
            map[depth][i] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    backtrack(0);
    std::cout << cnt << '\n';
}