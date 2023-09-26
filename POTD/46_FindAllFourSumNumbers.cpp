//                             FindAllFourSumNumbers ( medium) O(n^3)
/*
Given an array A of integers and another number K.
 Find all the unique quadruple from the given array that sums up to K.
 Also note that all the quadruples which you return should be internally sorted, 
 ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.
 
Example 1:
Input:N = 5, K = 3A[] = {0,0,2,1,1} Output: 0 0 1 2 Explanation: Sum of 0, 0, 1, 2 is equalto K.

Example 2:
Input:N = 7, K = 23A[] = {10,2,3,4,5,7,8} Output: 2 3 8 10 2 4 7 10 3 5 7 8 

Explanation: Sum of 2, 3, 8, 10 = 23,sum of 2, 4, 7, 10 = 23 and sum of 3,5, 7, 8 = 23.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n=arr.size();
        
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n-3;i++)
        {
            //  to not include redundant data..i.e only unique
            if(i>0 and arr[i]==arr[i-1]) 
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                 //  to not include redundant data..i.e only unique
                if(j>i+1 and arr[j]==arr[j-1]) 
                    continue;
                
                //  " TWO SUM " i.e 2 ptr is applied to last 2 numbers of quadruple
                int low=j+1,high=n-1;
                
                while(low<high)
                {
                    int sum=arr[i]+arr[j]+arr[low]+arr[high];
                    
                    if(sum==k)
                    {
                        ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                        int a=arr[low],b=arr[high];
                         //  to not include redundant data..i.e only unique
                        while(low<high and a==arr[low]) low++;
                        while(low<high and b==arr[high]) high--;
                    }
                
                    else if(sum<k) 
                        low++;
                    else 
                        high--;
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends