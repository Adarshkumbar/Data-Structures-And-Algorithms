// Find duplicates in an array
/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array. Return the answer in ascending order.

Note: The extra space is only for the array to be returned.
Try and perform all operations within the provided array. 

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> v; // used to store duplicate emts
        unordered_map<int , int > s; // unorderd set works like hashmap i.e key(emt) - value ( frequency of emt)
        for( int i = 0 ; i < n ; i ++){
            int emt = arr[i]; // each emt stored here for hash maping
            s[emt]++;    // increment no.of occurances of an emt
        }
        unordered_map<int , int >:: iterator it;
        for( it = s.begin(); it != s.end() ; it++){
            if( it->second > 1)
               v.push_back(it->first);
        }
       if( v.empty())
            v.push_back(-1);
        sort( v.begin(),v.end());
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends