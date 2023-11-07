//                                  Ticket Counter
//  easy
/*
N people from 1 to N are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

Example 1

Input:
N = 9
K = 3
Output:
6
Explanation:
Starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}. After the first distribution queue will look like {4, 5, 6, 7, 8, 9}. And after the second distribution queue will look like {4, 5, 6}. The last person to get the ticket will be 6.
Example 2

Input:
N = 5
K = 1
Output:
3
Explanation:
Queue start as {1, 2, 3, 4, 5} -> {2, 3, 4, 5} -> {2, 3, 4} -> {3, 4} -> {3}
Last person to get ticket will be 3.
*/

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // using deque to solve this
        
        deque<int> dq;
        
        // Step - 1 pushing all emts from 1 to N in Deque
        for(int i = 1 ; i <= N ; i++){
            dq.push_back(i);
        }
        //  Step - 2 Now we go on popping k emts from front then rear till dq becomes empty
        
        int ans = 0;
        while( !dq.empty()){
        // first k emts
            for(int i = 0 ; i < K && !dq.empty() ; i++){
                ans = dq.front();
                dq.pop_front();
            }
        //  last k emts 
            for(int i = 0 ; i < K && !dq.empty() ; i++){
                ans = dq.back();
                dq.pop_back();
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){

    int N;
    scanf("%d",&N);
    
    
    int K;
    scanf("%d",&K);
    
    Solution obj;
    int res = obj.distributeTicket(N, K);
    cout<<res<<endl;
        

}