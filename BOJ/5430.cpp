#include <iostream>
#include <list>

bool run(std::string func, int n, std::string arrstr)
{
    std::list<int> arr;
    int x = 0;
    for (std::string::size_type i = 1; i < arrstr.size() - 1; ++i)
    {
        if (arrstr[i] == ',')
        {
            arr.push_back(x);
            x = 0;
        }
        else
        {
            x *= 10;
            x += (arrstr[i] - '0');
        }
    }
    if (static_cast<std::list<int>::size_type>(n) != arr.size())
    {
        arr.push_back(x);
    }
    bool isforward = true;
    for (auto &x : func)
    {
        if (x == 'R')
        {
            isforward = !isforward;
        }
        else if (x == 'D')
        {
            if (arr.empty())
            {
                std::cout << "error\n";
                return false;
            }
            isforward ? arr.erase(arr.begin()) : arr.erase(--arr.end());
        }
    }
    std::cout << '[';
    if (isforward)
    {
        auto it = arr.begin();
        for (std::list<int>::size_type i = 0; i < arr.size(); ++i)
        {
            std::cout << *it;
            if (i != arr.size() - 1)
            {
                std::cout << ',';
            }
            ++it;
        }
        std::cout << "]\n";
    }
    else
    {
        auto it = --arr.end();
        for (std::list<int>::size_type i = 0; i < arr.size(); ++i)
        {
            std::cout << *it;
            if (i != arr.size() - 1)
            {
                std::cout << ',';
            }
            --it;
        }
        std::cout << "]\n";
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    std::string func;
    int n;
    std::string arrstr;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> func >> n >> arrstr;
        run(func, n, arrstr);
    }
}