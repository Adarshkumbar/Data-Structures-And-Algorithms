//                  Height of Binary Tree
//  easy  - recursion

/*
Given a binary tree, find its height.

Example 1:

Input:
     1
    /  \
   2    3
Output: 2

Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
       if( node == NULL)    
            return 0;
        //  traverse left
        int leftH = height(node -> left);
        //  traverse right
        int rightH = height( node -> right);
        
        return max(leftH , rightH) + 1;
    }
};