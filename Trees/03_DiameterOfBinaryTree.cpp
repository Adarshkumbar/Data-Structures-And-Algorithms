//                  Diameter of a Binary Tree
//  medium  - logic left right and both op1 op2 op3 using pair to solve it

/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3

Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
*/

class Solution {
  public:
    pair<int,int> solveD( Node * root){
        if( root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
          
            
        //  go left and find 
        pair<int,int> leftP = solveD(root -> left);
        
        //  go right and find 
        pair<int,int> rightP = solveD(root -> right);
        //  return max height among those two
        
        
        //  getting outputs for left only ,right only and both
        int op1 = leftP.first ; // cuz dia
        int op2 = rightP.first ; // cuz dia
        
        int op3 = leftP.second + rightP.second + 1; // height
        
        // storing ans
        pair<int , int> ans ;
        // store dia for ans
        ans.first = max( max( op1 , op2 ) , op3);
        
        // store height for ans
        ans.second = max( leftP.second , rightP.second) + 1;
        
        return ans;
    }
    int diameter(Node* root) {
    
        return solveD( root ).first;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
