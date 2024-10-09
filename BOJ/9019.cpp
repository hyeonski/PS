#include <iostream>
#include <queue>
#include <vector>

int fl(int a)
{
    if (a == 0)
    {
        return 0;
    }
    int b = a / 1000;
    a = (a * 10) % 10000;
    return a + b;
}

int fr(int a)
{
    if (a == 0)
    {
        return 0;
    }
    int b = a % 10;
    a = a / 10;
    return b * 1000 + a;
}

void solve(int a, int b)
{
    std::vector<bool> visited(10000, false);
    std::queue<std::pair<int, std::string>> q;
    q.push({a, std::string("")});
    visited[a] = true;
    int c, d, s, l, r;
    std::string res;
    while (true)
    {
        c = q.front().first;
        res = q.front().second;
        q.pop();
        if (c == b)
        {
            std::cout << res << '\n';
            break;
        }
        d = (c * 2) % 10000;
        s = (c == 0) ? 9999 : c - 1;
        l = fl(c);
        r = fr(c);
        if (!visited[d])
        {
            q.push({d, res + 'D'});
            visited[d] = true;
        }
        if (!visited[s])
        {
            q.push({s, res + 'S'});
            visited[s] = true;
        }
        if (!visited[l])
        {
            q.push({l, res + 'L'});
            visited[l] = true;
        }
        if (!visited[r])
        {
            q.push({r, res + 'R'});
            visited[r] = true;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    int a, b;
    while (t--)
    {
        std::cin >> a >> b;
        solve(a, b);
    }
}