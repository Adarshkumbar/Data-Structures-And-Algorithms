//                          Roman Number to Integer
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
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
    //  creating map to store Roman Values of I , V ,....
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        int n = str.length();
        int i = 0;
        if( n == 1)
            return m[str[0]];
        while( i < n){
            if( i+1 < n && m[str[i]] < m[str[i+1]]){
                ans += m[str[i+1]] - m[str[i]];
                i+= 2;
            }
            else{
                ans+= m[str[i]];
                i++;
            }
        }
        return ans;
    }
};
s
//{ Driver Code Starts.

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
        cout<<"Enter Roman Number : ";
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    // }
}
// } Driver Code Ends