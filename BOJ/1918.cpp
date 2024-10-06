#include <iostream>
#include <stack>
#include <vector>

struct node
{
    char c;
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *parent = nullptr;
};

void append(struct node **root, struct node *op, struct node *tree, struct node **last_term)
{
    if (*root == nullptr)
    {
        *root = tree;
        *last_term = tree;
    }
    else
    {
        if (op->c == '*' || op->c == '/')
        {
            struct node *parent = (*last_term)->parent;
            (*last_term)->parent = op;
            tree->parent = op;
            op->left = (*last_term);
            op->right = tree;
            op->parent = parent;
            if (parent != nullptr)
            {
                parent->right = op;
            }
            else
            {
                *root = op;
            }
            *last_term = op;
        }
        else
        {
            (*root)->parent = op;
            tree->parent = op;
            op->left = *root;
            op->right = tree;
            *root = op;
            *last_term = tree;
        }
    }
}

struct node *parse(std::string str)
{
    std::vector<std::string> chunks;
    struct node *root = nullptr;
    struct node *op = nullptr;
    struct node *last_term = nullptr;
    std::string::size_type i = 0;
    while (i < str.length())
    {
        if (str[i] == '(')
        {
            std::stack<std::string::size_type> stack;
            std::string::size_type j = i + 1;
            stack.push(i);
            while (j < str.length())
            {
                if (str[j] == '(')
                {
                    stack.push(j);
                }
                else if (str[j] == ')')
                {
                    stack.pop();
                }
                if (stack.empty())
                {
                    break;
                }
                ++j;
            }
            struct node *sub = parse(str.substr(i + 1, j - i - 1));
            append(&root, op, sub, &last_term);
            i = j;
        }
        else
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                op = new struct node({str[i]});
            }
            else
            {
                append(&root, op, new struct node({str[i]}), &last_term);
            }
        }
        ++i;
    }
    return root;
}

void postorder(struct node *tree)
{
    if (tree->left != nullptr)
    {
        postorder(tree->left);
    }
    if (tree->right != nullptr)
    {
        postorder(tree->right);
    }
    std::cout << tree->c;
    if (tree->left != nullptr)
    {
        delete tree->left;
        tree->left = nullptr;
    }
    if (tree->right != nullptr)
    {
        delete tree->right;
        tree->right = nullptr;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    std::cin >> input;
    struct node *tree = parse(input);
    postorder(tree);
    delete tree;
    tree = nullptr;
}
