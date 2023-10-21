//                  Sort a stack
//  medium  -- using recursion
/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/


#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}



// ------------------------------------ STEP - 2 ------------------------------------------
void sortedInsert( stack <int> &s , int emt){
    //  recursive method
    
//  BASE CASE
    if( s.empty()){
       s.push(emt);
       return;
    }
    
    //  storing top emt and popping from stk
    
    
    int topEmt = s.top();
    if( topEmt <= emt){
        s.push(emt);
        return;
    }
    s.pop();
    
    // recursive call
    sortedInsert( s , emt );
    s.push( topEmt );
}

// ------------------------------------ STEP - 1 ------------------------------------------
void SortedStack :: sort()
{
    //   using RECURSION
    //  BASE CASE
    if( s.empty())
        return ;
    //  Storing value
    int emt = s.top();
    s.pop();
    // recursive call
    SortedStack :: sort();
    
    // inserting emt at sorted posi
    sortedInsert( s , emt );
    
}