//                      Transitive closure of a Graph
//  medium
/*
Given a directed graph, determine whether a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here, vertex j is reachable from another vertex i means that there is a path from vertex i to j. The reachability matrix is called the transitive closure of a graph. The directed graph is represented by an adjacency matrix where there are N vertices. 

Example 1:

Input: N = 4
graph = {{1, 1, 0, 1}, 
         {0, 1, 1, 0}, 
         {0, 0, 1, 1}, 
         {0, 0, 0, 1}}
Output: {{1, 1, 1, 1}, 
         {0, 1, 1, 1}, 
         {0, 0, 1, 1}, 
         {0, 0, 0, 1}}
Explanation: 
The output list shows the reachable indexes.
Example 2:

Input: N = 3
graph = {{1, 0, 0}, 
         {0, 1, 0}, 
         {0, 0, 1}}
Output: {{1, 0, 0}, 
         {0, 1, 0}, 
         {0, 0, 1}}
Explanation: 
The output list shows the reachable indexes.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
         vector<vector<int>> adj ( n ,vector<int> ( n , 0) );
         
         for( int i = 0 ; i < n ; i++){
             for ( int j = 0 ; j < n ; j++){
                 if(graph[i][j] == 1 && i != j){
                    adj[i][j] = 1;
                 } 
             }
         }
        vector<vector<int>> ans ( n , vector< int >( n , 0));
        for( int i = 0 ; i < n ; i++){
            dfs( i , i , adj , ans );
        }
        return ans;
    }
    static void dfs ( int i , int j , const vector<vector<int>> & adj ,  vector<vector<int>> & ans ){
        ans[i][j] = 1; 
        for( int it = 0 ; it < adj[j].size(); it++){
            if( adj[j][it] == 1 && ans[i][it] == 0){
                dfs( i , it , adj , ans );
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends