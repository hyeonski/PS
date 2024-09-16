#include <iostream>

bool board[50][50];

int check(int a, int b)
{
    int cnt[2];
    cnt[0] = 0; cnt[1] = 0;
    bool start = false;
    for (int k = 0; k < 2; ++k)
    {
        start = !start;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if ((i + j) % 2 == 1 && start == board[a + i][b + j])
                {
                    ++cnt[k];
                }
                else if ((i + j) % 2 == 0 && start != board[a + i][b + j])
                {
                    ++cnt[k];
                }
            }
        }

    }
    if (cnt[0] > cnt[1])
    {
        return cnt[1];
    }
    return cnt[0];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string buf;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf;
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = buf[j] == 'W' ? true : false;
        }
    }

    int min = 64, ret;
    for (int i = 0; i <= n - 8; ++i)
    {
        for (int j = 0; j <= m - 8; ++j)
        {
            ret = check(i, j);
            if (min > ret)
            {
                min = ret;
            }
        }
    }
    std::cout << min << '\n';
}
