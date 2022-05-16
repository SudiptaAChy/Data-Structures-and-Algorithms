/**
 * https://hellohasan.com/2017/05/13/doubly-linked-list-insert-print/
 * https://hellohasan.com/2017/06/12/doubly-linked-list-delete-item-from-head-tail-and-middle/
 */

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
    node *previous;
    node(int d)
    {
        value = d;
        next = NULL;
        previous = NULL;
    }
};
node *head = NULL, *tail = NULL;

void insert_at_tail(int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->previous = tail;
        tail = newnode;
    }
}

void insert_at_head(int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->previous = newnode;
        head = newnode;
    }
}

void insert_at_middle(int val, int position)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        node *temp = head;
        for (int pos = 1; pos < position - 1 && temp != NULL; pos++)
            temp = temp->next;
        node *nextnode = temp->next;
        temp->next = newnode;
        newnode->previous = temp;
        newnode->next = nextnode;
    }
}

void delete_node(int position)
{
    if (head == NULL)
        return;
    if (position == 1)
    {
        head = head->next;

        if (head->next == NULL)
            tail = NULL;
        else
            head->next->previous = NULL;
    }
    else
    {
        node *temp = head;
        int pos = 1;
        while ((pos < position) && temp->next != NULL)
        {
            temp = temp->next;
            pos++;
        }
        if (pos == position)
        {
            node *tempAnother = temp->previous;
            tempAnother->next = temp->next;

            if (temp->next == NULL)
                tail = tempAnother;
            else
                temp->next->previous = tempAnother;
            delete (temp);
        }
        else
            cout << "Desired position can't be found!";
    }
}

void print()
{
    node *current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    insert_at_tail(1);
    insert_at_tail(2);
    insert_at_tail(3);
    insert_at_tail(4);
    insert_at_tail(5);
    insert_at_tail(6);
    insert_at_tail(7);

    print();

    insert_at_middle(100, 5);

    print();

    delete_node(5);
    print();
    return 0;
}
