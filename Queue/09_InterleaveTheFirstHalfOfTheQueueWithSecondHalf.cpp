//                          Interleave the First Half of the Queue with Second Half
//  medium
/*
You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue 
with the second half of the queue.

Example 1:

Input:
N = 4
Q = {2,4,3,1}
Output:
{2,3,4,1}
Explanation:
After the mentioned rearrangement of the first half
and second half, our final queue will be {2,3,4,1}.
*/

//  --------------------------------------------------- 2 approaches -------------------------------------------
//  --------------------------------------- APPORACH- 1 (using queue)-------------------------------------------------------
//  step 1 - create newQ
//  step 2 - push 1st half of q in newQ
//  step 3 - now keep on pushing and popping emts alternatively in q
//  step 4 - return ans;

//  --------------------------------------- APPORACH- 2 (using stack)-------------------------------------------------------
// step 1 - 1st half in stack 
// step 2 - stack to queue
// step 3 - pop 1st half and push in queue
// step 4 - first half queue in stack
// step 5 - now push alternatively from stack and queue

// -----------------------------------------------------------------------------------------------------------------------//
//           APPORACH- 1 (using queue)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> ans;
        queue<int> q2;
        int n = q.size();
        
        n = n/ 2 ;
        while( n > 0){
            //  pushing 1 st half of queue in queue2
            int emt = q.front();
            q.pop();
            
            q2.push(emt);
            n--;
        }
    //  now pushing alternativelu in ans
        while( !q.empty() && !q2.empty()){
             //  pushing from q2
            ans.push_back(q2.front());
            q2.pop();
            
            //  pushing from q1
            ans.push_back(q.front());
            q.pop();
        }
        if( !q.empty())
            ans.push_back(q.front());
        if( !q2.empty())
            ans.push_back(q2.front());
        return ans;
    }
};

int main(){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    return 0;
}