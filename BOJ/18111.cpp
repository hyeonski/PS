#include <iostream>

int map[500][500];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, b;
    std::cin >> n >> m >> b;
    int max = 0, min = 1024;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
            if (max < map[i][j])
            {
                max = map[i][j];
            }
            if (min > map[i][j])
            {
                min = map[i][j];
            }
        }
    }

    int nb, time;
    int mintime = (1 << 29), mheight;
    for (int h = max; h >= min; --h)
    {
        time = 0;
        nb = b;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] > h)
                {
                    nb += (map[i][j] - h);
                    time += ((map[i][j] - h) * 2);
                }
                else if (map[i][j] < h)
                {
                    nb -= (h - map[i][j]);
                    time += (h - map[i][j]);
                }
            }
        }
        if (nb >= 0 && mintime > time)
        {
            mintime = time;
            mheight = h;
        }
    }

    std::cout << mintime << ' ' << mheight << '\n';
}