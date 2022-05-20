/**
 * https://hellohasan.com/category/data-structure/tree/binary-search-tree-bst
 *
 * Time = O(logN)
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

bool search(int v) // O(logN)
{
    node *current = root;
    while (current != NULL)
    {
        if (v == current->value)
            return true;
        if (v < current->value)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

node *findMin(node *root)
{
    if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

node *delete_node(node *root, int val) // general case time O(h) worst case time O(n)
{
    if (root == NULL)
        return NULL;

    if (val < root->value)
        root->left = delete_node(root->left, val);
    else if (val > root->value)
        root->right = delete_node(root->right, val);
    else
    {
        if (root->left == NULL && root->right == NULL) // if node has no child
            root = NULL;
        else if (root->left == NULL) // if node has 1 child
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        else // if node has 2 child
        {
            node *temp = findMin(root);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
    }

    return root;
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

    cout << search(70) << endl;  // true
    cout << search(170) << endl; // false

    root = delete_node(root, 70);
    cout << search(70) << endl; // false
    return 0;
}
