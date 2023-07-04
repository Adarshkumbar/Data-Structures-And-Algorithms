// Count the subarrays having product less than k
/*
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

Example 1:

Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.

*/
//  logic create long long product, int subarray to  count no of sub arrays
//  run loop till i < n 

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long product = 1;  // stores large numbers
        int subArray = 0;
        int i = 0;
        int j = 0;
        while( i < n)
        {
            // finding product each iteration 
            product = product * a[i];
            if( product < k){
                
                subArray ++;
                if( i + 1 >= n){ // this condition is to check if i went out of bound 
                     i = ++j;
                     product = 1;
                }
                else 
                    i++;
            }
            // if product > k
            else{
                i = ++j;
                product = 1;
            }
        }
        return subArray ;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends