#include <iostream>
#include <vector>

std::vector<int> v;
std::vector<bool> check;
int n, m;

void permutation(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
        {
            std::cout << v[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            v[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    v.resize(m, 0);
    check.resize(n + 1, false);
    permutation(0);
}
