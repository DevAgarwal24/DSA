#include <iostream>
#include <vector>

#include "LinkedList.h"

using namespace std;

// T.C = O(n+m)
// S.C = O(1)
#if 0
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
#endif

// Another code for T.C = (n+m)
// In this solution, the first node of list1 will always be having the value less
// than the first node of list2
Node *mergeTwoSortedLists(Node *l1, Node *l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->getData() > l2->getData()) swap(l1, l2);

    Node *res = l1;

    while (l1 && l2) {
        // This will point to the node previous to the node pointed by l1
        Node *tmp = nullptr;
        while (l1 && l1->getData() <= l2->getData()) {
            tmp = l1;
            l1 = l1->next;
        }

        tmp->next = l2;
        
        // swap l1 and l2 again so that l1 points to the node with smaller value
        swap(l1, l2);
    }

    return res;
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