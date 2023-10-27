#include <iostream>
#include <vector>

#include "LinkedList.h"

using namespace std;

// T.C = O(n+m)
// S.C = O(1)
Node *mergeTwoSortedLists(Node *l1, Node *l2) {
    Node *tmp = new Node();
    Node *curr = tmp;

    while (l1 && l2) {
        if (l1->getData() < l2->getData()) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1) {
        curr->next = l1;
    }

    if (l2) {
        curr->next = l2;
    }

    return tmp->next;
}


int main()
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 3, 4};

    Node *l1 = constructLL(v1);
    Node *l2 = constructLL(v2);

    Node *mergedList = mergeTwoSortedLists(l1, l2);
    printLinkedList(mergedList);

    return 0;
}