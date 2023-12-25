// Count More than n/k Occurences
// easy - just use map and loop thru it 
/*
Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more 
than n/k times.

Example 1:

Input:
N = 8
arr = [3,1,2,2,1,2,3,3]
k = 4
Output: 
2
Explanation: 
In the given array, 3 and 2 are the only elements that appears more than n/k times.

Example 2:

Input:
N = 4
arr = [2,3,3,2]
k = 3
Output: 
2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map < int , int > m;
    //    map to cnt occurance of emt 
        int cnt = 0 ;
        for(int i = 0 ; i< n ; i++){
            m[arr[i]]++;
        }
        //  looping thru map 
        for(auto it : m){
            if(it.second > n/k)
                cnt++;
        }
        return cnt;
    }
};

int main() {
   
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.countOccurence(arr, n, k) << endl;

    return 0;
}