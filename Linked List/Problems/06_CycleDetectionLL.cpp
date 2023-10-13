// pbm 1 : we need to say true if cycle is present else false

//  APPROACH 1 .... TC O(n) and SC O(n) --cuz of map
bool checkCycle( Node * head){
    if( head == NULL)                       
        return false;
    Node * temp = head; // for traversal

    //  creating map to keep track of visited nodes .... 
    //  if visited again then loop else not loop

    map < Node * , bool > visited ;

    while( temp != NULL){
        if( visited[temp] == true)          // to get start of cycle print below              
            return true;                    // cout<<"Start of  cycle at "<< temp->next ->data;  or head -> data; 

        visited[temp] = true; // marking node true

        temp = temp->next;
    }
    return false;

}

//  APPROACH 2 .. FLOYD CYCLE DETECTION ALGO
//  what this algo does is keeps fast(2x) and slow(1x) 

Node * floyd (Node * head){
    if( head == NULL)
        return head;
    Node * fast = head;
    Node * slow = head;

    while( fast != NULL && slow != NULL){
        fast = fast -> next ;        // 1x 
        if( fast != NULL)           //  2x
            fast = fast ->next ;
        slow = slow ->next          // 1x for slow

        if( fast == slow)
            return slow;
    }
    return NULL;
}
//-------------------------------------------------  prb 2 : start/ beginning of cycle -----------------------------------------

//  after we found out cycle from floyd do below

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

//------------------------------------------------ prb 3:  Remove Loop -----------------------------------------------------------

void removeCycle( Node * head){
    if( head == nullptr)
        return;
    // we take "start" point of cycle and" temp" will be equlal to it ....
    // we go on checking temp->next == start if found then 
    //  temp -> next = NULL;
    Node * start = startOfCycle( head );

    Node * temp = start ;
    while( temp ->next != start){           // works for all conditions even 1 node
        temp = temp ->next;
    }
    temp ->next = NULL;
}