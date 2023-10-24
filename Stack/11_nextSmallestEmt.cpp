//                          Help Classmates
// medium -- if used loops O(n^2)
//  using stack so O(n)

/*
Professor X wants his students to help each other in the chemistry lab. He suggests that every student should help out a classmate who scored less marks than him in chemistry and whose roll number appears after him. But the students are lazy and they don't want to search too far. They each pick the first roll number after them that fits the criteria. Find the marks of the classmate that each student picks.
Note: one student may be selected by multiple classmates.

Example 1:

Input: N = 5, arr[] = {3, 8, 5, 2, 25}
Output: 2 5 2 -1 -1
Explanation: 
1. Roll number 1 has 3 marks. The first person 
who has less marks than him is roll number 4, 
who has 2 marks.
2. Roll number 2 has 8 marks, he helps student 
with 5 marks.
3. Roll number 3 has 5 marks, he helps student 
with 2 marks.
4. Roll number 4 and 5 can not pick anyone as 
no student with higher roll number has lesser 
marks than them. This is denoted by -1.
Output shows the marks of the weaker student that 
each roll number helps in order. ie- 2,5,2,-1,-1

Example 2:

Input: N = 4, a[] = {1, 2, 3, 4}
Output: -1 -1 -1 -1 
Explanation: As the marks ars in increasing order. 
None of the students can find a classmate who has 
a higher roll number and less marks than them.
*/

// approach ;
    //  1. loop from n-1 to 0 and "curr" = arr[i] .... i.e from last to 1st
    //  2. create stack and push -1 cuz last emt will have -1 as small emt
    //  3. create ans vector with n size
    //  4. for each iteration check if curr > stk.top() ..... cuz we need smaller emt
    //      yes-> ans[i] = stk.top() ; stk.push(curr);
    //      no -> pop stack till curr < stk.top() or stk.top( ) == -1 after loop  ans[i] = stk.top() ; stk.push(curr);
    // 5 . return ans
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
    //    creating stack to store smallest emts till that point
        stack <int > stk;
        vector< int > ans(n);  
        
        stk.push(-1); // since we gonna traverse from right side of arr last emt wont have any
        //  emt to compare so -1 will be always true
        
        for( int i = n-1 ; i >= 0 ; i--){ // traverse from right side of ARR
            int curr = arr[i]; // current emt
            
            if( !stk.empty() && stk.top() < curr){
                ans[i] = stk.top();
                //  pushing the emt to stack
                stk.push( curr );
            }
            else{  // when top emt if greater than curr we need to find smaller emt from STACK
                while( !stk.empty() && stk.top() >= curr){
                    stk.pop() ; // keep on popptin emt from stk
                }
                //  now stk.top() <= curr
                ans[i] = stk.top();
                //  pushing the emt to stack
                stk.push( curr );
            }
        }
        return ans;
    } 
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

