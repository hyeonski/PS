#include <iostream>

typedef unsigned long long int ull;

int main()
{
    ull n; std::cin >> n;
    ull arr[5];
    arr[0] = 0;
    arr[1] = 1;
    for (ull i = 2; i <= n; ++i)
    {
        arr[i % 3] = (arr[(i-1) % 3] + arr[(i-2) % 3]) % 1000000007;
    }
    std::cout << arr[n % 3] << '\n';
}
