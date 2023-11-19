//              Find the String
//  HARD .. using map & recursion

/*
Given two integers N and K, the task is to find the string S of minimum length such that it contains all possible strings of size N as a substring. The characters of the string should be from integers ranging from 0 to K-1.  

Example 1:

Input:
N = 2, K = 2
Output: 
00110
Explanation: 
Allowed characters are from 0 to k-1 (i.e., 0 and 1).
There are 4 string possible of size N=2 
(i.e "00", "01","10","11")
"00110" contains all possible string as a 
substring. It also has the minimum length.

Example 2:

Input:
N = 2, K = 3
Output: 
0010211220
Explanation: 
Allowed characters are from 0 to k-1 (i.e., 0, 1 and 2).
There are total 9 strings possible
of size N, given output string has the minimum
length that contains all those strings as substring.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     void dfs(string &curr, string & ans, unordered_map<string,int> &mp, int k)
    {
        string temp; 
        for(int i=k-1; i>=0; i--)
        {
          temp=curr. substr (1); 
          temp+=char(i+48);
        if(mp.find(temp)==mp.end()){
            mp[temp]=1;
            ans+=char(i+48);
            dfs (temp, ans, mp, k); 
            return;
            }
        }   
    }
    string findString(int n, int k) {
    
    string ans="" , temp="";
    unordered_map<string, int> mp;
    for(int i=0; i<n; i++)
    {
    ans+='0';
    }
    temp=ans; mp[temp]=1;
    dfs (temp, ans, mp, k);
    return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 