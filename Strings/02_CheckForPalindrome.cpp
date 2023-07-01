//1. check if valid i.e alphanumeric ....1-9 , a-z and A-Z
//2. remove unwanted char like ' ' % # etc..  put alphanumeric  in new char array
//3. convert to lower case
//4. check if palindrome
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

bool isValid(char ch){  // check if valid i.e alphanumeric ....1-9 , a-z and A-Z
    if( (ch >='a' && ch<= 'z') || (ch >='A' && ch<= 'Z') || (ch >='0' && ch<= '9'))
        return 1;
    else    
        return 0;
}

char toLowerCase(char ch){   // convert to lower case
    if((ch >='a' && ch <='z') || (ch >='0' && ch <='9')) // if lower case do nothing
    {
        return ch;
    }
    else{                      // if capital convert to lower
        char temp = ch-'A'+'a';
        return temp;
    }
}

bool isPalindrome(string str){
    int s = 0;
    int e = str.length()-1;
    while( s <= e){
        if( str[s] == str[e])
        {
            s++ ; e--;
        }
        else{
            return 0;
        }
    }
    return 1;
}


bool checkPalindrome(string &str){
    string temp = ""; // this new aray where we put values

// step 1: check isValid
    for(int i = 0 ; i < str.length(); i++) 
    {
        if(isValid(str[i]))   
            temp.push_back(str[i]);
    }    
 // step 2 : convert to lower case
    for(int i = 0 ; i < str.length(); i++) 
    {
        temp[i]=toLowerCase(temp[i]);
    }cout<<"\n\n new stuff :"<<str <<"\n\n";
// step 3 : check for palindrome
    return isPalindrome(temp);
}
int main()
{
    string str; 
    cout<<"Enter a Sentence:"<<endl;
    getline(cin,str);
    cout<<"\n\n"<<str <<"\n\n";
    cout<<" \nIs  Palindrome : "<< checkPalindrome(str);
}