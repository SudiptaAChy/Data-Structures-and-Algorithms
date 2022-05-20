/**
 * https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
 *
 * Time = O(n)
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

int findDepth(node *root)
{
    if (root == NULL)
        return -1;
    return max(findDepth(root->left), findDepth(root->right)) + 1;
}
