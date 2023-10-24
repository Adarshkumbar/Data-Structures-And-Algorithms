//                                  Next Greater Element
// medium
/*
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
Example 2:

Input: 
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1 , for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.
*/

// approach ;
    //  1. loop from n-1 to 0 and "curr" = arr[i] .... i.e from last to 1st
    //  2. create stack and push -1 cuz last emt will have -1 as larger emt
    //  3. create ans vector with n size
    //  4. for each iteration check if curr < stk.top() ..... cuz we need larger emt
    //      yes-> ans[i] = stk.top() ; stk.push(curr);
    //      no -> pop stack till curr > stk.top() or stk.top( ) == -1 after loop  ans[i] = stk.top() ; stk.push(curr);
    // 5 . return ans

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans(n);
        stack< long long > stk;
        stk.push(-1);
        
        for( int i = n -1 ; i >= 0 ; i--){
            long long  ele = arr[i];
            if( ele < stk.top()){
                // ans.push_back(stk.top());
                ans[i] = stk.top();
                stk.push( ele);
            }
            else{
                while( (stk.top() != -1) && ele >= stk.top() ){
                    stk.pop();
                }
                // ans.push_back(stk.top());
                ans[i] = stk.top();
                stk.push(ele);
            }
        }
        // reverse( ans.begin() , ans.end());
        return ans;
    }
};

int main()
{
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    
	return 0;
}