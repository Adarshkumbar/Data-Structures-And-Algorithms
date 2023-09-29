 //                                     Number Of Enclaves
/* medium 
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1,0,1,0}; // x axis
    int dy[4] = {0,1,0,-1}; // y axis
    
    bool ifSafe( int x , int y , vector<vector<bool>> & vis , int n , int m ,vector<vector<int>> & grid){
        return (x>= 0 && x<n && y>= 0 and y < m and grid[x][y] == 1 && vis[x][y]==0);
    }
    
    void dfs(int i , int j , vector<vector < bool>>&vis , int n , int m , vector<vector<int>>&grid){
        vis[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if( ifSafe(x, y , vis , n, m , grid)){
                dfs(x, y , vis , n , m , grid); // recursive call
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int ans = 0 ; 
        int n = grid.size();   // no. of rows
        int m = grid[0].size();// no. of columns
        // creating visited grid to track vis/ not vis
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        // for row
        for(int i = 0 ; i < n ; i++){
            if( grid[i][0] == 1){
                //  perform dfs if boundary is 1 
                dfs( i , 0 , vis , n , m , grid);
            }
            if( grid[i][m-1] == 1){
                //  perform dfs if boundary is 1 
                dfs( i , m-1 , vis , n , m , grid);
            }  
        }
        // for colms
         for(int j = 0 ; j < m ; j++){
            if( grid[0][j] == 1){
                //  perform dfs if boundary is 1 
                dfs( 0 , j , vis , n , m , grid);
            }
            if( grid[n-1][j] == 1){
                //  perform dfs if boundary is 1 
                dfs( n-1 , j , vis , n , m , grid);
            }  
        }
        for(int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( grid[i][j] == 1 and vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends