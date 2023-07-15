//                      Queue Reversal
/*
Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6
Output: 
6 2 10 1 3 4
Explanation: 
After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.
*/

#include<bits/stdc++.h>
using namespace std;

//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack <int> stk;
        
        while( !q.empty()){
            int x = q.front();
            q.pop();
            stk.push(x);
        }
        while( !stk.empty()){
            int x =   stk.top();
             stk.pop();
            q.push(x);
        }
        return q;
    }
};


int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}