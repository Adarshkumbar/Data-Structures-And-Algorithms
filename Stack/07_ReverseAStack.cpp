//                          Reverse a Stack  
//  easy / medium  -- Using Recursion

/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
*/

#include <bits/stdc++.h>
using namespace std;


//  Solved USING RECURSION
class Solution{
public:
//  ---------------------- Step 2  --------------------------
    void insertAtBottomStack( stack<int> &St, int emt){
        //  Recursion
    //  BASE CASE
        if(St.empty()){
            // meaning we push top emt to bottom
            St.push(emt);
            return;
        }
        //Storing top emt  and popping from stack
        int topEmt = St.top();
        St.pop();
        
        //  recursive Call to keep on popping
        insertAtBottomStack( St, emt);
        
        //  Now putting topEmt back to Stack
        St.push(topEmt);
        
    }
//  ---------------------- Step 1  --------------------------
    void Reverse(stack<int> &St){
        //  Recursion
    //  BASE CASE
        if( St.empty())
            return ;
        //  storing top emt & popping
        int emt = St.top();
        St.pop();
        // RECURSIVE CALL ... now reverse the stack
        Reverse(St);
        
        // while returning insert top emt to bottom of stack
        insertAtBottomStack( St, emt);
    }
};


int main(){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
}