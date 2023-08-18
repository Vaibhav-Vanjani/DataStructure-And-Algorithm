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

int main() {
    // Write C++ code here
    node* root = NULL;
    root = buildTree(root);
    preorder(root);
    // preorder(root);
    
    std::cout << "Hello world!";
    

    return 0;
}
