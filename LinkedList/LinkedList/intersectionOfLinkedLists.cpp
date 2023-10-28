// https://leetcode.com/problems/intersection-of-two-linked-lists
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "LinkedList.h"

using namespace std;

// Brute Force
// This will be a nested loop where we keep one pointer fix and then iterate over the other
// linked list to check if that pointer matches the fixed pointer
// T.C = O(n*m)
// S.C = O(1)
#if 0
Node *getIntersectionNode(Node *headA, Node *headB) {
    while(headA) {
        Node *tmp = headB;
        while(tmp) {
            if (tmp == headA) return headA;
            tmp = tmp->next;
        }
        headA = headA->next;
    }

    return nullptr;
}
#endif

// Better Solution
// We'll be using hashing. But, instead of hashing on the value, we'll hash on the address of the nodes
// Iterate the first linked list and hash all the node addresses
// Iterate the other linked list and check if the address is available in the hash map
// T.C = O(n+m)
// S.C = O(n)
#if 0
Node *getIntersectionNode(Node *headA, Node *headB) {
    unordered_map<Node*, int> m;

    while(headA) {
        m.insert({headA, 1});
        headA = headA->next;
    }

    while(headB) {
        if (m.find(headB) != m.end()) {
            return headB;
        }
        headB = headB->next;
    }

    return nullptr;
}
#endif

// Optimal Solution I
// Iterate over the nodes and find their lengths
// Check the list with more number of nodes and then iterate it's head by the difference of the
// size of the two linked list
// Start iterating both the heads till a common node is reached
// T.C = O(max(n,m)) + O(max(n,m))
// S.C = O(1)
#if 0
Node *getIntersectionNode(Node *headA, Node *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    int countA = 0;
    int countB = 0;

    Node *tmpA = headA;
    Node *tmpB = headB;

    while (tmpA || tmpB) {
        if (tmpA) {
            countA++;
            tmpA = tmpA->next;
        }

        if (tmpB) {
            countB++;
            tmpB = tmpB->next;
        }
    }

    tmpA = headA;
    tmpB = headB;

    if (countA >= countB) {
        for (int i = 1; i <= countA-countB; i++) {
            tmpA = tmpA->next;
        }
    } else {
        for (int i = 1; i <= countB-countA; i++) {
            tmpB = tmpB->next;
        }
    }

    while (tmpA && tmpB) {
        if (tmpA == tmpB) {
            return tmpA;
        }

        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }

    return nullptr;
}
#endif

// Optimal Solution II
// Iterating the lists twice
// Keep two dummy nodes at the head of the each list and keep iterating till one of the node pointer reaches null
// Move the node pointer that reached null to the head of the other list and continue till iterating over the
// list till the other pointer reaches null.
// Now move this pointer to the other list's head
//
// When we switched a pointer from one list to the other once it reached the end, the other pointer had the
// difference of the two lists to be moved infront of it. When that pointer reaches the end and we put it
// on the other list, we have basically travelled same number of nodes with both the pointers
Node *getIntersectionNode(Node *headA, Node *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    Node *tmpA = headA;
    Node *tmpB = headB;

    for (int i = 0; i < 2; i++) {
        while (tmpA && tmpB) {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        if (tmpA == nullptr) {
            tmpA = headB;
        }

        if (tmpB == nullptr) {
            tmpB = headA;
        }
    }

    while (tmpA && tmpB) {
        if (tmpA == tmpB) {
            return tmpA;
        }

        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }

    return nullptr;
}


int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 1};

    Node *headA = constructLL(v1);
    Node *headB = constructLL(v2);

    Node *ans = getIntersectionNode(headA, headB);

    if (ans) cout << ans->data << endl;
    else cout << "No common node!\n";

    vector<int> v3 = {9, 8, 3};

    Node* head = constructLL(v3);
    
    Node* tmpA = headA;
    Node* tmpB = headB;

    while(tmpA->next) tmpA = tmpA->next;
    while(tmpB->next) tmpB = tmpB->next;

    tmpA->next = head;
    tmpB->next = head;

    ans = getIntersectionNode(headA, headB);

    if (ans) cout << ans->data << endl;
    else cout << "No common node!\n";

    return 0;
}