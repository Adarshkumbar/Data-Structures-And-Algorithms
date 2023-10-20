#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
    Node( int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int data = this -> data;
        if( this -> next != NULL){
            delete next ;
            this ->next = NULL;
        }
        cout<<endl<<data<<" has been deleted"<<endl;
    }
};

Node * top = NULL ; // creating top globally which represents TOP of STACK
//  ------------------------------------------------------  1   ----------------------------------------------------------------
void push( int data ){

    //  creating newNode for every emt
    Node * newNode = new Node ( data);
    if( top == NULL)
    {
        top = newNode ;
        return ;
    }
    newNode -> next = top ;
    top = newNode ;
}
//  ------------------------------------------------------  2  ----------------------------------------------------------------
void pop(){
    if( top == NULL){
        cout<<" Stack UnderFlow"<<endl;
    }
    else{
        Node * nodeToDelete = top ;
        top = top -> next;
        nodeToDelete -> next = NULL;
        delete nodeToDelete;
    }
}
//  ------------------------------------------------------  3   ----------------------------------------------------------------
void peek(){
    if( top ==NULL)
        cout<<"\nStack is Empty"<<endl;
    else
        cout<<"\nTop emt is : "<<top -> data;
}
//  ------------------------------------------------------  4   ----------------------------------------------------------------
bool isEmpty(){
    if( top == NULL)
        return true;
    return false;
}
int main(){
    cout<<isEmpty()<<endl;
    peek();
    push(10);
    push(20);
    push(30);

    peek();

    pop();
    pop();
    peek();
    cout<<endl<<isEmpty()<<endl;  
}