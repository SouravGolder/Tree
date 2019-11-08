#include <iostream>

using namespace std;

class tree
{
public:
    int data;
    tree *left, *right;
};
tree *Insert(tree *ptr, int data);
void Inorder(tree *ptr);
void Preorder(tree *ptr);
void Postorder(tree *ptr);

int main()
{
    int n,i,x;
    cin>>n;
    tree *root=NULL;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root,x);
    }
    cout<<"Root = "<<root->data<<endl;
    cout<<"Inorder ===> ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder ==> ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder => ";
    Postorder(root);
    return 0;
}

tree *Insert(tree *ptr, int data)
{
    if(ptr==NULL)
    {
        ptr=new tree;
        ptr->data=data;
        ptr->left=ptr->right=NULL;
    }
    else if(data<=ptr->data)
        ptr->left = Insert(ptr->left,data);
    else
        ptr->right = Insert(ptr->right,data);
    return ptr;
}

void Inorder(tree *ptr)
{
    if(ptr==NULL)
        return;
    Inorder(ptr->left);
    cout<<ptr->data<<" ";
    Inorder(ptr->right);
}

void Preorder(tree *ptr)
{
    if(ptr==NULL)
        return;
    cout<<ptr->data<<" ";
    Preorder(ptr->left);
    Preorder(ptr->right);
}

void Postorder(tree *ptr)
{
    if(ptr==NULL)
        return;
    Postorder(ptr->left);
    Postorder(ptr->right);
    cout<<ptr->data<<" ";
}
