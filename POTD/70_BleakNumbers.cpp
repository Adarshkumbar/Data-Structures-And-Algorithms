//                          Bleak Numbers
//  medium
/*
Given an integer, check whether it is Bleak or not.

A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Example 1:

Input: 
4
Output: 
1
Explanation: 
There is no x such that x + countSetbit(x) = 4
Example 2:

Input: 
3
Output: 
0
Explanation: 
3 is a Bleak number as 2 + countSetBit(2) = 3
*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    int cntSetBits(int n ){
        int cnt = 0;
        while( n > 0 ){
            cnt+= n & 1; // 0111 & 0001 return 1 || if 1010 & 0001 returns 0 
            n = n /2 ; // or right shift ex 1010 (10) -> 0101 (5) -> 0010 (2)   -> 0001 (1)
            //                  set bits cnt     0       ->    1   ->      0       ->   1  = 2
        }
        return cnt ;
    }
	int is_bleak(int n)
	{ // log n * logn 
    	   for( int i = n - 30 ; i <= n ; i ++){
    	       cout<<" i + cntSetBits(i) "<< i + cntSetBits(i) << endl;
    	       if( i + cntSetBits(i) == n){
    	           return 0;
    	       }
    	        
    	   }
    	   return 1;
	}
};


//{ Driver Code Starts.
int main(){
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";

	return 0;
}
