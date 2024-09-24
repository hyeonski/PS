#include <iostream>
#include <list>

std::list<int>::iterator next(std::list<int> &l, std::list<int>::iterator &it)
{

    std::list<int>::iterator past = it;
    ++it;
    if (it == l.end())
    {
        it = l.begin();
    }
    return past;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::list<int> in;
    std::list<int> out;
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        in.push_back(i);
    }
    std::list<int>::iterator it = in.begin();
    std::list<int>::iterator del;

    while (n)
    {
        for (int i = 0; i < k-1; ++i)
        {
            next(in, it);
        }
        del = next(in, it);
        out.push_back(*del);
        in.erase(del);
        --n;
    }

    std::cout << '<';
    auto it2 = out.begin();
    for (; it2 != --out.end(); ++it2)
    {
        std::cout << *it2 << ", ";
    }
    std::cout << *it2 << ">\n";
}
