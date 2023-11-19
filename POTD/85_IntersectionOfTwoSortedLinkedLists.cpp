//                          Intersection of two sorted Linked lists
//  easy

/*
Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Example 1:

Input:
LinkedList1 = 1->2->3->4->6
LinkedList2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
LinkedList1 = 10->20->40->50
LinkedList2 = 15->40
Output: 40
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
       Node * head3 = NULL;
       Node * temp1 = head1;
       Node * temp2 = head2;
       Node * temp3 = NULL;
       
       while( temp1 != NULL && temp2 != NULL){
           
        if( temp1 ->data >   temp2 ->data ){ // l1 data greater then move l2 ptr
               temp2 = temp2 -> next;
           }
        else if( temp1 ->data <   temp2 ->data ){ // l2 data greater then move l1 ptr
               temp1 = temp1 -> next;
           }   
        else{  // means data equal need to create node and add in list3 move both lists 
            if( head3 == NULL){
                head3 = temp3 = new Node( temp1 -> data);
            }
            else{
                 temp3 -> next = new Node ( temp1 -> data);
                 temp3 = temp3 -> next;
            }
            //  move temp1 and temp2
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
           
        }
       }
       
       return head3;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}