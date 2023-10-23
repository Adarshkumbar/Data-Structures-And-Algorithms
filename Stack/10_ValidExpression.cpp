//                          Valid Expression
// easy/medium  -- using loop
/*
Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'. The task is to verify the validity of the arrangement.

An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

Example 1:

Input:
S = ()[]{}
Output: 1
Explanation: The arrangement is valid.
 

Example 2:

Input:
S = ())({}
Output: 0
Explanation: Arrangement is not valid.
*/

#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    cout<<"Enter expression:";
    string str;
    getline(cin,str);
    cout<<valid(str)<<endl;
    return 0;
}
// --------------------------------------------------------------------------------------------------------
bool valid(string s)
{
    stack< char > stk;
    for( int i = 0 ; i < s.length() ; i++){
        char ch = s[i];
        //  if opening parenthesis push into stack
        if( ch == '(' || ch == '{' || ch == '[' ){
            stk.push(ch);
        }
        else{ // means closing paranthesis found
            bool isValid = false; // keep track of valid or nah
            if( ch == ')' && (!stk.empty() ) &&stk.top() == '('){
                isValid = true;
            }
            if( ch == '}' && (!stk.empty() ) && stk.top() == '{'){
                isValid = true;
            }
            if( ch == ']' && (!stk.empty() ) && stk.top() == '['){
                isValid = true;
            }
            
            if( isValid == false)
                return false;
            stk.pop();
        }
    }
    if( stk.empty())
        return true;
    return false;
}