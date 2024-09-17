#include <iostream>
#include <cmath>

int table[20][20];
int n;
int arr[20];
int min = 2147483647;
int sum_all = 0;
bool is_start[20];

void combination(int depth, int next)
{
    if (depth == n / 2)
    {
        int sum1 = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = i + 1; j < n / 2; ++j)
            {
                sum1 += table[arr[i]][arr[j]];
                sum1 += table[arr[j]][arr[i]];
            }
            is_start[arr[i]] = true;
        }
        int sum2 = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (!is_start[i] && !is_start[j])
                {
                    sum2 += table[i][j];
                    sum2 += table[j][i];
                }
            }
            is_start[i] = false;
        }
        int result = abs(sum2 - sum1);
        if (min > result)
        {
            min = result;
        }
        return;
    }

    for (int i = next; i < n; i++)
    {
        arr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> table[i][j];
            sum_all += table[i][j];
        }
    }
    combination(0, 0);
    std::cout << min << '\n';
}
