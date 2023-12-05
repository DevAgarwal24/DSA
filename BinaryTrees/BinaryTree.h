#include <iostream>
#include <queue>
#include <stack>

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

vector<int> preOrderTraversalIterative(Node *root){
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node *node = s.top();
        s.pop();

        ans.push_back(node->data);
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }

    return ans;
}

vector<int> inOrderTraversalIterative(Node *root)
{
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> s;
    Node *node = root;

    while (true) {
        if (node != NULL) {
            s.push(node);
            node = node->left;
        } else {
            if (s.empty()) break;
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }

    return ans;
}

// Post order traversal using two stack
vector<int> postorderTraversalIterative(Node *root)
{
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node *node = s1.top();
        s1.pop();

        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    
    return ans;
}

// Post order traversal using one stack
vector<int> postorderTraversalIterativeII(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> s;
    Node* curr = root;

    while (curr || !s.empty()) {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            Node *tmp = s.top()->right;
            if (tmp == NULL) {
                tmp = s.top();
                s.pop();
                ans.push_back(tmp->data);
                while (!s.empty() && tmp == s.top()->right) {
                    tmp = s.top();
                    s.pop();
                    ans.push_back(tmp->data);
                }
            } else {
                curr =tmp;
            }
        }
    }

    return ans;
}

// Boundary Traversal
void leftTraversal(Node *root, vector<int> &ans) {
	if (root == nullptr) return;
	if (root->left == nullptr && root->right == nullptr) return;

	ans.push_back(root->data);
	if (root->left) {
		leftTraversal(root->left, ans);
	} else if (root->right) {
		leftTraversal(root->right, ans);
	}
}

void leafTraversal(Node *root, vector<int> &ans) {
	if (root == nullptr) return;

	if (root->left == nullptr && root->right == nullptr) ans.push_back(root->data);
	leafTraversal(root->left, ans);
	leafTraversal(root->right, ans);
}

void rightTraversal(Node *root, vector<int> &ans) {
	if (root == nullptr) return;
	if (root->left == nullptr && root->right == nullptr) return;

	if (root->right) {
		rightTraversal(root->right, ans);
	} else if (root->left) {
		rightTraversal(root->left, ans);
	}

	ans.push_back(root->data);
}

vector<int> traverseBoundary(Node *root)
{
	vector<int> ans;
	if (root == nullptr) return ans;
	
	ans.push_back(root->data);
	leftTraversal(root->left, ans);
	leafTraversal(root, ans);
	rightTraversal(root->right, ans);

	return ans;
}
