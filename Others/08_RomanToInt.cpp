//              Roman Number to Integer
//  easy
/*
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5

Example 2:

Input:
s = III 
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int romanToDecimal(string &str) {
        //  creating map to store roman values
        
        map<char , int > m;
    //  filling map
        m['I'] = 1 ; 
        m['V'] = 5 ; 
        m['X'] = 10 ; 
        m['L'] = 50 ; 
        m['C'] = 100 ; 
        m['D'] = 500 ; 
        m['M'] = 1000 ; 
        
        int n = str.length();
        int val = 0;
        //  loop from i = 1
        if( n == 1)
            return m[str[0]];
        for( int i = 0; i < n ; i++) {
            //  taking cur value 
            int v1 = m[str[i]];
            int v2 = 0;
            if( i + 1 < n ){
                 v2 = m[str[i+1]];
                
                if( v1 >= v2 ){
                    val += v1;
                }
                else{
                    val += v2 - v1;
                    i++;
                }
            }
            else{
                return val + v1;
            }
          
        }
        return val;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}