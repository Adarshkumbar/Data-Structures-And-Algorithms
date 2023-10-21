//                      Delete middle element of a stack
//  easy -- solved using recursion

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    // solving recursively
    public:
    void solve (stack<int>&s, int size , int count ){
        //  base case
        if( count == size /2){
            s.pop();
            return ;
        }
            
        //  now storing top emts
        int emt = s.top();
        s.pop();
        //  recursive call 
        solve(s,size , count +1 );
        //  now pushing emt back to stack
        s.push( emt );
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0 ;
        
        solve(s,sizeOfStack , count  );
    }
};


int main() {
  
    
   
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
   
    return 0;
}
