/**
 * http://www.shafaetsplanet.com/planetcoding/?p=2689
 * diff between array and linked list is memory sequence
 */

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
    node() {}
    node(int d)
    {
        value = d;
        next = NULL;
    }
};
node *root = NULL;

void append(int v) // O(n)
{
    if (root == NULL)
    {
        root = new node(v);
    }
    else
    {
        node *current = root;
        while (current->next != NULL)
            current = current->next;
        node *newnode = new node(v);
        current->next = newnode;
    }
}

void print() // O(n)
{
    node *current = root;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void delete_node(int v) // O(n)
{
    node *current = root;
    node *previous = NULL;
    while (current->value != v)
    {
        previous = current;
        current = current->next;
    }
    if (current == root)
    {
        node *temp = root;
        root = root->next;
        delete (temp);
    }
    else
    {
        previous->next = current->next;
        delete (current);
    }
}

void edit_node(int pre_val, int new_val) // O(n)
{
    node *current = root;
    while (current->value != pre_val)
        current = current->next;
    current->value = new_val;
}

int main()
{
    append(1);
    append(2);
    append(5);
    append(4);
    append(3);

    print();

    delete_node(5);
    print();

    edit_node(4, 10);
    print();

    return 0;
}
