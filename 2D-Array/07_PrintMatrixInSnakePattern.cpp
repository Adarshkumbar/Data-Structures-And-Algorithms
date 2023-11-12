//                      Print Matrix in snake Pattern
// easy
/*
Given a matrix of size N x N. Print the elements of the matrix in the snake like pattern depicted below.

Example 1:
Input:
N = 3 
matrix[][] = {{45, 48, 54},
             {21, 89, 87}
             {70, 78, 15}}
Output: 
45 48 54 87 89 21 70 78 15 
Explanation:
Matrix is as below:
45 48 54
21 89 87
70 78 15
Printing it in snake pattern will lead to 
the output as 45 48 54 87 89 21 70 78 15.
*/
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
    //  GIVEN MATRIX IS SQUARE MATRIX
        vector<int>ans;
        int n = matrix[0].size();
    //  Start from i = 0 to i < n 
        for(int i = 0 ; i< n ; i++){
            //  if i is odd  loop left to right -->
            // if  i is even loop right to left <--
            
            if( i % 2 == 0){ // even
                //  left to right
                for( int j = 0 ; j < n ; j++){
                    ans.push_back(matrix[i][j]);
                }
            }
            else{           // odd
                //  right to left
                  for( int j = n-1 ; j >= 0 ; j--){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int> > matrix(n); 
    for(int i=0; i<n; i++)
    {
        matrix[i].assign(n, 0);
        for( int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    Solution ob;
    vector<int> result = ob.snakePattern(matrix);
    for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}