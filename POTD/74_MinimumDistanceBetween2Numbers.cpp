//                      Minimum distance between two numbers
//  easy
/*
You are given an array a, of n elements. Find the minimum index based distance between two distinct elements of the array, x and y. Return -1, if either x or y does not exist in the array.

Example 1:

Input:
N = 4
A[] = {1,2,3,2}
x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are
two distances between x and y, which are
1 and 3 out of which the least is 1.

Example 2:

Input:
N = 7
A[] = {86,39,90,67,84,66,62}
x = 42, y = 12
Output: -1
Explanation: x = 42 and y = 12. We return
-1 as x and y don't exist in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minDist(int A[], int n, int x, int y) {
       
    //   to determine index of x or y whichever comes first
        int a = -1 ;
        int b = -1;
        int ans = INT_MAX; 
        
        for(int i = 0 ; i < n ; i++){
            if( A[i] == x){
                a = i;
                if( b != -1){
                    int temp = abs( b - a);
                    ans = min ( ans , temp);
                }
            }
            if( A[i] == y){
                b = i;
                if( a != -1){
                    int temp = abs( b - a);
                    ans = min ( ans , temp);
                }
            }
        }
        if( a== - 1 || b == -1 )
            return -1;
        return ans;
    }
};

int main() {

        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    return 0;
}