//                      Reverse each word in a given string
// medium
/*
Given a String. Reverse each word in it where the words are separated by dots.

Example 1:

Input:
S = "i.like.this.program.very.much"
Output: 
i.ekil.siht.margorp.yrev.hcum
Explanation: 
The words are reversed as
follows:"i" -> "i","like"->"ekil",
"this"->"siht","program" -> "margorp",
"very" -> "yrev","much" -> "hcum".
Example 2:

Input: 
S = "pqr.mno"
Output: 
rqp.onm
Explanation: 
The words are reversed as
follows:"pqr" -> "rqp" ,
"mno" -> "onm"s
*/

//  logic : 1.gonna loop till end of string usin i 
//          2. loop till . found and increment i 
//          3. use stack to push char from above loop
//          4. now push top of stack in ans string and  pop till !stk.empty() after this add .
//          5. if original string contains . at last dont do anything else push .
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string ans ="";
        for( int i = 0 ; i < s.length() ; i++){
             
            //  creating stack for every word
            stack<char> stk;
            // char ch = s[i];
            while( s[i] != '.' && i < s.length()){
                stk.push(s[i++]);
            }
            while( !stk.empty()){
                ans.push_back(stk.top());
                stk.pop();
            }
            ans.push_back('.');
        }
        if( s[s.length() -1 ] != '.') 
            ans.pop_back();
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}
