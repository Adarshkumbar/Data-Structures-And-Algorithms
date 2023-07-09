// Smallest Positive missing number

/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
*/
//  logic used created temp 10^6 array. with 0's and stores index as value of each given arry emts as 1
// ex: if arr[i] = 10 we store like temp[arr[i]] = 1. i.e temp[10]as 1
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
    // since -10^6 <= arr[i] <= 10^6
       int temp[1000002] = {0};  // created this array
        for(int i = 0 ; i < n ; i++){
            
          if( arr[i] >= 1)
                temp[arr[i]] = 1;  // store 1 in correct index i.e 7 for 7 1 for 1 etc
        }
        
        for(int i = 1 ; i < 1000003 ; i++ ){
            if(temp[i] == 0)
                return i;
        }
    } 
};