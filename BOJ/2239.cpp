#include <iostream>
#include <list>

int board[9][9];
std::list<std::pair<int, int>> lst;
bool flag = false;

bool isvalid(int a, int b)
{
    int key = board[a][b];
    for (int i = 0; i < 9; ++i)
    {
        if (a != i && key == board[i][b])
        {
            return false;
        }
        if (b != i && key == board[a][i])
        {
            return false;
        }
    }
    int r = (a / 3) * 3, c = (b / 3) * 3;
    for (int i = r; i < r + 3; ++i)
    {
        for (int j = c; j < c + 3; ++j)
        {
            if (a != i && b != j && key == board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void backtrack(std::list<std::pair<int, int>>::const_iterator it)
{
    if (flag == true)
    {
        return;
    }
    if (it == lst.end())
    {
        flag = true;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                std::cout << board[i][j];
            }
            std::cout << '\n';
        }
        return;
    }
    for (int t = 1; t <= 9; ++t)
    {
        board[it->first][it->second] = t;
        if (isvalid(it->first, it->second))
        {
            ++it;
            backtrack(it);
            --it;
        }
        board[it->first][it->second] = 0;
    }
}

int main()
{
    std::string buf;
    for (int i = 0; i < 9; ++i)
    {
        std::getline(std::cin, buf);
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = buf[j] - '0';
            if (board[i][j] == 0)
            {
                lst.push_back({i, j});
            }
        }
    }
    backtrack(lst.begin());
}
