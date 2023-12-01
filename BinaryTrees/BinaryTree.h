#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	Node() = delete;
	Node(int x) : data{x}, left{nullptr}, right{nullptr} {}
	Node(int x, Node* left, Node* right) : data{x}, left{left}, right{right} {}

    int data;
	Node *left, *right;
};

Node* constructBinaryTree(vector<int> &arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return nullptr;
    
    Node *node = new Node(arr[i]);
    node->left = constructBinaryTree(arr, 2*i+1);
    node->right = constructBinaryTree(arr, 2*i+2);
    
    return node;
}

Node* constructBinaryTree(vector<int> &arr) {
    Node *root = constructBinaryTree(arr, 0);
    return root;
}

void levelOrderTraversal(Node *root) {
    queue<Node *> q;
    
    q.push(root);
    
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    
    cout << endl;
}

void inOrderTraversal(Node *root) {
    if (root == nullptr) return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == nullptr) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
