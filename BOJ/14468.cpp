#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    std::cin >> input;
    std::vector<std::pair<int, int>> pos(26, {-1, -1});
    for (int i = 0; i < 52; ++i)
    {
        std::pair<int, int> &p = pos[input[i] - 'A'];
        if (p.first == -1)
        {
            p.first = i;
        }
        else
        {
            p.second = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        for (int j = i + 1; j < 26; ++j)
        {
            if (pos[i].first < pos[j].first && pos[j].second < pos[i].second)
            {
            }
            else if (pos[j].first < pos[i].first && pos[i].second < pos[j].second)
            {
            }
            else if (pos[i].second < pos[j].first)
            {
            }
            else if (pos[j].second < pos[i].first)
            {
            }
            else
            {
                ++cnt;
            }
        }
    }
    std::cout << cnt << '\n';
}
