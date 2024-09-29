#include <iostream>
#include <vector>
#include <sstream>
#include <list>

struct setitem
{
    bool isin;
    std::list<int>::iterator insetit;
    std::list<int>::iterator outsetit;
};

struct setitem set[21];
std::list<int> inset;
std::list<int> outset;

std::vector<std::string> split(std::string s)
{
    std::istringstream iss(s);
    std::vector<std::string> result;
    std::string buf;

    while (std::getline(iss, buf, ' '))
    {
        result.push_back(buf);
    }
    return result;
}

void add(int x)
{
    if (!set[x].isin)
    {
        set[x].isin = true;
        outset.erase(set[x].outsetit);
        inset.push_front(x);
        set[x].insetit = inset.begin();
    }
}

void remove(int x)
{
    if (set[x].isin)
    {
        set[x].isin = false;
        inset.erase(set[x].insetit);
        outset.push_front(x);
        set[x].outsetit = outset.begin();
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 1; i <= 20; ++i)
    {
        outset.push_front(i);
        set[i].outsetit = outset.begin();
    }
    std::string op;
    int x;
    while (n--)
    {
        std::cin >> op;
        if (op == "add")
        {
            std::cin >> x;
            add(x);
        }
        if (op == "remove")
        {
            std::cin >> x;
            remove(x);
        }
        if (op == "check")
        {
            std::cin >> x;
            std::cout << set[x].isin << '\n';
        }
        if (op == "toggle")
        {
            std::cin >> x;
            if (set[x].isin)
            {
                remove(x);
            }
            else
            {
                add(x);
            }
        }
        if (op == "all")
        {
            auto it = outset.begin();
            auto last = it;
            while (it != outset.end())
            {
                last = it;
                ++it;
                add(*last);
            }
        }
        if (op == "empty")
        {
            auto it = inset.begin();
            auto last = it;
            while (it != inset.end())
            {
                last = it;
                ++it;
                remove(*last);
            }
        }
    }
}
