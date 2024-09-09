#include <iostream>
#include <vector>

std::vector<int> v;
int n, m;

void combination(int depth, int next)
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

    for (int i = next; i <= n; i++)
    {

        v[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    v.resize(m, 0);
    combination(0, 1);
}
