//                      Stack Permutations
//  medium
/*
You are given two arrays A and B of unique elements of size N. Check if array B is a stack permutation of the array A or not.
Stack permutation means that array B can be created from array A using a stack and stack operations.

Example 1:
Input:
N = 3
A = {1,2,3}
B = {2,1,3}
Output:
1
Explanation:
1. push 1 from A to stack
2. push 2 from A to stack
3. pop 2 from stack to B
4. pop 1 from stack to B
5. push 3 from A to stack
6. pop 3 from stack to B
 

Example 2:
Input:
N = 3
A = {1,2,3}
B = {3,1,2}
Output:
0
Explanation:
Not Possible
 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        //  using stack and queue to solve this problem
        
    // Step 1 - push all emts of B in queue ..this is used to compare
        queue<int> q ;
        
        for(int i = 0 ; i < N ; i++){
            q.push(B[i]);
        }
        
    //  Step -2 keep on pushing emts of A in stack and compare ....if i = N the  return false
        //  cuz we cant form B with A using stack
        stack<int> stk;
        
        for(int i = 0 ; i < N ; i++){
            stk.push(A[i]);
            
            while( !stk.empty() && stk.top() == q.front()){ // loop is used cuz compare continuously
                //  popping from both cuz equal
                stk.pop();
                q.pop();
                
                //  after popping if q becomes empty then we could build B with A using stack
                if( q.empty())
                    return true;
            }
        }
        //  if we come out of loop then we were unable to form B with A using stack
        return 0;
    }
};

int main(){

    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    Solution ob;
    cout<<ob.isStackPermutation(n,a,b)<<endl;

    return 0;
}