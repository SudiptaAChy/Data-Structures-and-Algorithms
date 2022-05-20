/**
 * https://hellohasan.com/category/data-structure/tree/binary-search-tree-bst
 *
 * Time = O(N)
 * As DFS is O(V+E). In binary tree max node can be 2. Max number of total edges in a Binary Tree is n-1.
 * The complexity then becomes O(n + n-1) ~ O(n)
 */

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *left, *right;
    node(int d)
    {
        value = d;
        left = NULL;
        right = NULL;
    }
};
node *root = NULL;

void insert(int v) // O(logN)
{
    if (root == NULL)
    {
        root = new node(v);
    }
    else
    {
        node *current = root;
        node *parent = NULL;
        while (true)
        {
            parent = current;
            if (v <= current->value)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = new node(v);
                    break;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = new node(v);
                    break;
                }
            }
        }
    }
}

void PreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->value << " ";
    InOrder(root->right);
}

void PostOrder(node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->value << " ";
}

int main()
{
    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    PreOrder(root); // 50 30 20 40 70 60 80
    cout << endl;

    InOrder(root); // 20 30 40 50 60 70 80
    cout << endl;

    PostOrder(root); // 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}
