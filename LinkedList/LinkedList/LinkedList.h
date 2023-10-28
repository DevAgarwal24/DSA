#include <iostream>

using namespace std;

// Definition of Linked List Node
class Node {
public:
	Node() : data{0}, next{nullptr} {}
	Node(int x) : data{x}, next{nullptr} {}
	Node(int x, Node* next) : data{x}, next{next} {}

    int data;
	Node* next;
};

// Printing the linked list
void printLinkedList(Node* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

// Create Linked List from the array
Node* constructLL(vector<int> &arr) {
    Node* head = nullptr;
    Node* prev = nullptr;

    for (int i = 0; i < arr.size(); i++) {
        Node* tmp = new Node(arr[i]);

        if (head == nullptr) {
            head = tmp;
            prev = tmp;
        } else {
            prev->next = tmp;
            prev = tmp;
        }
    }

    return head;
}

Node *deleteLinkedList(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    return nullptr;
}
