//                  Non Repeating Character
/*
Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= N <= 105

*/
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        int arr[26] = {0};  // count frequency 
        queue<char> q;      // check each char if repeating or not
        // just need to return q.front()as ans 
        // if q is empty return $
        int n = S.length();
       
       
       for( int i = 0 ; i < n ; i++){
            char ch = S[i];
            q.push(ch);
            arr[ch-'a']++;
            
            while(!q.empty()){
                if( arr[q.front() - 'a'] == 1)
                {
                    ans = q.front();
                    break;
                }
                else{
                    q.pop();
                }
            }
       }
       if(q.empty())
            return '$';
        return q.front();
    }

};


int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}