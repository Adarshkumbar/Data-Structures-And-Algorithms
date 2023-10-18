//                          Check if Linked List is Palindrome
//  medium
/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
*/
//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    
    Node * getMidNode( Node * &head){
        long long count = 0;
        
        Node * temp = head;
        
        while( temp != NULL){
            count++;
            temp = temp ->next;
        }
       
        if( count % 2 == 0)
            count--;
    //  Now traverse till mid 
        Node * mid = head; 
        for( int i = 0 ; i < (count / 2) ; i++){
            mid = mid -> next;
        }
        return mid;
        
        //  or use 2 ptr approach
        //  Node * slow = head;
        //  Node * fast = head -> next;
        //  while( fast != NULL && fast -> next != NULL){
            // {
                // fast = fast -> next -> next;
                // slow = slow -> next ;
            // } return slow
        }
    }
    
    void reverseList( Node * &head , Node * & mid){
        if( mid == NULL)
            return ;
        Node * prev = NULL;
        Node * cur = mid -> next ;
        Node * next = NULL;
        
        
        while( cur != NULL){
            next = cur -> next;
            cur -> next = prev;
            
            prev = cur ;
            cur = next ;
        }
        mid -> next = prev;
    }
    
    bool chekPalindrome( Node *head ,Node * mid ){
        Node * temp1 = head;
        Node * temp2 = mid -> next;
        
        while( temp2 != NULL ){
            if( temp1 -> data != temp2 -> data)
                return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if( head ->next == NULL)
            return true;
        if( head -> next ->next ==NULL){
            if( head -> data == head -> next -> data)
                return 1;
            else
                return 0;
        }
        
        
        //  Step 1 get mid //  this gets mid node from list
        Node * mid = getMidNode(head);
        
        //  Step 2 reverse List after mid
        reverseList( head ,mid );
        
        // Step 3  compare and get result
        bool check = chekPalindrome( head , mid );
        
        // Step 4 --- reverse back to get original LIst Back
        reverseList( head , mid -> next );
        return check;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends