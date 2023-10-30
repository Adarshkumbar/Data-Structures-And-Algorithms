//                          Sum of XOR of all pairs
//  medium
/*
Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

Example 1:

Input : arr[ ] = {7, 3, 5}
Output : 12
Explanation:
All possible pairs and there Xor
Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
 + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
Example 2:

Input : arr[ ] = {5, 9, 7, 6} 
Output :  47
Explanation:
All possible pairs and there Xor
Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
 + (5 ^ 6 = 3) + (9 ^ 7 = 14)
 + (9 ^ 6 = 15) + (7 ^ 6 = 1)
 = 12 + 2 + 3 + 14 + 15 + 1 = 47
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long long int ans = 0 ;
    	
    // 	 we are doin 7, 3, 5 ->(int bit)posi 3 2 1 0
    //                                      ----------
    //                                       0 1 1 1 
    //                                       0 0 1 1
    //                                       0 1 0 1
    //   counting 0's and 1 at each bit     ---------
    //   0th posi 0's = 0,  1's = 3 .. multiply 0's and 1's 0 * 3 = 0
    //   1st posi 0's = 1,  1's = 2 .. 1 * 2 = 2 and value of 1st posi = 2^1 so 2 * 2
    //   2nd posi 0's = 1,  1's = 2 .. 1 * 2 = 2 and value of 1st posi = 2^2 so 2 * 4
    //   2nd posi 0's = 3,  1's = 0 .. 3 * 0 = 0 and value of 1st posi = 2^2 so 0
    //  for every bit posi we add sum we got in ans ..
        
        for(int i = 0 ; i < 32 ; i++)// for 32 bits
        {   
            long long  zeroCnt = 0 , oneCnt = 0; // cnt for each bit as sh0wn above
            for( int j = 0 ; j < n ; j++){// running for every number in arr
                //  findin bit if 0 or 1
                if( arr[j] % 2 == 0 )
                    zeroCnt++;    
                else
                    oneCnt++;
                
                //  now dividing jth number by 2 cuz ...8 -> 4 -> 2 - > 1 to get nexxt bit value
                arr[j] /=2;
            }
            //  once we get 0's and 1's cnt of ith bit for every emt of arr  we get ans for ith bit
                ans += (zeroCnt * oneCnt )* ( 1 << i)  ;
        }
         return ans;
    }
};
int main()
{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	return 0;
}