#include <iostream>
#include <queue>

int n;
bool paper[128][128];
int white, blue;

void search(int r, int c, int size)
{
    bool color = paper[r][c];
    bool success = true;
    for (int i = r; i < r + size; ++i)
    {
        for (int j = c; j < c + size; ++j)
        {
            if (color != paper[i][j])
            {
                success = false;
                break;
            }
        }
        if (!success)
        {
            break;
        }
    }
    if (success)
    {
        color == 0 ? ++white : ++blue;
    }
    else
    {
        int new_size = size / 2;
        search(r, c, new_size);
        search(r, c + new_size, new_size);
        search(r + new_size, c, new_size);
        search(r + new_size, c + new_size, new_size);
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
            std::cin >> paper[i][j];
        }
    }
    search(0, 0, n);
    std::cout << white << '\n';
    std::cout << blue << '\n';
}
