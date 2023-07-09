//  Find triplets with zero sum
/*
Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

Note: Return 1, if there is at least one triplet following the condition else return 0.

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
Example 2:

Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists. 

*/
//  2 pointer appreach is used 
 bool findTriplets(int arr[], int n)
    { 
        int sum = 0;
        sort(arr,arr+n);
        for( int i = 0 ; i < n - 1 ; i++){
            
            int j = i+1 ;
            int k = n-1 ; 
            while( j < k){
                if( arr[i] + arr[j] + arr[k] == 0)
                    return true ;
                else if ( arr[i] + arr[j] + arr[k] < 0)
                    j++;
                else
                    k--;
            }
        }
       return false;
    }