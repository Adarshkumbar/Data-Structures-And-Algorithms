//                  Sum of upper and lower triangles
//  easy
/*
Given a square matrix of size N*N, print the sum of upper and lower triangular elements. Upper Triangle consists of elements on the diagonal and above it. The lower triangle consists of elements on the diagonal and below it. 

Example 1:

Input:
N = 3 
mat[][] = {{6, 5, 4},
           {1, 2, 5}
           {7, 9, 7}}
Output: 
29 32
Explanation:
The given matrix is
6 5 4
1 2 5
7 9 7
The elements of upper triangle are
6 5 4
  2 5
    7
Sum of these elements is 6+5+4+2+5+7=29.
The elements of lower triangle are
6
1 2
7 9 7
Sum of these elements is 6+1+2+7+9+7= 32.
*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
    //  step 1 - calculate diagonal sum 
        int digSum = 0;
        int uTriSum = 0;
        int lTriSum = 0;
    // Calculating diagonal Sum 
        for(int i = 0 ; i < n ; i++){
            digSum += matrix[i][i];
        }
        
    //  step 2 - calculating lower Triangle sum
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                lTriSum += matrix[i][j];
            }
        }
        lTriSum += digSum ; // adding diagonal sum that we calculated earlier
        
    //  Step 3 - calculating upper Triangle sum
        for( int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j< n ; j++){
                uTriSum += matrix[i][j];
            }
        }
        uTriSum += digSum ; // adding diagonal sum that we calculated earlier
        
    //  step 4 - returning solution 
        vector<int> ans ; 
        ans.push_back(uTriSum);
        ans.push_back(lTriSum);
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
    vector<int> result = ob.sumTriangles(matrix,n);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}