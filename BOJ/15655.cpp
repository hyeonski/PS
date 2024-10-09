#include <iostream>
#include <algorithm>

int arr[8];
int n, m;
int result[8];

void backtrack(int depth, int last)
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
    for (int i = last + 1; i < n; ++i)
    {
        result[depth] = arr[i];
        backtrack(depth + 1, i);
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
    backtrack(0, -1);
}