//                                  Get minimum element from stack
// medium
/*
You are given N elements and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query 
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack 
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2 
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    int minEle ;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
            if( s.empty())
                return -1;
            return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
        //  Check for UNDERFLOW
            if( s.empty()){
                return -1;
            }
            //  check if top is greater than min or nah ... if yes normal pop .,,
            //  if not then we need to change minEle and pop top and return val of smaller top
            // cuz we pushed 2* cur - min from PUSH
            int cur = s.top();
            s.pop();
            
            if( cur > minEle){
                return cur; // normal pop did above only and just returnign that here
            }
            else{
                //  gotta updata min now 
                int prevMin = minEle ; // we need to save minEle cuz we gonna update it cuz top was smaller than min
                minEle = 2*minEle - cur;
                return prevMin;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
        // 1st push   
            if( s.empty()){
                s.push(x);
                minEle = x ;
            }
            else{
                //  check if x is smaller then we need to update min ....else normal shit
            if( x >= minEle){
                s.push( x );
                
            }
            else{
                //  we push updated emt to stack and update minEle
                int val = 2 * x - minEle;
                minEle = x;   // since x is smaller 
                s.push( val ); 
            }
            }
            
       }
};

//{ Driver Code Starts.

int main()
 {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    
    return 0;
}