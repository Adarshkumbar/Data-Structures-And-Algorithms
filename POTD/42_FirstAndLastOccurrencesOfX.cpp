//                  First and last occurrences of x
/*
Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.


Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    vector<int> solve(int first , int last, int arr[] , int n , int x){
        while( arr[first] == x){
            if( (first -1) >= 0 && arr[first -1 ] == x)
                first--;
            else
                break;
        }
         while( arr[last] == x){
            if( (last +1 ) < n && arr[last + 1 ] == x)
                last++;
             else
                break;
        }
       vector<int> v;
       v.push_back(first);
       v.push_back(last);
       return v;
    }
    public:
    vector<int> find(int arr[], int n , int x )
    {
       int s = 0;
       int e = n - 1;
       int first = -1; 
       int last = -1;
       int mid = s + (e - s )/2 ;
       while( s <= e ){
            if( x == arr[mid]){
                first = mid;
                last = mid;
                break;
            }
            else if( arr[mid] > x)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e - s )/2 ;
       }
       if( x == arr[mid])
            return solve( first , last , arr,n , x);
        vector<int> v(2,-1);
        // v.push_back(-1);
        // v.push_back(-1);
        return  v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends