//              Finding middle element in a linked list
// easy
/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.
Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/

//-------------------------------------------- APPROACH - 1----------------------------------------------------------------- 
    int getLen(Node * head){
        int cnt = 0;
        Node * temp = head;
        while( temp != NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    
    int getMiddle(Node *head)
    {
        if( head ->next == NULL)
            return head->data;
        int mid = getLen(head) / 2;
        int cnt = 0;
        
        Node * temp = head;
        while( cnt < mid){
            temp = temp->next;
            cnt++;
        }
        return temp->data;
    }
//-------------------------------------------- APPROACH - 2-----------------------------------------------------------------     
    int getMid( Node * head){
        //  if list empty
        if(  head == NULL )
            return -1;
        //  only one node in list
        if(head -> next == NULL)    
            return head->data;
        //  2 Nodes present in list
        if( head -> next ->next ==NULL)
            return head->next->data;
        //  we keeping 2 ptrs one moves 2x other moves 1x 
        //  so if 2x reach null then 1x reaches middle ... thats what we return
        Node * fast = head ->next;
        Node * slow = head;

        while( fast != NULL){
            fast = fast ->next;
            //  check of already reached null .. if no then move fast
            if( fast != NULL)
                fast = fast ->next;
            slow = slow ->next;
        }
        return slow ->data;
    }
};


//{ Driver Code Starts.

int main() {
    //code
        cout<<"Enter N:";
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout <<"apr 1 -> Middle element is : "<<ob.getMiddle(head) << endl;
        cout <<"apr 2 -> Middle element is : "<<ob.getMid(head) << endl;
    return 0;
}

// } Driver Code Ends