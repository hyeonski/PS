#include <iostream>

int arr[1000001];
int size = 0;

int _log2(int n)
{
    int ret = 0;
    while (n > 1)
    {
        n /= 2;
        ++ret;
    }
    return ret;
}

int get_left_child_idx(int i)
{
    return i * 2;
}

int get_right_child_idx(int i)
{
    return i * 2 + 1;
}

int get_parent_idx(int i)
{
    return i / 2;
}

int get_grandparent_idx(int i)
{
    return i / 4;
}

void swap(int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int get_index_of_smallest_child_or_grandchild(int size, int i)
{
    int left_child_idx = get_left_child_idx(i);
    int right_child_idx = get_right_child_idx(i);
    int left_left_child_idx = get_left_child_idx(left_child_idx);
    int left_right_child_idx = get_right_child_idx(left_child_idx);
    int right_left_child_idx = get_left_child_idx(right_child_idx);
    int right_right_child_idx = get_right_child_idx(right_child_idx);
    int smallest_child_idx = left_child_idx;
    int smallest_grandchild_idx = left_left_child_idx;
    if (right_child_idx <= size && arr[right_child_idx] < arr[smallest_child_idx])
    {
        smallest_child_idx = right_child_idx;
    }
    if (left_right_child_idx <= size && arr[left_right_child_idx] < arr[smallest_grandchild_idx])
    {
        smallest_grandchild_idx = left_right_child_idx;
    }
    if (right_left_child_idx <= size && arr[right_left_child_idx] < arr[smallest_grandchild_idx])
    {
        smallest_grandchild_idx = right_left_child_idx;
    }
    if (right_right_child_idx <= size && arr[right_right_child_idx] < arr[smallest_grandchild_idx])
    {
        smallest_grandchild_idx = right_right_child_idx;
    }
    if (smallest_grandchild_idx > size || arr[smallest_child_idx] < arr[smallest_grandchild_idx])
    {
        return smallest_child_idx;
    }
    return smallest_grandchild_idx;
}

int get_index_of_largest_child_or_grandchild(int size, int i)
{
    int left_child_idx = get_left_child_idx(i);
    int right_child_idx = get_right_child_idx(i);
    int left_left_child_idx = get_left_child_idx(left_child_idx);
    int left_right_child_idx = get_right_child_idx(left_child_idx);
    int right_left_child_idx = get_left_child_idx(right_child_idx);
    int right_right_child_idx = get_right_child_idx(right_child_idx);
    int largest_child_idx = left_child_idx;
    int largest_grandchild_idx = left_left_child_idx;
    if (right_child_idx <= size && arr[right_child_idx] > arr[largest_child_idx])
    {
        largest_child_idx = right_child_idx;
    }
    if (left_right_child_idx <= size && arr[left_right_child_idx] > arr[largest_grandchild_idx])
    {
        largest_grandchild_idx = left_right_child_idx;
    }
    if (right_left_child_idx <= size && arr[right_left_child_idx] > arr[largest_grandchild_idx])
    {
        largest_grandchild_idx = right_left_child_idx;
    }
    if (right_right_child_idx <= size && arr[right_right_child_idx] > arr[largest_grandchild_idx])
    {
        largest_grandchild_idx = right_right_child_idx;
    }
    if (largest_grandchild_idx > size || arr[largest_child_idx] > arr[largest_grandchild_idx])
    {
        return largest_child_idx;
    }
    return largest_grandchild_idx;
}

void push_down(int size, int i);

void push_down_min(int size, int i)
{
    if (i * 2 <= size)
    {
        int m = get_index_of_smallest_child_or_grandchild(size, i);
        if (m / 4 == i)
        {
            if (arr[m] < arr[i])
            {
                swap(m, i);
                if (arr[m] > arr[get_parent_idx(m)])
                {
                    swap(m, get_parent_idx(m));
                }
                push_down(size, m);
            }
        }
        else if (arr[m] < arr[i])
        {
            swap(m, i);
        }
    }
}

void push_down_max(int size, int i)
{
    if (i * 2 <= size)
    {
        int m = get_index_of_largest_child_or_grandchild(size, i);
        if (m / 4 == i)
        {
            if (arr[m] > arr[i])
            {
                swap(m, i);
                if (arr[m] < arr[get_parent_idx(m)])
                {
                    swap(m, get_parent_idx(m));
                }
                push_down(size, m);
            }
        }
        else if (arr[m] > arr[i])
        {
            swap(m, i);
        }
    }
}

void push_down(int size, int i)
{
    if (_log2(i) % 2 == 0)
    {
        push_down_min(size, i);
    }
    else
    {
        push_down_max(size, i);
    }
}

void push_up_min(int size, int i)
{
    if (i / 4 > 0 && arr[i] < arr[i / 4])
    {
        swap(i, i / 4);
        push_up_min(size, i / 4);
    }
}

void push_up_max(int size, int i)
{
    if (i / 4 > 0 && arr[i] > arr[i / 4])
    {
        swap(i, i / 4);
        push_up_max(size, i / 4);
    }
}

void push_up(int size, int i)
{
    if (i != 1)
    {
        if (_log2(i) % 2 == 0)
        {
            if (arr[i] > arr[get_parent_idx(i)])
            {
                swap(i, get_parent_idx(i));
                push_up_max(size, get_parent_idx(i));
            }
            else
            {
                push_up_min(size, i);
            }
        }
        else
        {
            if (arr[i] < arr[get_parent_idx(i)])
            {
                swap(i, get_parent_idx(i));
                push_up_min(size, get_parent_idx(i));
            }
            else
            {
                push_up_max(size, i);
            }
        }
    }
}

void insert(int element)
{
    ++size;
    arr[size] = element;
    push_up(size, size);
}

void delete_min()
{
    if (size == 0)
    {
        return;
    }
    arr[1] = arr[size];
    --size;
    push_down(size, 1);
}

void delete_max()
{
    if (size == 0)
    {
        return;
    }
    if (size == 1 || size == 2)
    {
        --size;
        return;
    }
    if (arr[2] < arr[3])
    {
        arr[3] = arr[size];
        --size;
        push_down(size, 3);
        return;
    }
    arr[2] = arr[size];
    --size;
    push_down(size, 2);
}

int find_min()
{
    return arr[1];
}

int find_max()
{
    if (size == 1)
    {
        return arr[1];
    }
    if (size == 2)
    {
        return arr[2];
    }
    return arr[2] > arr[3] ? arr[2] : arr[3];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, k, n;
    char op;
    std::cin >> t;
    while (t--)
    {
        size = 0;
        std::cin >> k;
        while (k--)
        {
            std::cin >> op >> n;
            switch (op)
            {
            case 'I':
                insert(n);
                break;
            case 'D':
                if (n == 1)
                {
                    delete_max();
                }
                else
                {
                    delete_min();
                }
                break;
            default:
                break;
            }
        }
        if (size == 0)
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << find_max() << ' ' << find_min() << '\n';
        }
    }
}
