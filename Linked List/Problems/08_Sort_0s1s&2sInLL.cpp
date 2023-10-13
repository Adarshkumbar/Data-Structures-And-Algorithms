//  Given a linked list of 0s, 1s and 2s, sort it.
//  easy
/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{ 
    public:
    
    // ---------------------------------------------      For  Apporach 2         ----------------------------------------------
    void insertAtTail( Node *  cur , Node * & tail){       // works for 0,1 and 2's list
        tail-> next = cur ;
        tail = cur ;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
    // ----------------------------------------------   Apporach 1   -----------------------------------------------
        /*   // This approach overrites already present data 
        //  just count number of 0's , 1's and 2's 
        //  and go on replacing already present data in LL till these counts become 0
        
        
        if( head == NULL)
            return head;
        
        int zeroCnt = 0;
        int oneCnt  = 0 ;
        int twoCnt = 0 ; 
        
        Node * temp = head;
        
        //  Counting number of 0 , 1 and 2 's
        while( temp != NULL){
            if( temp -> data == 0)
                zeroCnt++;
                
            if( temp -> data == 1)
                oneCnt++;
                
            if( temp -> data == 2)
                twoCnt++;
                
            temp = temp -> next ;
        }
        //   Now go one replacing zeroCnt 0's , oneCnt 1's etc ....
        
        temp = head; // reallocating temp to head cuz it was null earlier loop
        
        while( temp != NULL){
            if( zeroCnt > 0)
            { 
                temp -> data = 0;
                zeroCnt --;
                temp = temp -> next;
                continue ;
            }
            if( oneCnt > 0)
            { 
                temp -> data = 1;
                oneCnt --;
                temp = temp -> next;
                continue ;
            }
               if( twoCnt > 0)
            { 
                temp -> data = 2;
                twoCnt --;
                temp = temp -> next;
                continue ;
            }
        }
        return head;
        */ 
// --------------------------------------------     Apporach 2   ---------------------------------------------
    //  
    //  This approach doesn't overrite already present data 
    
    // In this appreoach we create 3 linked list and merge the
    //  create 3 heads and 3 tails for 0,1 and 2 and point tail of 1 to 2 to 3 -> NULL
    
    //  we create dummy data first to avoid complications
    if( head == NULL)
        return head;
        
    Node * zeroHead = new Node( -1 ); 
    Node * zeroTail = zeroHead;     // initially both head and tail point to dummy data
    
    Node * oneHead = new Node( -1 ); 
    Node * oneTail = oneHead;  
    
    Node * twoHead = new Node( -1 ); 
    Node * twoTail = twoHead;  
    
    Node * cur = head; // this is used to traverse the list
    
    while( cur != NULL){
        int val = cur -> data ;
        if( val == 0){      // inserting cur at zeroTail
            insertAtTail( cur , zeroTail);
        }
        
        if( val == 1){      // inserting cur at oneTail
            insertAtTail( cur , oneTail);
        }
        
        if( val == 2){      // inserting cur at twoTail
            insertAtTail( cur , twoTail);
        }
        cur = cur ->next;
    }
    //  after all linked lists have been formed we just merge them
    
    //  merging 3 linked lists
       
       if( oneHead->next != NULL)  // means one list present
       {
            zeroTail -> next = oneHead ->next ;   //  oneHead ->next cuz 1st Node is dummy
            zeroTail  = oneHead ->next ;
       }
       else{  // means one list is empty
            // so adding 2's list to zero's tail
            zeroTail -> next = twoHead -> next ;// twoHead -> next cuz 1st Node is dummy
            zeroTail  = twoHead -> next ;
       }
        // if one's list was present then  we need to add 2's list to oneTail cuz of above condition
        oneTail -> next = twoHead -> next ;
        twoTail -> next = NULL;  // cuz this will be last node 
        
        //  now Pointing head to the new list 
        
        head = zeroHead -> next ;
        
        // we need to delete the taken dummy nodes
        
        zeroHead -> next = NULL;
        delete zeroHead;
        
        oneHead -> next = NULL;
        delete oneHead;
        
        twoHead -> next = NULL;
        delete twoHead;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    return 0;
}
// } Driver Code Ends