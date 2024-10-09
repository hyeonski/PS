#include <iostream>
#include <algorithm>

int arr[8];
bool used[8];
int n, m;
int result[8];

void backtrack(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
        {
            std::cout << result[i] << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            result[depth] = arr[i];
            backtrack(depth + 1);
            used[i] = false;
        }
    }
}

int main()
{
    std::cin >> n >> m;
    int c;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c;
        arr[i] = c;
    }
    std::sort(arr, arr + n);
    backtrack(0);
}