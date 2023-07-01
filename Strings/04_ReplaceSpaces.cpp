// Task : replace void space with @69
// Ex: Hi its me --> Hi@69its@69me 
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

string replaceSpaces(string str){
    string temp = "";  // this string stores that new string where spaces replaced by @69
    
    //  loop through string to check for void space and perform operations
    for( int i = 0 ; i < str.length() ; i++ ){
        if( str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('6');
            temp.push_back('9');
        }
        else{
           temp.push_back(str[i]);
        }
    }
    return temp;
}

int main(){
    string str; 
    cout<<"Enter a Sentence :";
    getline(cin , str);
   
    cout<<"\n new Sentence is : "<< replaceSpaces(str) ;

    return 0;
}

//   we can do this without temp 
//  just pass reference in replaceSpaces(string &str)
// if(str[i]==' ')
//  str[i] = '@' 