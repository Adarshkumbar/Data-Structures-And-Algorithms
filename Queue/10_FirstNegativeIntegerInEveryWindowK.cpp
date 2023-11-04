//                        First negative integer in every window of size k
//  medium
/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) 
of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger
    (long long int A[],long long int N, long long int K) {
            
        // creating dequeue to keep track of index of 1st -ve emt 
        // treaversing till k 
        
        deque<long long int > dq;
        
        vector<long long> ans;
        
        for( int i = 0 ; i < K ; i++){
            if( A[i] < 0 )  // if -ve push index in dq
                dq.push_back(i);
        }
        
        //  filling for 1st k window
        
        if( !dq.empty() && A[dq.front()] < 0 )
                ans.push_back(A[dq.front()]);
            else
                ans.push_back(0);
        
        for(int i = K ; i < N ; i++)
        {
        // step 1 -  removal of 1 emt i.e moving window
            //  below means withing k window limit
            if( !dq.empty() && i - dq.front() >= K ){
                dq.pop_front();
            }
        // step 2 Addition of index of next -ve emt from arr if present
            if( A[i] < 0){
                dq.push_back(i);
            }
            
        // step 3 Storing ans -> i.e if -ve emt present in tha window
            if( !dq.empty() && A[dq.front()] < 0 )
                ans.push_back(A[dq.front()]);
            else
                ans.push_back(0);
        }
       return ans;                                           
 }