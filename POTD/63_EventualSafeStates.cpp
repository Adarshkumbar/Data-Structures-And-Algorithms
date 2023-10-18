//                      Eventual Safe States
// medium
/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Input:


Output:
2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
Example 2:

Input:


Output:
3
Explanation:
Only node 3 is a terminal node, and every path 
starting at node 3 leads to node 3.
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       vector<int> ans ; 
       
       vector<int> arr[V] ; 
       int indegree[V] = { 0 } ;
       for( int i = 0 ; i < V ; i++){
           for( auto it : adj [i]){
               arr[it].push_back(i);
               indegree[i]++;
           }
       }
       queue<int>q;
       
       for( int i = 0 ; i < V ; i++){
           if( indegree[i]== 0 )
                q.push(i);
       }
       while(!q.empty()){
           int node = q.front();
           q.pop();
           ans.push_back(node);
           
           for( auto it : arr [node]){
               indegree[it]--;
               if( indegree[it] == 0)
                    q.push( it );
           }
       }
       sort( ans.begin() , ans.end());
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends