// Check if string is rotated by two places
// easy
/*
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 
1
Explanation: 
amazon can be rotated anti-clockwise by two places, which will make it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 
0
Explanation: 
If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n = str2.length();
        string ans1="  "; // clockwise
        string ans2 ="";  // anti 
        
    //  creating clockwise ans
    
        ans1+= str2;
        ans1[0] = str2[n-2];
        ans1[1] = str2[n-1];
        ans1.pop_back();
        ans1.pop_back();
        
    //  creating anti clockwise ans
        ans2 = str2;
        ans2.push_back(str2[0]);
        ans2.push_back(str2[1]);
        
        ans2.erase(ans2.begin() + 0);
        ans2.erase(ans2.begin() + 0);
        // ans2.erase(ans2.begin() + 1);
        if( str1 == ans1 )
            return true;
        if (str1 == ans2)
            return true;
            
        return false;
    }

};

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}