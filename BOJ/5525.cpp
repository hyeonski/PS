#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    int cnt = 0;
    std::string::size_type i = 0, idx;
    int len;
    while ((idx = s.find('I', i)) != std::string::npos)
    {
        i = idx + 1;
        len = 0;
        while (s[i] == 'O' && s[i + 1] == 'I')
        {
            i += 2;
            len += 1;
        }
        if (len >= n)
        {
            cnt += ((len - n) + 1);
        }
    }
    std::cout << cnt << '\n';
}
