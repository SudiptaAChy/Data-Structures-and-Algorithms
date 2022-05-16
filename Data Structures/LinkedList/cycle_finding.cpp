/**
 * http://www.shafaetsplanet.com/planetcoding/?p=2822
 * https://www.codingninjas.com/blog/2020/09/09/floyds-cycle-detection-algorithm/
 * https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
 *
 * using floyd algorithm
 *
 * Time = O(n)
 * Space = O(1)
 */

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
    node(int d)
    {
        value = d;
        next = NULL;
    }
};
node *root = NULL;

bool isCycleFound()
{
    node *slow = root;
    node *fast = root;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

node *cycleMakingNode()
{
    node *slow = root;
    node *fast = root;
    bool cycle = false;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }
    if (!cycle)
        return NULL;
    else
    {
        slow = root;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}

int main()
{
    node *nodeOne = new node(1);
    node *nodeTwo = new node(2);
    node *nodeThree = new node(3);
    node *nodeFour = new node(4);
    node *nodeFive = new node(5);
    node *nodeSix = new node(6);
    node *nodeSeven = new node(7);
    node *nodeEight = new node(8);

    // Head node pointing to first node of linked list
    root = nodeOne;

    // creating a dependency in nodes by linking node to one another
    nodeOne->next = nodeTwo;
    nodeTwo->next = nodeThree;
    nodeThree->next = nodeFour;
    nodeFour->next = nodeFive;
    nodeFive->next = nodeSix;
    nodeSix->next = nodeSeven;
    nodeSeven->next = nodeEight;
    nodeEight->next = nodeThree; // create a cycle here

    if (isCycleFound())
    {
        cout << "Cycle starts from node " << cycleMakingNode()->value << endl;
    }
    else
    {
        cout << "No cycle found!\n";
    }
    return 0;
}
