//                  Insert an Element at the Bottom of a Stack
//  easy        -- solved using recursion

/*
You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.
Example 1:

Input:
N = 5
X = 2
St = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
 

Example 2:

Input:
N = 3
X = 4
St = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void solve (stack<int> &St,int X ){
        //  BASE CASE 
        if( St.empty()){  // after all emts popped adding X to it
            St.push( X ); 
            return ;
        }
        //  Storing Top emt and popping it from Stack
        int emt = St.top();
        St.pop();
        //  recursive call
        solve( St , X );
        //  while returning  we need to push emt back top stack
        St.push( emt );
    }
    stack<int> insertAtBottom(stack<int> St,int X){
        //  solved using recursion
       solve( St , X );
       return St;
    }
};


int main(){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    return 0;
}