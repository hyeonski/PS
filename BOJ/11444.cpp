#include <iostream>
#include <map>

#define MOD 1000000007

typedef unsigned long long int ull;

std::map<ull, ull> m;

ull fibo(ull n)
{
    if (m[n])
    {
        return m[n];
    }

    ull result;
    if (n % 2 == 0)
    {
        result = (fibo(n / 2) * (fibo(n / 2 + 1) + fibo(n / 2 - 1))) % MOD;
    }
    else
    {
        result = ((fibo((n + 1) / 2) * fibo((n + 1) / 2)) % MOD) + ((fibo((n - 1) / 2) * fibo((n - 1) / 2)) % MOD) % MOD;
    }

    return m[n] = result % MOD;
}

int main()
{
    ull n;
    std::cin >> n;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    std::cout << fibo(n);
}
