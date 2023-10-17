//                                  Add two numbers represented by linked lists
//  medium

/*
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
*/
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    void reverseList( Node * & head){
        if( head == NULL)
            return;
        Node * prev = NULL;
        Node * cur = head;
        Node * next = NULL;
        
        while( cur != NULL){
            next = cur -> next;
            cur -> next = prev;
                
            prev = cur ;
            cur = next ;
        }
        head = prev ;
    }
    void insertAtTail( Node * & head , Node * &tail , int digit ){
          //  creating newNode to put it in ans list;
        Node * newNode = new Node( digit ); 
        if( head == NULL){
            head =  newNode ;
            tail = head ;
            return ;
        }
        tail -> next = newNode ;
        tail = newNode;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int carry = 0;
        //  step 1 -- reverse both lists
        reverseList( first );
        reverseList( second );
        
        Node * ansHead = NULL ;
        Node * ansTail = NULL ;
        while( first!= NULL || second != NULL || carry > 0 ){
            int val1 = 0;
            if( first != NULL) // if first is not null then taking value from it
                val1 = first -> data;
            
            int val2 = 0;
            if( second != NULL) // if first is not null then taking value from it
                val2 = second -> data;
            
            int sum = val1 + val2 + carry;
            
            //  now getting digit to put in new list
            int digit = sum % 10;
            //  not getting carry to add to next node/ number
            carry = sum / 10;
            
          // this function updates ans List 
            insertAtTail ( ansHead , ansTail , digit );
            
            //  moving ptrs
            if( first != NULL)
                first = first -> next ;
            if( second != NULL) 
                second = second -> next ;
        }
        // since ans list is in reverse orderd ... we need to reverse it
        reverseList( ansHead );
        return ansHead; 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends