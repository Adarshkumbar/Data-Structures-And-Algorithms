// Merge two sorted linked lists
//  meadium
//  1)1st check which lists 1st emt is larger 
//  2)then......go on cheking is larger lists emt lies withing cur and next of smaller list .....
//  3)if  exists then put between those and move temp of larger list and move cur of smaller list
//  4) if not move next and cur 
//  5) even after traversal if larger list still exists point that to cur -> next = temp ;

/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
*/

//{ ------------------------------------------------------------------------v Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } ------------------------------------------------------------------------v Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// ---------------------------------------------------------- SOLUTION ----------------------------------------------------
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if( head1 == NULL)
        return head2;
    if( head2 == NULL)
        return head1;
    
    Node * prev = head1 ;
    Node * cur = head1 -> next; 
    Node * temp = head2; // to traverse 2nd list
    
    //  if list1's  1st emt is  smaller or equal to list2's 1st emt
    if( head1 -> data <= head2 -> data){
        Node * prev = head1 ;
        Node * cur = head1 -> next; 
        Node * temp = head2 ; // to traverse 2nd list
        while( cur != NULL && temp != NULL){
        if( ( temp -> data <= cur -> data) && ( temp-> data >= prev -> data ) ){
            // means we can add node btw prev and cur 
            prev -> next = temp;
            prev = temp ;
            temp = temp -> next ;
            prev ->next = cur ;
        }
        else{
            prev = cur; 
            cur = cur ->next ;
            }
        }
        if( temp != NULL)
            prev -> next = temp;
        return head1 ;  
    }
    else{
        Node * cur1 = head2 ;
        Node * next1 = head2 -> next; 
        Node * cur2 = head1 ; // to traverse 2nd list
        Node * next2 = head1 -> next;
        while( next1 != NULL && cur2 != NULL){
        if( ( cur2 -> data <= next1 -> data) && ( cur2-> data >=  cur1-> data ) ){
            // means we can add node btw prev and cur 
           cur1 -> next = cur2;
           next2 = cur2 -> next ;
           cur2 -> next = next1 ;
           
           cur1 = cur2 ;
           cur2 = next2 ;
        }
         else{
            cur1 = next1; 
            next1 = next1 ->next ;
        }
    }
    if( cur2 != NULL)
        cur1 ->next = cur2;
    return head2 ; 
    }   
}

// ---------------------------------------------------------- SOLUTION  ENDS ----------------------------------------------------