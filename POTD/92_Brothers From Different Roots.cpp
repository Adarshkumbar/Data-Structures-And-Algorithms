//              Brothers From Different Roots
//  easy - store 1 tree in vector and traverse other using BST rules 
/*
/Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)

Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)
*/

void traversal(Node * root1 , int val, int &cnt, int x){
    if( root1 == NULL)
        return ;
    if( root1 -> data + val == x )
    {
        cnt++;
        if(root1 -> data == val )
            return;
    }
    //  left
    if( root1 -> data + val > x )
        traversal(root1 -> left , val,cnt,  x);
    // right
    else
        traversal( root1 -> right ,val, cnt, x);
}

void inorderTraversal( Node * root , vector<int> & v){
    //  base
    if(root == NULL)
        return;
    //  left 
    inorderTraversal( root->left , v);
    //  root
    v.push_back(root->data);
    //  right
    inorderTraversal( root->right , v);
}
int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> v;
    int cnt = 0;
    inorderTraversal( root1 , v);
    for(int i = 0 ; i < v.size() ; i++){
        traversal(root2 ,v[i] , cnt , x );
    }
    return cnt;
}