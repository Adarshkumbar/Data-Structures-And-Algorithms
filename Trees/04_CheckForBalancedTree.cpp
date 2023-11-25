//                  Check for Balanced Tree
// easy  logic same as 3rd problem pair stores balance/no and height check for each node 
/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 

*/

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    //  first is balanced/nah and second is height of tree
    pair<bool , int> solve( Node * root){
        //  base case
        if( root == NULL)
        {
            pair<bool, int> p = make_pair(true , 0);
            return p;
        }
        //  traverse left
        pair<bool , int> left = solve(root->left);
        
        //  traverse right
        pair<bool , int> right= solve(root->right);
        
        //  now find difference leftH - rightH <= 1 then balanced
        int diff = abs(left.second - right.second) <= 1 ;
        
        //  storing ans
        pair<bool , int> ans;
        //  1 . storing height
        ans.second = max( left.second , right.second) + 1;
        // 2. storing isbalanced or nah
        //  its balanced when diff is true and left and right sub tree are true
        if( diff && left.first && right.first){
            ans.first = true;
        }
        else
            ans.first = false;
        return ans;
    }
////////////////////////////////////////////////////// starts here-----------------------------  
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};