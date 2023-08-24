//                  Multiply two strings

/*
Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       bool neg = 0 ;
       
       if(s1[0] == '-'){
           neg ^= 1;
           s1 = s1.substr(1);
       }
       
       if(s2[0] =='-'){
           neg ^=1;
           s2 = s2.substr(1);
       }
         
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        int n = s1.size();
        int m = s2.size();
        
          vector<int> res(n + m + 20, 0);
        
        for(int i = 0; i < m; i++){
            int pos = i;
            int x = s2[i] - '0';
            for(int j = 0; j < n; j++){
                int y = s1[j] - '0';
                
                res[pos] += x * y;
                
                if(res[pos] > 9){
                    res[pos + 1] += res[pos] / 10;
                    res[pos] = res[pos] % 10;
                }
                
                ++pos;
            }
        }
        
        bool found = 0;
        string ans = "";
        
        for(int i = res.size() - 1; i > -1; i--){
            if(res[i])
                found = 1;
                
            if(found)
                ans += (char)(res[i] + '0');
        }
        
        if(neg)
            ans = '-' + ans;
        
        return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends