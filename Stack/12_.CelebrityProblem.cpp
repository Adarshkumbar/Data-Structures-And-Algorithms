//                                         The Celebrity Problem
// Medium
/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack < int > stk;
        //  pushing all the emts in stack
        for( int i = 0 ; i< n ; i++){
            stk.push( i );
        }
        
        //  getting top 2 emts and checking if one knows other 
        //  if knows remove and push other emt back to stack
        
        while( stk.size() > 1){
            int a = stk.top(); 
            stk.pop();
           
                
            int b = stk.top(); 
            stk.pop();
            
            // checking if a knows b or nah
            if( M[a][b] == 1){
                //  discard a and push b into stack
                stk.push(b);
                // continue;
            }
            // checking if b knows a or nah
            else{
                stk.push(a);
            }
        }
        //  now only 1 emt left out which is potential CELEBRITY
        //  checking row ---- all should be 0 cuz celeb knows noone
        for( int i = 0 ; i < n ; i ++){
            if( M[stk.top()][i] != 0 )
                return -1;
        }
        //  if came out of above loop means we need to check column
        //  cuz everyone knows celeb  and diagonal is 0 obviosly
        
         M[stk.top()][stk.top()] = 1; // making one ;
         for( int i = 0 ; i < n ; i ++){
            if( M[i][stk.top()] != 1 ){
                return -1;
            }
        }
        
        //  making this back to 0 as it was
        M[stk.top()][stk.top()] = 0;
        return stk.top();
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}