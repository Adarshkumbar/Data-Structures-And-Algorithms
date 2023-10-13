// deletion in Unsorted LIST easy .... just create map to keep track of visited nodes


    Node * removeDuplicatesUnsorted( Node *head) 
    {
        if( head == NULL)
            return NULL;
        
        map < int, bool > visited; // keeps track of already visited map
        
        Node * prev = NULL;
        Node * cur = head;
        
        while( cur != NULL){
            if( visited[cur->data] == true)  // means we need to delete this node
            {
                Node * nodeToDelete = cur ;
                cur = cur -> next ;
                prev -> next = cur;
                nodeToDelete -> next = NULL;
                delete (nodeToDelete);
            }
            else{  // means this is the first time we encountered such node
                visited[cur->data] = true ; // marking this node true
                prev = cur ;
                cur = cur -> next;
            }
        }
        return head;
    }


