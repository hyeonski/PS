#include <iostream>
#include <vector>

int min = 2147483647;
int max = -2147483648;

int n;
int a[11];
int op[4];
bool check[10];
char aop[10];
std::string opstr;

void permutation(int depth)
{
    if (depth == n-1)
    {
        int result = a[0];
        for (int i = 0; i < n-1; ++i)
        {
            switch (aop[i])
            {
            case '+':
                result += a[i+1];
                break;
            case '-':
                result -= a[i+1];
                break;
            case '*':
                result *= a[i+1];
                break;
            case '/':
                result /= a[i+1];
                break;
            default:
                break;
            }
        }
        if (max < result) {
            max = result;
        }
        if (min > result) {
            min = result;
        }
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            aop[depth] = opstr[i];
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    std::cin >> op[0];
    for (int i = 0; i < op[0]; ++i) {
        opstr += '+';
    }
    std::cin >> op[1];
    for (int i = 0; i < op[1]; ++i) {
        opstr += '-';
    }
    std::cin >> op[2];
    for (int i = 0; i < op[2]; ++i) {
        opstr += '*';
    }
    std::cin >> op[3];
    for (int i = 0; i < op[3]; ++i) {
        opstr += '/';
    }
    permutation(0);
    std::cout << max << '\n' << min << '\n';
}
