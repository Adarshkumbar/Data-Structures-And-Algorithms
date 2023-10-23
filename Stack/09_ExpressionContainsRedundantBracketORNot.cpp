//                          Expression contains redundant bracket or not
//  medium -- loop approach

#include<bits/stdc++.h>
using namespace std;

// if open parenthesis or operator we push in stack cuz expression is balanced
//  if ) found we pop all oprators till parenthesis ( found  means" no redundancy"
//  if operator was not found then "redundancy"
class Solution {
  public:
    int checkRedundancy(string s) {
        stack <char> stk;
        for( int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            // if open parenthesis or operator we push in stack cuz expression is balanced
            if( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                stk.push(ch);
            }    
            else{  // means either alphabet or closing parenthesis found
                bool isRedundant = true; // just used to mark
                if( ch == ')'){
                    // need to check if operator is present in stack .. else itll be redundant
                    while( stk.top() != '('){ // running loop til op parenthesis found cuz many operator maybe present in between .. we
                        //    we need to pop em all
                        if( stk.top() == '+' || stk.top()  == '-' || stk.top()  == '*' || stk.top()  == '/'){
                                isRedundant = 0 ;
                        }
                        stk.pop();  // popping all operators in between 2 parenthesis;
                    }
                if( isRedundant == true) // means we found redundant ... else move ahead
                    return 1;
                    stk.pop();
                }
            }
        }
        return 0 ; // means we didnt find any redundancy
    }
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}