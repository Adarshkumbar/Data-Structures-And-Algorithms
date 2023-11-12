//                      Isomorphic Strings
// easy - using map and vector\
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
/*
If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic.
 A character must be completely swapped out for another character while maintaining the order of the 
 characters. A character may map to itself, but no two characters may map to the same character.

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 
1
Explanation: 
There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 
0
Explanation: 
There are two different characters in aab but there are three different charactersin xyz. So there 
won't be one to one mapping between str1 and str2.*/

#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if( str1.length() != str2.length())
            return false;
        int n = str1.length();
        map< char , char > m; // this is for str1 
        vector<int> v(26,-1); // this is for str 2 // -1 for not mapped 1 for mapped
        
        for(int i = 0 ; i< n ; i++){
            //  checking if already mapped or nah
            
            if( m.find(str1[i]) != m.end()){  // mapped
                if( m[str1[i]] != str2[i])  // means mapped thing and curr thing are different
                    return false;  
            }
            else{
                //  not mapped so we need to map
                //  only if str2[i] hasent been already mapped
                if( v[str2[i] - 'a' ]  != -1) // means mapped
                    return false;
                else{
                    //  not mapped
                    m[str1[i]] = str2[i];
                    v[str2[i]-'a']=1;
                }
            }
        }
        return true;
    }
};

int main()
{
    string s1,s2;
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    return 0;
}