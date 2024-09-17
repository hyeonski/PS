#include <iostream>

struct node
{
    int left;
    int right;
};

struct node tree[26];

void preorder(int i)
{
    std::cout << static_cast<char>(i + 'A');
    if (tree[i].left != -1)
    {
        preorder(tree[i].left);
    }
    if (tree[i].right != -1)
    {
        preorder(tree[i].right);
    }
}
void inorder(int i)
{
    if (tree[i].left != -1)
    {
        inorder(tree[i].left);
    }
    std::cout << static_cast<char>(i + 'A');
    if (tree[i].right != -1)
    {
        inorder(tree[i].right);
    }
}
void postorder(int i)
{
    if (tree[i].left != -1)
    {
        postorder(tree[i].left);
    }
    if (tree[i].right != -1)
    {
        postorder(tree[i].right);
    }
    std::cout << static_cast<char>(i + 'A');
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    char tnode, tleft, tright;
    while (n--)
    {
        std::cin >> tnode >> tleft >> tright;
        if (tleft != '.')
        {
            tree[tnode - 'A'].left = tleft - 'A';
        }
        else
        {
            tree[tnode - 'A'].left = -1;
        }
        if (tright != '.')
        {
            tree[tnode - 'A'].right = tright - 'A';
        }
        else
        {
            tree[tnode - 'A'].right = -1;
        }
    }
    preorder(0);
    std::cout << '\n';
    inorder(0);
    std::cout << '\n';
    postorder(0);
    std::cout << '\n';
}