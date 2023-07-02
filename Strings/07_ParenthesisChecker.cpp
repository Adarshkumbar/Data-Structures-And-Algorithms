#include<iostream>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;

bool isPar(string x)
    {
         stack <char> stk;
        for( int i = 0 ; i < x.length() ; i++)
        {
            // char ch = x[i];
            if(stk.empty())    // just push if empty
                stk.push(x[i]);
            // pop if {} or [] or ()
            else if( (stk.top() == '(' &&  x[i] == ')') ||
                     (stk.top() == '{' &&  x[i] == '}') ||
                     (stk.top() == '['&&  x[i] == ']') 
                )
                stk.pop(); 
            else{
               stk.push(x[i]);
            }
        }
        if( stk.empty())
            return true;
        else 
            return false;
   }

int main()
{
    string str; 
    cout<<"Enter string:"<<endl;
    getline(cin, str);
    cout<<" \nIs str check : "<< isPar(str);
}