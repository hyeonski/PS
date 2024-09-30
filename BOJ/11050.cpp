#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int result = 1;
    for (int i = 0; i < k; ++i)
    {
        result *= (n - i);
    }
    for (int i = 1; i <= k; ++i)
    {
        result /= i;
    }
    std::cout << result << '\n';
}