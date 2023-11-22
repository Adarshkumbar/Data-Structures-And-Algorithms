//      Determine if Two Trees are Identical
/*
Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: 
Yes
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: 
No
Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
*/
class Solution
{
    public:
   
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 and !r2 ) return true;
        if(!r1 || !r2) return false;
        if(r1->data != r2->data) return false;
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};