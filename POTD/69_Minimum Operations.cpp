//                  Minimum Operations
//  easy
/*
Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

Double the number
Add one to the number
Example 1:

Input:
N = 8
Output: 4
Explanation: 
0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
Example 2:

Input: 
N = 7
Output: 5
Explanation: 
0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
*/
class Solution
{
  public:
    int minOperation(int n)
    {
        if( n == 1)
            return 1;
        int cnt = 1;
        
        while( n != 1){
            // if( n == 1)
            //     return cnt;
            if( n % 2 == 0){
               n /= 2;
            }
            else{
               n--;
           }
        //   cout<<" N: "<< n <<" && cnt =" << cnt<<endl;
           cnt++;
       }
       return cnt;
    }
};

int main()
{
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;

}