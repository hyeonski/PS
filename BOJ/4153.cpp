#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int a, b, c, pa, pb, pc;
    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        pa = a * a;
        pb = b * b;
        pc = c * c;
        if (pa + pb == pc || pb + pc == pa || pc + pa == pb)
        {
            std::cout << "right\n";
        }
        else
        {
            std::cout << "wrong\n";
        }
    }
}
