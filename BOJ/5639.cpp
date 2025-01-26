#include <iostream>

struct node
{
    int key;
    struct node *left = nullptr;
    struct node *right = nullptr;
};

void insert(struct node *root, int key)
{
    while (true)
    {
        if (key > root->key)
        {
            if (root->right == nullptr)
            {
                root->right = new struct node({key, nullptr, nullptr});
                break;
            }
            else
            {
                root = root->right;
            }
        }
        else
        {
            if (root->left == nullptr)
            {
                root->left = new struct node({key, nullptr, nullptr});
                break;
            }
            else
            {
                root = root->left;
            }
        }
    }
}

void postorder(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->key << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string buf;
    std::getline(std::cin, buf);
    struct node *root = new struct node();
    root->key = std::stoi(buf);
    while (std::getline(std::cin, buf))
    {
        insert(root, std::stoi(buf));
    }

    postorder(root);
}