//                          Symmetric Tree
//  easy  - > compare then go left for tree1 and right for tree2 vice versa 

/*
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: 
True
Explanation: 
Tree is mirror image of itself i.e. tree is symmetric
Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: 
False
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
   bool check(Node* left, Node* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL || left->data != right->data)
            return false;
// go left for t1 right for t2 ......go right for t1 left for t2 
        return check(left->left, right->right) && check(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        if (root == NULL) 
            return true;
            //  splitting tree in half
        return check(root->left, root->right);
    }
};