//  BINARY TREE - BASICS
#include<iostream>
#include<queue>
using namespace std;

class node{
    public :
        int data;
        node * left;
        node * right;
    
    //  constructor
    node(int data){
        this ->data = data;
        this ->left = NULL;
        this ->right = NULL;
    }
};

//---------------------------------------------------- THIS function creates Binary Tree RECURSIVELY ------------------------------
node * buildTree(node * &root){

// STEP - 1 CREATING ROOT / NODE
    int data;
    cout<<" Enter data : "<<endl;
    cin>>data;

    if( data ==-1)
        return NULL;
    
    root = new node(data);

// STEP - 2 Going left 
    cout<<"Enter data for Left of "<< data <<" : ";
    root -> left = buildTree(root->left);

// STEP - 3 Going right
    cout<<"Enter data for Right of "<< data <<" : ";
    root -> right = buildTree(root->right);

// STEP - 4 return root/ node 
    return root;
}
// ----------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------- LEVEL ORDER TRAVERSAL -----------------------------------------------------------
//  using queue
void levelOrderTraversal( node * &root){
    //  Step 1  creating queue and adding root and NULL-> cuz its breaking point to print enter
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    //  Step 2 Loop till q is empty 
    // keep on popping q and putting it in temp to print and push left and right of temp in q
    while( !q.empty()){
        node * temp = q.front();
        q.pop();

    //  Step 3 if temp is NULL then its breaking pt so enter
        if( temp == NULL){
            cout<<endl;

            //  Step 4 Adding breaking pt if emts are still in queue
            if(!q.empty()){
                q.push(NULL);
            }
        }
    //  Step 5 printing and pushing left and right nodes in queue
        else{
            cout<<temp-> data<<" ";

            //  pushing left
            if( temp->left)
                q.push(temp->left);
            //  pushing right
            if( temp->right)
                q.push(temp->right);
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------- INORDER TRAVERSAL ------------------------------------------------------
void inorder(node * root){
    if( root == NULL)
        return ;
    //  LEFT
    inorder(root->left);

    // ROOT
    cout<<root->data<<" ";

    // RIGHT
    inorder(root->right);

}

// --------------------------------------------------- PREORDER TRAVERSAL ------------------------------------------------------
void preorder(node * root){
    if( root == NULL)
        return ;

    // ROOT
    cout<<root->data<<" ";

    //  LEFT
    preorder(root->left);
  
    // RIGHT
    preorder(root->right);

}

// --------------------------------------------------- POSTORDER TRAVERSAL ------------------------------------------------------
void postorder(node * root){
    if( root == NULL)
        return ;

    //  LEFT
    postorder(root->left);
  
    // RIGHT
    postorder(root->right);

    // ROOT
    cout<<root->data<<" ";

}

// ---------------------------------------------------------------------------------------------------------------------------------

//  BUILDING TREE WITH LEVEL ORDER TRAVERSAL ////i.e QUEUE

node * buildTreeWithLevelOrder(node * &root){
    queue<node *> q;
    int data;
    cout<<" Enter data :";
    cin>>data;

    if( data == -1 )
        return NULL;
    root = new node(data);
    q.push(root);

    while( !q.empty()){
        node * temp = q.front();
        q.pop();

    //  left of node
        cout<<"Enter left of "<< temp->data<<" : ";
        int leftData;
        cin>>leftData;
        if( leftData != -1){
            temp ->left = new node(leftData);
            q.push(temp->left);
        }
        

    // right of node 
        cout<<"Enter right of "<< temp->data <<" : "; 
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp ->right = new node(rightData);
            q.push(temp->right);
        }
        
    } 
}

int main(){
    node * root = NULL;

    // buildTree(root);

    buildTreeWithLevelOrder(root);
    levelOrderTraversal(root);
    // cout<<"root :"<<root->data;
    cout<<"INORDER : ";
    inorder(root);
}