//                              Count the Reversals
//  medium
/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    string s; cin >> s;
    cout << countRev (s) << '\n';
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    stack<char>stk;
    
    // Step - 1 keep on pushing char from string s in stack if stk.top == { and char ==} .stk.pop
    
    for(int i = 0 ; i< s.length() ; i++){
        char ch = s[i];
        
        if( !stk.empty() && stk.top() == '{' && ch == '}'){
            stk.pop();
        }
        else{
            stk.push(ch);
        }
    }
    
    // step -2  Now counting how many "{" and "}" are present in stack
    // cout<<"size "<<stk.size()<<endl;
    int a = 0;
    int b = 0;
    while( !stk.empty()){
        if( stk.top() == '{'){
            a++;
            stk.pop();
        }
        else{
            b++;
            stk.pop();
        }
    }
    //  if braces are odd we cant reverse and make valid hence return -1 
    if( (a + b ) & 1 == 1)  // if oddd
        return -1;
    int ans = ((a + 1) /2) +((b + 1) /2);// formula to be remembered
    return ans;
}