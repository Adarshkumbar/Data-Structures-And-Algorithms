//              Stack using two queues
//  easy

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
int main()
{
    QueueStack *qs = new QueueStack();

    int Q;
    cin>>Q;
    while(Q--){
    int QueryType=0;
    cin>>QueryType;
    if(QueryType==1)
    {
        int a;
        cin>>a;
        qs->push(a);
    }else if(QueryType==2){
        cout<<qs->pop()<<" ";

    }
    }
    cout<<endl;
}
//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
   // for PUSH operation we just push in q1
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if( q1.empty())
        return -1;
    // step 1 -> pop till size of q1 becomes 1
    
    while( q1.size() > 1 ){
        q2.push(q1.front());
        q1.pop();
    }
    // step  -2 getting emt to be popped
    int emt = q1.front();
    q1.pop();
    
    //  Step -3 push backk all emts to q1
     while( !q2.empty() ){
        q1.push(q2.front());
        q2.pop();
    }
    return emt;
}