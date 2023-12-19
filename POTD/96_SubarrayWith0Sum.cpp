//              Subarray with 0 sum
//  meidum
/*
Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false 
depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.

Example 2:

Input:
n = 5
arr = {4,2,0,1,6}
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //  logic : if a number is  repeated after sum then sub array is present whose sum is 0 
        //  ex : 4 , 2 , -3 , 1 ,6
        // sum : 4,  6 ,  3,  4, 6 --> here 4  is repeated  so true 
        
        unordered_set< int>s ; 
        int sum = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            
            // if sum becomes 0 then obv true
            if( sum == 0 )
                return true;
            //  checking if its present or nah/
            if( s.find(sum) != s.end()){
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
    
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}