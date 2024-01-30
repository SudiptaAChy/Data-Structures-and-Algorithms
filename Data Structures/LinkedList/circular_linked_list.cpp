#include<bits./stdc++.h>
using namespace std;
struct node
{
    int value;
    node* next;
    node(int v) {
        this->value = v;
        this->next = NULL;
    }
};
node* head = NULL, * tail = NULL;
void addNode(int v) {
    node* newNode = new node(v);
    if (head == NULL) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
    tail->next = head;
}
void deleteNode(int position) {
    node* current = head;
    node* prev = NULL;
    for (int p = 1;p < position;p++) {
        prev = current;
        current = current->next;
    }
    if (current == head) {
        node* temp = head;
        head = head->next;
        tail->next = head;
        delete(temp);
        return;
    }
    prev->next = current->next;
    if (current == tail) {
        tail = prev;
    }
    delete(current);
}
void print() {
    node* current = head;
    while (current->next != head) {
        cout << current->value << ", ";
        current = current->next;
    }
    cout << tail->value << endl;
}
void solve() {
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);

    print();

    cout << "After deleting\n";
    deleteNode(2);
    print();
}
int main() {
    freopen("out.txt", "w", stdout);
    solve();
    return 0;
}