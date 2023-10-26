// https://leetcode.com/problems/reverse-linked-list/
// https://www.codingninjas.com/studio/problems/reverse-linked-list_920513

#include <iostream>
#include <vector>

#include "LinkedList.h"

// Iterative
#if 0
Node *reverseList(Node *head) {
    Node *newHead = nullptr;

    while (head) {
        Node *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }

    return newHead;
}
#endif

// Recursive
Node *reverseListHelper(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *rest = reverseListHelper(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rest;
}

Node *reverseList(Node *head) {
    return reverseListHelper(head);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);

    head = reverseList(head);
    printLinkedList(head);

    head = deleteLinkedList(head);

    arr = {1};
    head = constructLL(arr);
    head = reverseList(head);
    printLinkedList(head);

    head = deleteLinkedList(head);

    return 0;
}