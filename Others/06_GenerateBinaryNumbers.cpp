//                      Generate Binary Numbers
// easy
/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2
Output: 
1 10
Explanation: 
Binary numbers from
1 to 2 are 1 and 10.

Example 2:

Input:
N = 5
Output: 
1 10 11 100 101
Explanation: 
Binary numbers from
1 to 5 are 1 , 10 , 11 , 100 and 101.
*/

#include<bits/stdc++.h>
using namespace std;


//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> ans;
	for(int i = 1 ; i <= N ; i++){
	    string temp ="" ; // this is created for every number for 1 to N
	    
	    int num = i;
	    while(num > 0){
	        if( num & 1 == 1) // set bit
	            temp.push_back('1');
	        else
	            temp.push_back('0');
	        //divide the number
	        num /= 2;
	    }
	   //  since itll be in reverse order we revrse it
	   reverse(temp.begin(), temp.end());
	   ans.push_back(temp);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<string> ans = generate(n);
	for(auto it:ans) cout<<it<<" ";
	cout<<endl;
	return 0;
}
