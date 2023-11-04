//                              Remove duplicate elements from sorted Array
//easy
/*
Given a sorted array A[] of size N, delete all the duplicated elements from A[]. 
Modify the array such that if there are X distinct elements in it then the first X positions 
of the array should be filled with them in increasing order and return the number of distinct elements in the array.

N = 5
Array = {2, 2, 2, 2, 2}
Output: 2

N = 4
Array = {1, 2, 2, 4}
Output: 1 2 4
*/
    int remove_duplicate(int arr[],int n){
        int j = 0 ; // this keeps track of unique emt till new unique emt comes in
        
        for( int i = 0 ; i < n-1 ; i ++){
            if( arr[i] != arr[i+1] )
                arr[j++] = arr[i];
        }
        //  last emt is being stored 
        arr[j++] = arr[n-1];
        return j;
    }