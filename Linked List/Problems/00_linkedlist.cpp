#include<iostream>
using namespace std;
#include<map>
class Node{
    public:
        int data;
        Node * next ;
  
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
        //  to free the memory
        ~Node(){
            int val = this->data;
            if( this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<< " The Node with values "<< val <<" is Deleted"<<endl;
        }
};
// ------------------------------------------------ INSERTION ------------------------------------------------------------------
// INSERT AT BEGINNING   
void insertAtBeg( Node * & head, int data){
    Node * newNode = new Node(data);
    newNode ->next = head;
    head = newNode;
}
//  INSERT AT ENDs
void insertAtEnd( Node * &tail, int data ){
     Node * newNode = new Node(data);
     tail -> next = newNode ; 
     tail = tail->next;
}
//  INSERT AT POSI
void insertAtPosi(Node * & head , int data , int posi){
    if( posi == 1){
         insertAtBeg(head, data);
         return;
    }
       

    //  traverse to the posi
    int cnt = 1 ;
    Node * temp = head;

    while( cnt < posi-1){
        temp = temp->next;
        cnt++;
    }
    // if traversed to last node which is insertAtEnd
    if( temp->next == NULL){
        insertAtEnd(temp , data);
        return;  // return from func cuz below code will add data again
    }

    Node * nodeToInsert = new Node(data);
    nodeToInsert ->next = temp->next;
    temp ->next = nodeToInsert;
}

// ------------------------------------------------ DELETION ------------------------------------------------------------------
void deleteNode( Node * &head , int posi , Node * &tail){
    if( posi == 1){
        Node * temp = head; 
        head = head ->next ;
        // free memory
        temp -> next = NULL;
        delete temp;
    }
    else{
        int cnt = 1 ;
        Node * cur = head;
        Node * prev = NULL;

        while( cnt < posi){
            prev = cur ;
            cur = cur ->next;
            cnt++;
        }
        if( cur->next == NULL){
           tail = prev;
        }
        prev ->next = cur ->next;
        cur ->next = NULL;
        delete cur;
    }
}
// ----------------------------------------- Check loop ----------------------------------------------------------------
// APPROACH - 1
bool checkLoop(Node * head){
    if( head == NULL)
        return false;
    Node * temp = head;
    //  keeping map to keep track of visited Nodes

    map < Node * , bool> visited;

    while( temp != NULL){
        if( visited[temp] == true)
            return true;
        visited[temp] = true;   // marking node true
        temp = temp ->next;
    }
    return false;
}
// APPROACH - 2 
Node * floyd (Node * head){
    if( head == NULL)
        return head;
    Node * fast = head;
    Node * slow = head;

    while( fast != NULL && slow != NULL){
        fast = fast -> next ;        // 1x 
        if( fast != NULL)           //  2x
            fast = fast ->next ;
        slow = slow ->next ;         // 1x for slow

        if( fast == slow)
            return slow;
    }
    return NULL;
}
// ----------------------------------------- Remove DUPLICATE IN UNSORTED LIST --------------------------------------------------

void removeDuplicate( Node *&head){
    if ( head == NULL)
        return ;
    Node * cur = head;
    Node * temp = head -> next;

    while( cur != NULL){
        while( temp != NULL)
        {
            if( temp == NULL && cur -> next != NULL )
                temp = cur -> next;
            if( temp -> data == cur -> data ){
                Node * toDel = temp;
                temp = temp -> next;
                toDel ->next = NULL;
                delete toDel;
                if( cur -> next == NULL)
                    cur ->next = temp;
                continue;
            }
            temp = temp -> next;
        }
        if( cur ->next == NULL)
            return ;
        cur = cur ->next;
    }
}

void Print(Node * &head){
    Node * temp = head ;
    while( temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}
int main(){
    Node *newNode = new Node(10);
    Node *head = newNode;
    Node *tail = newNode ;

//  INSERT AT BEGINNING   
//     insertAtBeg(head,20);
//     insertAtBeg(head,30);
    // Print(head);
    
//  INSERT AT END
    insertAtEnd( tail , 20);
    insertAtEnd( tail , 10);
    Print(head);
//  INSERT AT POSI
    insertAtPosi(head,40 , 1);
    // Print(head);
    cout<<"\nAFTER DELETE\n";
    deleteNode( head , 3 , tail); // tail passed to update if last node deleted
    Print(head);
    cout<<" TAIL IS :" << tail ->data;

    //  CHECK FOR LOOP
    (checkLoop( head)) ? cout <<"\nLOOP IS PRESENT \n" : cout<<"\nLOOP  ABSENT \n";
  
    (floyd( tail)) ? cout <<"\nLOOP IS PRESENT \n" : cout<<"\nLOOP  ABSENT \n";

    removeDuplicate(head);
    Print( head);
}