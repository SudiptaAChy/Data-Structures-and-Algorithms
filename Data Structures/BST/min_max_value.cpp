/**
 * https://hellohasan.com/2017/01/19/%e0%a6%9f%e0%a7%8d%e0%a6%b0%e0%a6%bf-binary-search-tree-find-maximum-minimum/
 *
 * Time = O(h) ; height of tree
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

node *findMin(node *root)
{
    if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

node *findMax(node *root)
{
    if (root->right == NULL)
        return root;
    else
        return findMin(root->right);
}

int main()
{
    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
    return 0;
}
