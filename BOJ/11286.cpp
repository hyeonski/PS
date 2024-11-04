#include <iostream>
#include <cmath>

int heap[100001];
int size = 0;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

bool lt(int a, int b)
{
    if (abs(a) == abs(b))
    {
        return a < b;
    }
    return abs(a) < abs(b);
}

bool gt(int a, int b)
{
    if (abs(a) == abs(b))
    {
        return a > b;
    }
    return abs(a) > abs(b);
}

void enqueue(int e)
{
    ++size;
    heap[size] = e;
    int i = size;
    while (i > 1)
    {
        if (lt(heap[i], heap[i / 2]))
        {
            swap(heap + i, heap + (i / 2));
            i = i / 2;
        }
        else
        {
            break;
        }
    }
}

int dequeue()
{
    if (size == 0)
    {
        return 0;
    }
    int ret = heap[1];
    heap[1] = heap[size];
    --size;
    int i = 1;
    while (i * 2 <= size)
    {
        if (gt(heap[i], heap[i * 2]))
        {
            if (gt(heap[i * 2], heap[i * 2 + 1]))
            {
                swap(heap + i, heap + (i * 2 + 1));
                i = (i * 2) + 1;
            }
            else
            {
                swap(heap + i, heap + (i * 2));
                i = i * 2;
            }
        }
        else if (gt(heap[i], heap[i * 2 + 1]))
        {
            swap(heap + i, heap + (i * 2 + 1));
            i = (i * 2) + 1;
        }
        else
        {
            break;
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int in;
    while (n--)
    {
        std::cin >> in;
        if (in == 0)
        {
            std::cout << dequeue() << '\n';
        }
        else
        {
            enqueue(in);
        }
    }
}
