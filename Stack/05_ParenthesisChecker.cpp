//              Parenthesis Checker
//  easy        
/*

Example 1:
Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.

Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack <char> stk;
        for( int i = 0 ; i< x.length() ; i++){
            char ch = x[i];
            if( ch == '(' || ch == '{' || ch == '['){ // open 
                stk.push( ch );
            }
            else{  // closed
                if( !stk.empty()){
                    if( stk.top() == '(' && ch == ')' ||
                        stk.top() == '{' && ch == '}'   ||
                        stk.top() == '[' && ch == ']')
                        {
                            stk.pop();
                        }
                    else
                        return false ;
                }
                else{
                    //  means invalid cuz } , ) or ] present at beginning
                    return false;
                }
            }
        }
        // after loop over then
        if( stk.empty())
            return true;
        else
            return false;
    }

};


int main()
{
  
   string a;

       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
}