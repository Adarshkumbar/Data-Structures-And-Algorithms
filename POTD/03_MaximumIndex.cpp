//                  Maximum Index (IMP)
// Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].
/*
Example 1:
Input:
    n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}

Output: 6
         
Explanation: 
In the given array arr[1] < arr[7]  satisfying 
the required condition (arr[i] <= arr[j])  thus 
giving the maximum difference of j - i which is
6(7-1). */

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        //  creating left and right arrays 
    int left[n];  // stores min emts from left to right
    int right[n]; // stores max emts from right to left 
     
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    //   loop till all min emts are arranged in left array
        for( int i = 1 ; i < n ; i++)
        {
            left[i] = min( arr[i] , left[i-1]);
        }
     //   loop till all max emts are arranged in right array    
        for( int j = n-2 ; j >= 0 ; j--)
        {
            right[j] = max( arr[j] , right[j+1]);
        }
        
        // check for maxIndex
        int i = 0, j = 0 , ans = INT_MIN;
        while( i < n && j < n)
        {
            if( left[i] <= right[j])  
            {
                ans = max( j-i , ans);
                j++ ;   // so that we find next max emt greater than left[i]
            }
            else 
                i++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
