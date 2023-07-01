
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z') // if lower case do nothing
    {
        return ch;
    }
    else{                      // if capital convert to lower
        return ch-'A'+'a';
    }
}
bool isPalindrome(string str){
    int s = 0;
    int e = str.length()-1;
    while( s <= e){
        if( toLowerCase(str[s]) == toLowerCase(str[e]) ) // simply str[s] == str[e] if case specific
        {
            s++ ; e--;
        }
        else{
            return false;
        }
    }
    return 1;
}
int main()
{
    string str; 
    cout<<"Enter string:"<<endl;
    cin>>str;
    cout<<" Is str Palindrome : "<< isPalindrome(str);
}