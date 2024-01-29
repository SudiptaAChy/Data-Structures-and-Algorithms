/**
 * http://www.shafaetsplanet.com/planetcoding/?p=2689
 * https://www.geeksforgeeks.org/reverse-a-linked-list/
 *
 * diff between array and linked list is memory sequence
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
    node(int v) {
        this->val = v;
        this->next = NULL;
    }
};
node* root;
void addNode(int v) {
    if (root == NULL) {
        root = new node(v);
        return;
    }
    node* curr = root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new node(v);
}
void insertNode(int pos, int v) {
    node* curr = root;
    node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        if (curr == NULL) {
            cout << "Invalid position\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    node* newNode = new node(v);
    if (curr == root) {
        newNode->next = root;
        root = newNode;
        return;
    }
    newNode->next = curr;
    prev->next = newNode;
}
void print() {
    node* curr = root;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
void deleteNode(int pos) {
    node* curr = root;
    node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == root) {
        root = root->next;
        return;
    }
    prev->next = curr->next;
}
void reverseList() {
    node* curr = root;
    node* prev = NULL, * next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    root = prev;
}
void printFromLast(int pos) {
    node* slow = root, * fast = root;
    for (int i = 1;i < pos;i++) {
        fast = fast->next;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    cout << "from last " << pos << " node = " << slow->val << endl;
}
node* cycleDetectingNode() {
    node* slow = root, * fast = root;
    bool cycle = false;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycle = true;
            break;
        }
    }

    if (!cycle) return NULL;

    slow = root;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
node* middleNode() {
    node* slow = root, * fast = root;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(10);
    addNode(4);

    print();

    insertNode(4, 9);
    print();

    // deleteNode(4);
    // print();

    // reverseList();
    // print();
    printFromLast(5);

    cout << "middle node " << middleNode()->val << endl;

    /* cycle finding */
    // root = new node(1);
    // node* n1 = new node(2);
    // node* n2 = new node(3);
    // node* n3 = new node(4);
    // node* n4 = new node(5);
    // node* n5 = new node(6);
    // node* n6 = new node(7);
    // node* n7 = new node(8);

    // root->next = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    // n6->next = n7;
    // n7->next = root;

    // node* cycle = cycleDetectingNode();
    // if (cycle == NULL) cout << "No cycle found\n";
    // else cout << cycle->val << " node creating cycle";
    /* cycle finding end */

    return 0;
}
