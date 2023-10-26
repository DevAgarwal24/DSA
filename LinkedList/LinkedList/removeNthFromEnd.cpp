// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://www.codingninjas.com/studio/problems/delete-kth-node-from-end_799912

#include <iostream>
#include <vector>

#include "LinkedList.h"

using namespace std;

// Approach 1
// Iterate over the linked list and find the total number of nodes in the list
// Nth node from the end will be equal to total nodes - n + 1 node from the front
// Reach to the one node previous to that node, and delete the desired node
// T.C = O(2N)
// S.C = O(1)
#if 0
Node* removeNthFromEnd(Node *head, int n) {
    int count = 0;

    Node *curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }

    if (n > count) {
        cout << "Node doesn't exist!\n";
        return head;
    }

    // Trying to delete the head (last node from the end)
    if (count == n) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    int prevCount = count - n - 1;
    curr = head;

    while (prevCount && curr) {
        curr = curr->next;
        prevCount--;
    }

    Node *tmp = curr->next;
    curr->next = curr->next->next;
    delete tmp;

    return head;
}
#endif

// Approach 2
// Deleting the node in a single iteration
// Have two pointers pointing at the start and let the first move to n places
// Then move the both the pointers together till the first pointer is null
// This way, the second pointer will reach to the node that needs to be deleted i.e. the
// nth node from the end
Node *removeNthFromEnd(Node *head, int n) {
    Node *start = new Node();
    start->next = head;
    Node *fast = start, *slow = start;

    for (int i = 1; i <= n; i++) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    Node *tmp = nullptr;

    if (slow->next == head) {
        tmp = head;
        head = head->next;
    } else {
        tmp = slow->next;
        slow->next = slow->next->next;
    }

    delete tmp;
    delete start;

    return head;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);

    head = removeNthFromEnd(head, 2);
    printLinkedList(head);

    head = removeNthFromEnd(head, 4);
    printLinkedList(head);

    // It's guranteed that the node to be removed will be in the linked list
    /// So, don't use this case
    // head = removeNthFromEnd(head, 4);
    // printLinkedList(head);

    head = deleteLinkedList(head);

    arr = {1};
    head = constructLL(arr);
    head = removeNthFromEnd(head, 1);
    printLinkedList(head);

    return 0;
}