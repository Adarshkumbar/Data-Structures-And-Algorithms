//                      Form a number divisible by 3 using array digits
// Easy
/*
You will be given an array arr of integers of length N. You can construct an integer from two integers by treating the integers as strings, and then concatenating them. For example, 19 and 4 can be used to construct 194 and 419.

The task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3.
If it is possible then print 1 and if not print 0.

Example 1:

Input: N = 3
arr = {40, 50, 90}
Output: 1
Explanation: One such number is 405090.
Example 2:

Input: N = 2
arr = {1, 4}
Output: 0
Explanation: The numbers we can form 
are 14 and 41. But neither of them are 
divisible by 3.
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        long long sum = 0;
        //  getting overall sum
        for( int i = 0 ; i < N ; i++){
            sum += arr[i];
        }
    //  getting digit sum cuz ./...... rule of multiple of 3 ...adding digits and checking if its
    // divisible by 3
        int digit = 0;
        int digitSum = 0;
        
        while( sum != 0){
            digit = sum % 10 ;      // getting digit
            sum /= 10 ;             // reducing sum
            digitSum += digit;
        }
        
        if( digitSum % 3 == 0)
            return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends