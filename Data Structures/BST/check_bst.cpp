/**
 * https://hellohasan.com/2017/02/01/is-it-binary-search-tree-or-not/
 */

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node* left, * right;
    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};
node* root = NULL;

bool checkBst1(node* root, int mn = INT_MIN, int mx = INT_MAX) {
    if (root == NULL) return true;

    if (root->val <= mn || root->val >= mx) return false;

    return checkBst1(root->left, mn, root->val) & checkBst1(root->right, root->val, mx);
}

bool checkBst2(node* root, int prev = INT_MIN) {
    if (root == NULL) return true;

    if (!checkBst2(root->left, prev)) return false;

    if (root->val <= prev) return false;

    if (!checkBst2(root->right, root->val)) return false;

    return true;
}

int main()
{
    return 0;
}