//                          Min sum formed by digits
//  easy
/*
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array.
All digits of the given array must be used to form the two numbers.
Any combination of digits may be used to form the two numbers to be summed.  Leading zeroes are permitted.
If forming two numbers is impossible (i.e. when n==0) then the "sum" is the value of the only number that can be formed.

Example 1:

Input:
N = 6
arr[] = {6, 8, 4, 5, 2, 3}
Output:
604
Explanation:
The minimum sum is formed by numbers 
358 and 246

Example 2:

Input:
N = 5
arr[] = {5, 3, 0, 7, 4}
Output:
82
Explanation:
The minimum sum is formed by numbers 
35 and 047
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int minSum(int arr[], int n)
    { 
    //  solving using queue
    
        if( n == 1)
            return arr[0];
            
        long long int n1 = 1 ;
        long long int  n2 = 1 ;
        queue<int> q;
        
    //  step - 1 sort arr
        sort( arr , arr+ n);
        
    //  step - 2 push emts in queue
        for( int i = 0 ; i < n ; i++){
            q.push(arr[i]);
        }
        
    //  step -3 now keep on popping for num1 and num2 till queue is empty
    
        n1 = q.front();
        q.pop();
        
        n2 = q.front();
        q.pop();
        
        while( !q.empty()){
            n1 = n1 * 10 + q.front();
            q.pop();
            
            if( !q.empty()){
                 n2 = n2 * 10 + q.front();
            q.pop();
            }
        }
        return n1 + n2;
    }
};

int main()
{

    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution ob;
    cout<<ob.minSum(arr, n)<<endl;

    return 0;
}