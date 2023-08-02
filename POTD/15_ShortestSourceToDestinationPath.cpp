//              Shortest Source to Destination Path
/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//    BFS is used
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        //  checking if starting posi is 0 .....if 0 we cant move i.e reach destination
        if(A[0][0] == 0 ) return -1;
        
        // queue for bfs 
        queue<pair <int,int> > q;
        // creating visited vector to check if node is visited alr
        vector <vector<bool>> vis(N,vector<bool>(M,false));
        int path = 0 ;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i< size ; i++){
                auto cur = q.front();
                q.pop();
                //  checking if destination reached
                if(cur.first == X && cur.second == Y) return path;
                
                // move right
                if(cur.first+1< N && !vis[cur.first+1][cur.second] && A[cur.first+1][cur.second] == 1){
                    q.push({cur.first+1,cur.second});
                    vis[cur.first+1][cur.second] = true;
                }
                // move left
                 if(cur.first-1>= 0 && !vis[cur.first-1][cur.second] && A[cur.first-1][cur.second] == 1){
                    q.push({cur.first-1,cur.second});
                    vis[cur.first-1][cur.second] = true;
                }
                // 
                if(cur.second+1<M && !vis[cur.first][cur.second+1] && A[cur.first][cur.second+1]==1){
                    q.push({cur.first,cur.second+1});
                    vis[cur.first][cur.second+1]=  true;
                }
                // 
                if(cur.second-1 >=0 && !vis[cur.first][cur.second-1] && A[cur.first][cur.second-1]==1){
                    q.push({cur.first,cur.second-1});
                    vis[cur.first][cur.second+1]=  true;
                }
            }
            path++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends