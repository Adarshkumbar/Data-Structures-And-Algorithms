#include<iostream>
using namespace std;

class Stack{
    public:
        int * arr; // gonna create dynamic arr;
        int size ; // size of arr
        int top ;
    Stack(int size){
        this -> size = size;
        arr = new int[size]; //dynamic arr;
        top = -1 ;
    }
    void push(int emt ){
        if( top >= size)
            cout<<"Stack OverFlow"<<endl;
        if( size - top > 1){// within range 
            arr[++top] = emt;
        }
    }
    void pop(){
        if( top == -1 )
            cout<<" Stack UnderFlow "<<endl;
        else    
        {
            cout<<" Popped Emt is "<<arr[top]<< endl;
            top--;
        }
    }
    void peek(){
        if( top == -1)
            cout<<" Stack is Empty"<<endl;
        else    
            cout<<" top emt is "<< arr[top];
    }
    bool isEmpty(){
        if(top == -1)
            return 1;
        return 0;
    }
};

int main(){
    Stack stk(4);
    // cout<<stk.isEmpty();
    // stk.pop();
    // stk.peek();
    stk.push(11);
    stk.push(21);
    stk.push(31);
    stk.push(41);
    stk.peek();

    stk.pop();
    stk.pop();
    stk.peek();
}