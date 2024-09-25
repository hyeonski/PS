#include <iostream>

int n, m;
int a[7];
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
    for (int i = 1; i <= n; ++i)
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