//                              Maximum sum increasing subsequence
//  medium
/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

Example 1:

Input: 
N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 
106
Explanation:
The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100},
Example 2:

Input: 
N = 4, arr[] = {4, 1, 2, 3}
Output: 
6
Explanation:
The maximum sum of a increasing sequence is obtained from {1, 2, 3}.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{ 
	    int maxSum[n];
	    maxSum[0]= arr[0];
	    int ans = maxSum[0];
	    
	    for( int i = 1 ; i < n ; i++){
	        maxSum[i] = arr[i];
	        for( int j = 0 ; j < i ; j++){
	            if( arr[i] > arr[j] && maxSum[i] < maxSum[j] + arr[i] ){
	                maxSum[i] = maxSum[j] + arr[i];
	            }
	        }
	        ans = max( ans, maxSum[i]);
	    }
	    return ans;
	}  
};
.
int main() 
{
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];
	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
    return 0;
}
