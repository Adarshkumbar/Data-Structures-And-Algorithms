#include<iostream>
using namespace std;

class Node{
    public:
        Node * left ;
        Node * right ;
        int data ;
    Node(int data ){
        this ->data = data;
        this ->left = NULL;
        this ->right = NULL;
    }
    ~Node(){
        int val = this -> data;
        if( this ->right != NULL){
            delete right;
            this->right = NULL;
        }
        cout<<" \n "<<val <<" has been deleted"<<endl;
    }
};
// ------------------------------------------------- INSERTION ---------------------------------------------------------------
void insertAtBeg( Node * &head , Node * &tail , int data ){
    if( head == NULL){
        Node * newNode = new Node( data );
        head = tail = newNode;
    }
    else{
        Node * newNode = new Node(data);
        newNode ->right = head;
        head -> left = newNode;
        head = newNode;
    }
}
void insertAtEnd( Node * &head , Node * &tail , int data ){
    if( head == NULL){
        Node * newNode = new Node( data );
        head = tail = newNode;
    }
    else{
        Node * newNode = new Node( data );
        tail -> right = newNode ;
        newNode ->left = tail;
        tail = newNode;
    }
}
void insertAtPosition(Node * &head , Node * &tail , int data , int posi ){
     if( head == NULL){
        Node * newNode = new Node( data );
        head = tail = newNode;
        return;
    }
    if( posi == 1){
        insertAtBeg(head, tail , data);
        return ;
    }
    Node * newNode = new Node(data);
    //  for traversal
    Node * temp = head;
    int cnt = 1;
    while(cnt < posi - 1){
        temp = temp ->right;
        cnt++;
    }
    //  checking if we need to insert at end
    if( temp ->right == NULL){
        insertAtEnd( head , tail , data);
        return;
    }
    newNode ->right = temp ->right;
    newNode ->left = temp;
    temp ->right->left = newNode ;
    temp->right = newNode;
}

// ------------------------------------------------- DELETION ---------------------------------------------------------------
void deleteNode( Node * &head , Node * & tail,int posi ){
    if( head == NULL)
        return ;
    if( posi == 1){
        Node * temp = head ;
        head = head -> right;
        temp ->right = NULL;
        delete temp;
        return ;
    }
    int cnt = 1 ;
    Node * cur= head;
    Node * prev = NULL;
    while( cnt < posi ){
        prev = cur;
        cur = cur->right;
        cnt++;
    }
    //  updating tail before deleting last node
    if( cur ->right == NULL){
        tail = prev;
        tail -> right = NULL;
        cur -> left = NULL ;
        delete cur;
        return;
    }
    prev -> right = cur -> right;
    cur ->right ->left = prev;
    cur -> left = cur -> right = NULL;
    delete cur;
}
// ------------------------------------REVERSE ---------------------------------------------------------

Node * reverseList( Node * head){
    // BASE CASE
    if( head->right == NULL ){
        return head;
    }
    //  revursive call to rev and return head of that rev list
    Node * smallHead = reverseList(head->right);
    //  updating small lists last node
    head ->right -> right = head;
    head->left = head ->right;
    head ->right = NULL;
   
   return smallHead;
}

void Print( Node * & head)
{
    Node * temp = head;

    while( temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->right;
    }
    cout<<"\n";
}
int main(){
    Node * head = NULL;
    Node * tail = NULL;
//  INSERT AT BEGINNING
    insertAtBeg(head , tail , 10);
    insertAtBeg(head , tail , 20);
    insertAtBeg(head , tail , 30);
    Print(head);
    cout<<" \n";

// INSERT AT END

    // insertAtEnd(head , tail , 550);
    // insertAtEnd(head , tail , 660);
    // cout<<" tail is : "<< tail->data << endl;
    // Print(head);

// INSERT AT POSITION
    // insertAtPosition(head, tail , 1111, 6);
    // Print(head);
    insertAtPosition(head, tail , 1, 1);        // 1st posi
    Print(head);
    insertAtPosition(head, tail , 1111, 5);   //last posi
    Print(head);
      insertAtPosition(head, tail , 69, 3);   //middle
    Print(head);
    // cout<<"head is :"<< head->data;

//------------------- cout<<" AFTER DELETE "<< endl;---------------------------
/*
    //  deleting tail
    deleteNode(head, tail , 6);
    Print(head);
    cout<<"\n Tail : "<< tail -> data;

    //  deleting head
    deleteNode(head, tail , 1);
    Print(head);

    //  deleting in between
    deleteNode(head, tail , 3);
    Print(head);
*/ 
//      REVERSING LINKED LIST
    head = reverseList(head);
    Print(head);
}