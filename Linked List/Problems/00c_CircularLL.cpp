//  In Circular LL we are Creating "SORTED LIST" by taking input "input" and 
//  emt which is already present in a list .....we place "input" after the emt
#include<iostream>
using namespace std;
#include<map>
class Node{
    public:
        int data;
        Node * next;

    Node(int data){
        this -> data = data;
        this ->next = NULL;
    }
    ~Node(){
        int val = this ->data;
        if( this-> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<< "\nvalue : "<< val<<" has been deleted"<<endl;
    }
};
// ---------------------------------------  INSERTION   --------------------------------------------------------------------
void insertNode( Node * &tail ,int input , int emt){
    if( tail == NULL){
        Node * newNode = new Node( input);
        tail = newNode;
        newNode ->next = newNode;
    }
    else{
        //  ASSUMING input value present in list
        Node * temp = tail->next;
        while( emt != temp->data){
            temp = temp ->next;
        }
        Node * newNode = new Node(input);
        if( temp == tail){
            tail = newNode;
        }
        newNode ->next = temp->next;
        temp->next = newNode;
    }
}

// ---------------------------------------  DELETION  --------------------------------------------------------------------
void deleteNode( Node * & tail , int val){
    // if list EMPTY
    if( tail == NULL){
        cout<<"List is empty"<< endl;
        return;
    }
    else{
        Node * prev = tail ;
        Node * cur = tail->next;
        while( cur -> data != val){
        prev = cur;
        cur = cur ->next;
        }
        if( cur == tail){
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
        if( visited[temp] == true){
            cout<<"Start of  cycle at "<< temp->next ->data;
             return true;
        }
           
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
Node * startOfCycle( Node * head ){ // A + B = C i.e  C is distance of loop and A distance till start .B is From A till fast == slow
    //  now assigning slow to head and move both fast  and slow at 1x till they reach .... the reaching point will be Start/ beg of cycle
    Node * fast = floyd( head ); // this is also point of intersection
    Node * slow = head;

    while(fast != slow){
        fast = fast ->next;
        slow = slow ->next;
    }
    return slow;
}


void Print(Node * &tail){
    if( tail == NULL || tail->next ==NULL ){
        cout<<" LIST IS EMPTY"<<endl;
        return;
    }
    Node * temp = tail ->next;
    while( temp != tail){
        cout<<temp ->data<< " ";
        temp = temp->next;
    }
    cout<<tail->data;
    cout<<endl;
}

int main(){
    Node * tail = NULL;
    // INSERTION
  
    insertNode(tail , 10 , 10);
    Print( tail);
    insertNode(tail , 20 , 10);
    Print( tail);

    insertNode(tail , 30 , 20);
    Print( tail);

    insertNode(tail , 40 , 30);
    Print( tail);

    insertNode(tail , 40 , 20);
    Print( tail);

    // DELETION
   /*
    deleteNode(tail , 10);
    Print(tail);
    cout<<"tail :"<<tail->data;

    deleteNode(tail , 40);
    Print(tail);
    cout<<"tail :"<<tail->data;

    deleteNode(tail , 40);
    Print(tail);
    cout<<"tail :"<<tail->data;

    deleteNode(tail ,20);
    Print(tail);
    cout<<"tail :"<<tail->data;

    
    deleteNode(tail ,30);
    Print(tail);
    */
    // cout<<"tail :"<<tail->data;

//  CHECK FOR LOOP
    (checkLoop( tail)) ? cout <<"\nLOOP IS PRESENT \n" : cout<<"\nLOOP  ABSENT \n";

    (floyd( tail)) ? cout <<"\nLOOP IS PRESENT \n" : cout<<"\nLOOP  ABSENT \n";

    cout<<"\nStart of cycle = "<<startOfCycle(tail)->data;
}