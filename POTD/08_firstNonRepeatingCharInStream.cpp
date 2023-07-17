//                  First non-repeating character in a stream
/*
 Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		  string ans;
		  int n = A.length();
		  int arr[26] = {0};  // stores repeted or not
		  queue<char> q;     // used to store string which we get from input and perform operations based on this
		 
		  for(int i = 0 ; i < n ; i++){
		      char ch = A[i];
		      arr[ch-'a']++;
		      q.push(ch);
		      
		      while(!q.empty()){
		          if(arr[q.front()-'a'] == 1)
		          {
		              ans.push_back(q.front());
		              break;
		          }
		          else
		            {
		                q.pop();
		            }
		      }
		      if(q.empty())
		        ans.push_back('#');
		  }
		  return ans;
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}