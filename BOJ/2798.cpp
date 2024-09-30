#include <iostream>

int n, m;
int cards[100];
int max;

void combination(int depth, int last, int sum)
{
    if (depth == 3)
    {
        if (sum <= m && max < sum)
        {
            max = sum;
        }
        return;
    }
    for (int i = last + 1; i < n; ++i)
    {
        combination(depth + 1, i, sum + cards[i]);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cards[i];
    }
    combination(0, -1, 0);
    std::cout << max << '\n';
}