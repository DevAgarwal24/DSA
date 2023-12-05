#include <iostream>
#include <vector>

#include "BinaryTree.h"

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, -1, -1, 7};
    
    Node *root = constructBinaryTree(v);
    
    levelOrderTraversal(root);  // 1 2 3 4 7
    
    preOrderTraversal(root);    // 1 2 4 3 7
    cout << endl;
    
    inOrderTraversal(root);     // 4 2 1 3 7
    cout << endl;
    
    postOrderTraversal(root);   // 4 2 7 3 1
    cout << endl;

	vector<int> boundary = traverseBoundary(root);
    for (auto i : boundary)     // 1 2 4 7 3
        cout << i << " ";
    cout << endl;
    
    return 0;   
}
