        //   Surround The 1's
/*
Given a matrix of order nxm, composed of only 0's and 1's, find the number of 1's in the matrix that are surrounded by an even number (>0) of 0's. The surrounding of a cell in the matrix is defined as the elements above, below, on left, on right as well as the 4 diagonal elements around the cell of the matrix. Hence, the surrounding of any matrix elements is composed of 8 elements. Find the number of such 1's.

Example 1:

Input: 
matrix = {{1, 0, 0}, 
          {1, 1, 0}, 
          {0, 1, 0}}
Output: 
1
Explanation: 
1 that occurs in the 1st row and 1st column, has 3 surrounding elements 0,1 and 1. The occurrence of zero is odd. 
1 that occurs in 2nd row and 1st column has 5 surrounding elements 1,0,1,1 and 0. The occurrence of zero is even. 
1 that occurs in 2nd row and 2nd column has 8 surrounding elements. The occurrence of 0 is odd. 
Similarly, for the 1 that occurs in 3rd row and 2nd column, the occurrence of zero in it's 5 surrounding elements is odd. 
Hence, the output is 1.
Example 2:

Input: 
matrix = {{1}}
Output: 
0
Explanation: 
There is only 1 element in the matrix. Hence, it has no surroundings, so it's count for even 0's is 0 for the whole matrix. 
0 is even but we want occurrence of a zero in the surrounding at least once. 
Hence, output is 0.
*/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private : 
//  this function checks if top,left,right,bottom and diagonals are valid or not
    bool isValid(int i , int j , int n , int m){
        if( (i <= n) && (i >= 0) && (j <= m) && (j >= 0))
            return true;
        return false;
    }
public:
    int Count(vector<vector<int> >& matrix) {
        
        int count = 0;     // ans to be returned
         // count no. of surrounding zeros of 1
        
        int n = matrix.size();      // no of ROWS
        int m = matrix[0].size();   // no of COLUMNS
        
        for(int i = 0 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                if(matrix[i][j])
                {
                    int zeroCnt = 0 ; 
                    // top 1
                    if( i-1 >= 0){
                        zeroCnt += matrix[i-1][j] == 0;
                    }
                    // top right 2
                    if( i-1 >= 0 && j+1 < m ){
                         zeroCnt += matrix[i-1][j+1] == 0;
                    }
                    // right 3 
                    if( j+1 < m ){
                        zeroCnt += matrix[i][j+1] == 0;
                    }
                    // bottom right 4 
                    if( i+1 < n && j+1 < m ){
                        zeroCnt +=matrix[i+1][j+1] == 0;
                    }
                    // bottom 5 
                    if( i+1 < n ){
                        zeroCnt += matrix[i+1][j] == 0;
                    }
                    // bottom left 6 
                     if( i+1 < n && j-1 >= 0 ){
                         zeroCnt += matrix[i+1][j-1] == 0;
                    }
                    // left 7 
                    if( j-1 >= 0 ){
                        zeroCnt += matrix[i][j-1] == 0;
                    }
                    // top left 8
                    if( i-1 >= 0 && j-1 >= 0 ){
                        zeroCnt += matrix[i-1][j-1] == 0;
                    }
                    if( !(zeroCnt & 1) and zeroCnt)
                        count++;
                }
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends