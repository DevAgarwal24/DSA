// https://leetcode.com/problems/add-two-numbers/description/
// https://www.codingninjas.com/studio/problems/add-two-numbers_1170520

#include <iostream>
#include <vector>

#include "LinkedList.h"

using namespace std;

// There is just the optimal solution here
// Don't just go for the solution directly, ask about edge cases and not jump to the solution directly

// Modifying the exisiting list
#if 0
Node *addTwoNumbers(Node *num1, Node *num2)
{
    if (!num1) return num2;
    if (!num2) return num1;

    Node *res = num2;
    int carry = 0;
    Node *prev = nullptr;

    while (num1 && num2) {
        int sum = num1->data + num2->data + carry;

        carry = sum / 10;

        num2->data = sum % 10;
        prev = num2;

        num1 = num1->next;
        num2 = num2->next;
    }

    if (!num1 && !num2 && carry) {
        prev->next = new Node(1);
        return res;
    }

    // swap the pointers so that we always work with num2
    if (num1) {
        swap(num1, num2);
        prev->next = num2;
    }

    while (num2 && carry) {
        int sum = num2->data + 1;
        
        carry = sum / 10;
        num2->data = sum % 10;

        prev = num2;
        num2 = num2->next;
    }

    if (carry) {
        prev->next = new Node(1);
    }

    return res;
}
#endif

// Creating a new list
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *res = new Node();
    Node *curr = res;

    int carry = 0;

    while (num1 && num2) {
        int sum = num1->data + num2->data + carry;

        carry = sum / 10;
        Node *tmp = new Node(sum % 10);

        curr->next = tmp;
        curr = tmp;

        num1 = num1->next;
        num2 = num2->next;
    }

    if (num2) {
        swap(num1, num2); 
    }

    while (num1) {
        int sum = num1->data + carry;

        carry = sum / 10;
        Node *tmp = new Node(sum % 10);

        curr->next = tmp;
        curr = tmp;

        num1 = num1->next;
    }

    if (carry) {
        curr->next = new Node(1);
    }

    return res->next;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 2, 6};

    Node *num1 = constructLL(v1);
    Node *num2 = constructLL(v2);

    Node *result = nullptr;

    result = addTwoNumbers(num1, num2);
    printLinkedList(result);      // 4 4 9 4 5

    v1.clear();
    v2.clear();

    num1 = deleteLinkedList(num1);
    num2 = deleteLinkedList(num2);

    v1 = {9, 9, 9, 9};
    v2 = v1;

    num1 = constructLL(v1);
    num2 = constructLL(v2);

    result = addTwoNumbers(num1, num2);
    printLinkedList(result);      // 8 9 9 9 1

    num1 = deleteLinkedList(num1);
    num2 = deleteLinkedList(num2);

    return 0;
}