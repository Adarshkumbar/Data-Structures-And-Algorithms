//              Boundary Traversal of binary tree
//  medium - 1. print left 2. print leaves . 3 print right

/*
Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
Explanation:

*/

// -------- 1 -------------------------
    void traverseLeft(Node * root , vector<int> & ans){
        //  base case    return if leaf or root becomes null
        if( root == NULL || root -> left == NULL && root -> right == NULL)
            return ;
        //  go left 
        ans.push_back(root -> data);
        if( root -> left )
            traverseLeft(root -> left ,ans);
        else
            traverseLeft( root -> right ,ans );
    }
    
// -------- 2 -------------------------   simple PREORDER
    void traverseLeaf(Node * root , vector<int> & ans){
        if( root == NULL)
            return ;
     //  root/ node
        if( root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
            return ;
        }
            
    //  go left
        traverseLeaf( root -> left ,  ans);
        
    //  go right
        traverseLeaf( root -> right,  ans);
    }
    
// -------- 3  -------------------------  
    void traverseRight(Node * root , vector<int> & ans){
        //  base case           leaf
        if( root == NULL || root -> left == NULL && root -> right == NULL ){
            return ;
        }
        if( root -> right)
            traverseRight( root -> right , ans);
        else
            traverseRight( root -> left , ans );
        ans.push_back(root -> data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector <int> ans;
        if( root == NULL)
            return ans;
        ans.push_back(root->data);
        //  traverse left and fill vector
        traverseLeft(root -> left ,ans);
        
        //  traverse leaves of left sustree
        traverseLeaf( root -> left , ans);
        
        //  traverse leaves of right sustree
        traverseLeaf( root -> right , ans);
        
        //  traverse riught 
        traverseRight(root -> right, ans);
        return ans;
        
    }