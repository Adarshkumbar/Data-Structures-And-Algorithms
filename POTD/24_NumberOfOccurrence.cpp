//                  NumberOfOccurrence
/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int s = 0, e = n - 1 ,l = 0 , r = 0;
	    
	   //  start , end and l and r are start and end posi no of X 
	   int mid = (s+e)/2;
	   while( s <= e ){
	       if( arr[mid] == x){
	           l = mid ;
	           r = mid ;
	           while( arr[l] == x || arr[r] == x){
	               if( arr[l] == x)
	                    l--;
                   if( arr[r] == x)
	                    r++;
	           }
	           int ans = r - l - 1;
	           return ans;
	       }
	       else if( arr[mid] > x){
	           e = mid - 1 ;
	       }
	       else
	           s = mid + 1;
	           mid = (s+e)/2;
	   }
	   return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends