#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next ;
  
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};
void insertAtBeg( Node * & head, int data){
    Node * newNode = new Node(data);
    newNode ->next = head;
    head = newNode;
}
void insertAtEnd( Node * & tail, int data ){
     Node * newNode = new Node(data);
     tail -> next = newNode ; 
     tail = tail->next;
}
void Print(Node * &head){
    Node * temp ;
    while( temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}
int main(){
    Node *head = new Node(10);
    head->next = NULL;
    Node *tail = head ;
   
    
    insertAtBeg(head,20);
    insertAtBeg(head,30);
    Print(head);
    
    // insertAtEnd( tail , 20);
    // insertAtEnd( tail , 30);
    // Print(head);
}