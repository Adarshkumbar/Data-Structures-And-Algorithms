//                   Check whether K-th bit is set or not 
//  easy

/*
Given a number N and a bit number K, check if Kth index bit of N is set or not. A bit is called set if it is 1. Position of set bit '1' should be indexed starting with 0 from LSB side in binary representation of the number.
Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

Example 1:

Input: 
N = 4
K = 0
Output: 
No
Explanation: 
Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Example 2:

Input: 
N = 4
K = 2
Output: 
Yes
Explanation: 
Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
Example 3:

Input: 
N = 500
K = 3
Output: 
No
Explanation: 
Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        //  we need to devide number n k times and find if its set bit or nah
        while( k > 0){      // divide till k th emt ....ex 10 -> 1010 
            n /= 2 ;
            k--;
        }
        if( n & 1)  // now last bit compared with 1 if set bit --> 1 else 0
            return true;
        return false;
    }
};

int main()
{
	    long long n;
	    cin>>n;//input n
	    int k;
	    cin>>k;//bit number k
	    Solution obj;
	    if(obj.checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;

	return 0;
}