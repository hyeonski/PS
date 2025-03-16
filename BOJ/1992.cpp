#include <iostream>
#include <string>

int map[64][64];

std::string make_tree(int n, int x, int y)
{
    int mark = map[x][y];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[x + i][y + j] != mark)
            {
                mark = -1;
                break;
            }
        }
        if (mark == -1)
        {
            break;
        }
    }
    if (mark == -1)
    {
        std::string ret = "(";
        int sub = n / 2;
        ret += make_tree(sub, x, y);
        ret += make_tree(sub, x, y + sub);
        ret += make_tree(sub, x + sub, y);
        ret += make_tree(sub, x + sub, y + sub);
        return ret + ")";
    }
    return std::to_string(mark);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::string buf;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf;
        for (int j = 0; j < n; ++j)
        {
            map[i][j] = buf[j] - '0';
        }
    }
    std::cout << make_tree(n, 0, 0) << '\n';
}
