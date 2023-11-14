//                          Check if strings are rotations of each other or not
//  easy  -- just finding whether s2 pattern appears in s1+s1 
/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.

Example 2:

Input:
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        s1 += s1; // making s1+s1
        
        return s1.find(s2) != string :: npos; // prebuilt code 
    }
};

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    Solution obj;
    cout<<obj.areRotations(s1,s2)<<endl;
    return 0;
}