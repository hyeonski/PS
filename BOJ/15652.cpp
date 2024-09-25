#include <iostream>

int n, m;
int a[8];
void backtrack(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
        {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i = depth == 0 ? 1 : a[depth - 1]; i <= n; ++i)
    {
        a[depth] = i;
        backtrack(depth + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    backtrack(0);
}
