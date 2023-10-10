//                          Reverse Linked List Using RECURSION
//  easy


#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

*/

class Solution
{
// APRROACH 1
/*
    void Solve( Node * &head , Node * prev , Node * cur){
        //  Base case
        if( cur == NULL){
            head = prev;
            return;
        }
        //  To Store the List
        Node * forward = cur ->next;
        //  recursive call
        Solve( head,cur , forward );
        cur ->next = prev;
    }   
*/
// APRROACH 2
        Node * Solve( Node * head){
        //  Base case
        if( head == NULL || head -> next == NULL){
            return head;
        }
        //  SmallHead will be head of small list which is reversed by recursion
        Node * smallHead = Solve ( head ->next); 
        //  solving one condi rest solved by recursion
        head ->next ->next = head;
        head ->next = NULL;
        return smallHead;
    }   

    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node * cur = head;
        Node *prev =NULL;

 // for 1st approach
        // Solve( head, prev, cur);  
        // return head;

//  for 2nd approach
        return Solve(head);
    }
    
};
    

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}


int main()
{
    int n,l,firstdata;
  

        struct Node *head = NULL,  *tail = NULL;
    cout<<" Enter n : ";
        cin>>n;
        
        if(n!=0)
        { cout<<"Enter 1st emt :"<<endl;
            cin>>firstdata;
            head = new Node(firstdata);
            tail = head;
        }
        
        for (int i=1; i<n; i++)
        {
            cout<<"Enter "<< i+1<<"th emt :"<<endl;
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    
    return 0;
}
