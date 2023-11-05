//                      Maximum of all subarrays of size k
//  medium
/*
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, 
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13}, 
Max = 90

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans ;
        
        // step - 1 creating deque to keep track of indices of curr max and next indices 
        deque<int> dq;
        
        //  step 2  processing till k 
        for( int i = 0 ; i < k ; i++){
            while( !dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        //  Step - 3 storing k window ans in ans vector
        if( !dq.empty()){
            ans.push_back(arr[dq.front()]);
        }
        
        //  Step - 4 Processing from k to n -1 
        
        for(int i = k ; i < n ; i++){
        
            // MOVING WINDOW
            
            //  Removal 
            if( !dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            
            //  Addition
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            //  storing ans;
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

int main() { 
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	return 0;
}