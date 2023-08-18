// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node{
public:

int data;
node* left;
node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root)
{
    int input;
    cin>>input;
    if(input==-1)return NULL;
    root = new node(input);
    
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

void preorder(node* root)
{
    if(root==NULL)return;
    
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}


void lot(node* root)
{
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node* f = q.front();
            q.pop();
            cout<<f->data;
            
            if(f->right)
            q.push(f->right);
            
            if(f->left)
            q.push(f->left);
        }
        cout<<endl;
    }
    
}

int main() {
    // Write C++ code here
    node* root = NULL;
    root = buildTree(root);
    preorder(root);
    cout<<endl;
    lot(root);
    // preorder(root);
    // 1 3 5 -1 -1 -1 7 -1 8 -1 -1
    
    // std::cout << "Hello world!";
    

    return 0;
}