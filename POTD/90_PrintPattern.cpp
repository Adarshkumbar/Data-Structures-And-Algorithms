//                      Print Pattern
//  easy - recursion
/*
Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace 
N with N + 5 until N regains its initial value.

Example 1:

Input: 
N = 16
Output: 
16 11 6 1 -4 1 6 11 16
Explaination: 
The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.

Example 2:

Input: 
N = 10
Output: 
10 5 0 5 10
Explaination: It follows the same logic as per the above example.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void minus5(vector<int> & v , int N){
        //  base case
        if( N <= 0 ){
            v.push_back(N);
            return;
        }
        //  push value and recursive call
        v.push_back(N);
        minus5(v,N-5);
    }
    void plus5(vector<int> & v , int N , int x){
        //  base case
        if( x >= N)
            return;
        //  push x+ 5 and call recursively
        v.push_back(x+5);
        plus5(v,N,x+5);
    }
    vector<int> pattern(int N){
        vector<int> v ;
        minus5(v , N);
        // now calling plus5
        int size = v.size() ; // this is where last one ended
        int x = v[size -1];
        plus5(v,N,x);
        
        return v;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}