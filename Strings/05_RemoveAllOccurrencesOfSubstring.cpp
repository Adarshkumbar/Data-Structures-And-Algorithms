//1. s - string , part - part of string 
//2. if part is present in s remove it 

//              "logic "         used find ( 1st  occrance )and erase from STL
//  .... loop till s.length()!= 0 and find(part) ... i.e part present 
// if present remove that part ........ s.erase(s.find(part), part.length())
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

string removeAllOccurrences( string str , string part ){

    while( str.length() != 0 && str.find(part) < str.length())   // loop till str length != 0 and part is found in the string str 
        str.erase(str.find(part) , part.length()) ;  // if part is found in  string erase it 
    return str;
}

int main(){
    string str, part; 
    cout<<"Enter a String :";
    getline(cin , str);
    cout<<"Enter a Part :";
    cin>> part;
    cout<<"\n New String is : "<< removeAllOccurrences(str, part) ;

    return 0;
}

