//  Quesiont - 1 normal reversal
// Easy
//  2 - METHODS
//  1. just use stack -> push all and pop all to get result
//  2 .Recursion 
//  ---->         
        //  base case
        void solve( queue<int> &q) {
            if( q.empty())
                return; 
        //  storing 1st emt;
            int emt = q.front();
        //  recursive call
            solve(q);
            q.push(emt);
        }    
      

// /---------------------------------------------------------------------------------------------------------------/ //
//      Question - 2 Reverse First K elements of Queue
// easy

//  recursive call to reverse queue.

void solve(queue<int> &q ){
    if( q.empty()){
        return ;
    }
    int emt = q.front(); //storing and  popping 1 st emt and storing 
    q.pop();
    solve( q );
    q.push( emt);
} 

queue<int> modifyQueue(queue<int> q, int k) {
    queue<int> ans;
//------------------------------------------  approach - 1 using stack -----------------------------------------
    // stack < int > stk;
    // for( int i = 0 ; i < k ; i++){
    //     stk.push(q.front());
    //     q.pop();
    // }
    // while( !stk.empty()){
    //     ans.push( stk.top());
    //     stk.pop();
    // }
    // while( !q.empty()){
    //     ans.push(q.front());
    //     q.pop();
    // }
    // return ans;
    
// -----------------------------------------  approach -2 using recursion --------------------------------------
     for( int i = 0 ; i < k ; i++){ // pushing emts to be reversed
        ans.push(q.front());
        q.pop();
    }
    //  reversing the ans queue - recursively
    solve( ans);
    //  now pushing remaining emt from q to ans
    while( !q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;   
}
