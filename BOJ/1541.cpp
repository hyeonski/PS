#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;
    bool isopen = false;
    for (auto &x : input)
    {
        if (!std::isdigit(x))
        {
            if (x == '-')
            {
                isopen = true;
            }
            else
            {
                if (isopen)
                {
                    x = '-';
                }
            }
        }
    }

    std::string buf = "";
    long long int tmp;
    long long int result = 0;
    bool isminus = false;
    for (auto &x : input)
    {
        if (std::isdigit(x))
        {
            buf += x;
        }
        else
        {
            tmp = std::stoi(buf);
            result += (isminus ? -tmp : tmp);
            buf = "";
            isminus = (x == '-');
        }
    }
    tmp = std::stoi(buf);
    result += (isminus ? -tmp : tmp);
    std::cout << result << '\n';
}
