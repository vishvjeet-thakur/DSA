//ASSIGNMENT - 6 

// Vishvjeet Thakur
// Sid - 21105066


#include <iostream>                   
#include <queue>                     
using namespace std;


class Node{
    public:
        int data;
        Node*left;
        Node*right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }   
};

Node * insert_in_BST(Node*root,int data){ // to insert data into BST

    if(root==NULL){
        Node*new_node=new Node(data);
        root=new_node;
        return root;
    }

    if(data>root->data){root->right=insert_in_BST(root->right,data);}

    else if(data<root->data){root->left=insert_in_BST(root->left,data);}

    else{return root;}

    return root;
}

void level_order_traversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){q.push(NULL);};}

        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

Node* min_value_node(Node* node) // to get min value node in a Binary Search Tree
{
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* delete_node(Node* root, int key) //to delete a node 
{
    if (root == NULL)
        return root;
  
    if (key < root->data)
        root->left = delete_node(root->left, key);
  
    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        else if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
             Node* temp = root->left;
            free(root);
            return temp;
        }
 
        Node* temp = min_value_node(root->right);
        root->data= temp->data;
        root->right = delete_node(root->right, temp->data);

    }
    return root;
}

void pfun(int arr[],int n){// to print a array
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"\nEnter number elements in the ARRAY to form BST:";cin>>n;
    int arr[n];
    cout<<"\nEnter elements of the array to form BST:";
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<"\nArray:[";pfun(arr,n);cout<<"]";
    cout<<endl;

    Node*root=NULL;
    for(int i=0;i<n;i++){
        root=insert_in_BST(root,arr[i]);
    }
    cout<<"\nBinary Search Tree using Level Order Traversal\n"<<endl;
    level_order_traversal(root);

    int key;
    cout<<"\nEnter data to be deleted from BST:";cin>>key;
    root=delete_node(root,key);
    cout<<"\nBinary Search Tree after deleting:"<<key<<endl;
    cout<<endl;
    level_order_traversal(root);
}

/*
space complexity of tree is  O(n) 
space complexity of  the array is  O(n)
*/