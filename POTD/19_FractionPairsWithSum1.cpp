//                  Fraction pairs with sum 1
/*
Given a list of N fractions, represented as two lists numerator and denominator, the task is to determine the count of pairs of fractions whose sum equals 1.

Example 1:

Input:
N = 4
numerator = [1, 2, 2, 8]
denominator = [2, 4, 6, 12]
Output:
2
Explanation:
Fractions 1/2 and 2/4 sum to 1. Similarly fractions 2/6 and 8/12 sum to 1. So there are 2 pairs of fractions which sum to 1.
Example 2:

Input:
N = 5
numerator = [3, 1, 12, 81, 2]
denominator = [9, 10, 18, 90, 5]
Output:
2
Explanation:
Fractions 3/9 and 12/18 sum to 1. Similarly fractions 1/10 and 81/90 sum to 1. So there are 2 pairs of fractions which sum to 1.
*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        //  creating map to store pair and its frequency 
        map <pair<int,int>, int> f;
        int ans = 0 ; 
        
        for( int i = 0 ; i < n ; i++){
            // using in-built gcd function 
            int gcd = __gcd( numerator[i] , denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;
            
            int x,y;
            x =  numerator[i] ;
            y =  denominator[i];
            
            // here  finding 1 - x/y  to match with ex : 1/3 and 2/3 to get 1
            int z = y-x;
            
            if( f.count({z,y}))
                ans += f[{z,y}];  // frequency
                
            ++f[{numerator[i] , denominator[i]}];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends