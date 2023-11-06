//                      Letters Collection
//  easy
/*
The Postmaster wants to write a program to answer the queries regarding letter collection in a city. A city is represented as a matrix mat of size n*m. Each cell represents a house and contains letters which are denoted by a number in the cell. The program should answer q queries which are of following types:
1 i j : To sum all the letters which are at a 1-hop distance from the cell (i,j) in any direction
2 i j : To sum all the letters which are at a 2-hop distance from the cell (i,j) in any direction 
The queries are given in a 2D matrix queries[][].
In one hop distance postmaster can go to any of [(i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1)] from (i,j). 

Example 1:

Input: 
n = 4, m = 5
mat = {{1, 2, 3, 4, 10}, 
       {5, 6, 7, 8, 10}, 
       {9, 1, 3, 4, 10}, 
       {1, 2, 3, 4, 10}}
q = 2
queries = {{1 0 1}, 
           {2 0 1}}
Output: 
22 29
Explaination: 
For the first query sum is 1+5+6+7+3 = 22. 
For the second query sum is 9+1+3+4+8+4 = 29.
Example 2:

Input: 
n = 6, m = 6
mat = {{ 1,  2,  3,  4,  5,  6}, 
       { 7,  8,  9, 10, 11, 12}, 
       {13, 14, 15, 16, 17, 18}, 
       {19, 20, 21, 22, 23, 24},
       {25, 26, 27, 28, 29, 30},
       {31, 32, 33, 34, 35, 36}}
q = 1
queries = {{2 3 2}}
Output: 
336
Explaination: 
The first query sum is 7+8+9+10+11+17+23+29+35+34+33+32+31+25+19+13 = 336.
*/

// ------------------------------------------------------------ GOOD CODE -----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
//  this function is to Check if emt present in MATRIX or out of bound

 vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int hop = queries[i][0];
            int r = queries[i][1];
            int c = queries[i][2];
            if (hop == 1) {
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
                int sum = 0;
                for (int j = 0; j < 8; j++) {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            } else {
                int dx[] = {-2, -2, 2, 2, -2, 2, 0, 0, -2, -2, 2, 2, -1, 1, -1, 1};
                int dy[] = {-2, 2, -2, 2, 0, 0, -2, 2, -1, 1, -1, 1, -2, -2, 2, 2};
                int sum = 0;
                for (int j = 0; j < 16; j++) {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){

    int n, m, q, ty, i, j;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin>>mat[i][j];
    cin>>q;
    vector<int> queries[q];
    for(int k = 0;k < q;k++){
        cin>>ty>>i>>j;
        queries[k].push_back(ty);
        queries[k].push_back(i);
        queries[k].push_back(j);
    }
    
    Solution ob;
    vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
    for(int u: ans)
        cout<<u<<"\n";
    return 0;
}
// } Driver Code Ends




// ----------------------------------------------------------- SHIT CODE -------------------------------------------
/*

class Solution{
public:
    
//  this function is to Check if emt present in MATRIX or out of bound

    bool isValid(  int n , int m , int i , int j ){ // n & m size of MAT and i & j are cur posi to be checked
        if( i >= 0 && i < n && j >= 0 && j < m){
            return true;
        }
        return false;
    }

//  calculating sum for one Hop
//  i & j are curr position and n & m are size of matrix
    int hopOne( int i , int j , int n , int m ,vector<vector<int>> mat ){
        int sum = 0;
    // right 
        if ( isValid( n , m , i , j + 1)) // if valid
            sum += mat[i][j+1];
    // left 
        if ( isValid( n , m , i , j - 1)) // if valid
            sum += mat[i][j-1];
    // up 
        if ( isValid( n , m , i - 1, j )) // if valid
            sum += mat[i-1][j];
    // down
        if ( isValid( n , m , i + 1 , j)) // if valid
            sum += mat[i+1][j];
    // bottom right
        if( isValid( n , m , i + 1, j + 1)) // if valid
            sum += mat[i+1][j + 1];
    // top left 
        if( isValid( n , m , i - 1, j - 1)) // if valid
            sum += mat[i-1][j - 1];
    // bottom left   
        if( isValid( n , m , i + 1, j - 1)) // if valid
            sum += mat[i+1][j - 1];    
    // top right  
        if( isValid( n , m , i - 1, j + 1)) // if valid
            sum += mat[i-1][j + 1];    
        
        return sum;
    }

//  calculating sum for two Hops
    int hopTwo( int i , int j , int n , int m ,vector<vector<int>> mat ){
         int sum = 0;
// ------------------------ NORMAL 8 directions ----------------------------------------
    // right 
        if ( isValid( n , m , i , j + 2)) // if valid
            sum += mat[i][j+2];
    // left 
        if ( isValid( n , m , i , j - 2)) // if valid
            sum += mat[i][j-2];
    // up 
        if ( isValid( n , m , i - 2, j )) // if valid
            sum += mat[i-2][j];
    // down
        if ( isValid( n , m , i + 2 , j)) // if valid
            sum += mat[i+2][j];
    // bottom right
        if( isValid( n , m , i + 2, j + 2)) // if valid
            sum += mat[i+2][j + 2];
    // top left 
        if( isValid( n , m , i - 2, j - 2)) // if valid
            sum += mat[i-2][j - 2];
    // bottom left   
        if( isValid( n , m , i + 2, j - 2)) // if valid
            sum += mat[i+2][j - 2];    
    // top right  
        if( isValid( n , m , i - 2, j + 2)) // if valid
            sum += mat[i-2][j + 2];    
            
// ------------------------ IN BETWEEN 8 directions ----------------------------------------
    // between right and bottom right
        if( isValid( n , m , i + 1, j + 2)) // if valid
            sum += mat[i+1][j + 2];
    // between right and top right
        if( isValid( n , m , i - 1, j + 2)) // if valid
            sum += mat[i-1][j + 2];    
    // between left and top left
        if( isValid( n , m , i - 1, j - 2)) // if valid
            sum += mat[i-1][j - 2];    
    // between left and bottom left
        if( isValid( n , m , i + 1, j - 2)) // if valid
            sum += mat[i+1][j - 2];   
    // between up and top left
        if( isValid( n , m , i - 2 , j - 1)) // if valid
            sum += mat[i-2][j - 1];
    // between up and top right
        if( isValid( n , m , i - 2 , j + 1)) // if valid
            sum += mat[i-2][j + 1]; 
    // between down and bottom left
        if( isValid( n , m , i + 2 , j - 1)) // if valid
            sum += mat[i+2][j - 1];  
    // between down and bottom right
        if( isValid( n , m , i + 2 , j + 1)) // if valid
            sum += mat[i+2][j + 1]; 
            
        return sum;
    }

    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        //  Step - 1 loop from 0 till q and get -> 
        //                                      a) hop.no 1/2 .b) n(row).c) m.(col)
        for( int i = 0 ; i < q ; i++){
            int hop = queries[i][0];
            int row = queries[i][1];
            int col = queries[i][2];
        // step - 2 solve for hop 1 or hop 2 
            if( hop == 1 ){
                ans.push_back(hopOne(row , col , n , m , mat));
            }
            else{
                ans.push_back(hopTwo(row , col , n , m , mat));
            }
        }
        return ans;
    }
};
*/