#include<iostream>
#include<queue>
#include<climits>
#include<set>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

//                Binary Search Tree building 

node * createbsttree(node * root,int d)
{
    if(root==nullptr)
    {
        return new node(d);
    }
    if(d<root->data)
    root->left=createbsttree(root->left,d);
    else
    root->right=createbsttree(root->right,d);
    return root;
}
node * buildtree()
{
    int d;
    cin>>d;
    node * root = nullptr;
    while(d!=-1)
    {
       root=createbsttree(root,d);
       cin>>d;
    }
    return root;
}

//                 Printing Tree Preorder Inorder Postorder

void print(node * root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f= q.front();
        if(f==NULL)
        {
           cout<<endl;
           q.pop();
           if(!q.empty())
           {
               q.push(NULL);
           }
        }
        else
        {   
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
    }
    return;
}

void printpre(node * root)
{
    //
    if(root==nullptr)
       return;
    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}
void printIn(node * root)
{
    //
    if(root==nullptr)
       return;
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printpost(node * root)
{
    //
    if(root==nullptr)
       return;
    printpost(root->left);
    printpost(root->right);
    cout<<root->data<<" ";
}

void printorder(node * root)
{
    printpre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printpost(root);
    cout<<endl;
}


//                                 find the no. present or not

bool search(node * root,int val)
{
    if(root==nullptr)
    return false;
    if(root->data==val)
      return true;
    if(val<root->data)
      return search(root->left,val);
    if(val>root->data)
       return search(root->right,val);
    //return false;        
}
 void search(node * root)
 {
     if(search(root,13))
       cout<<"True";
     else 
       cout<<"False";  
 }

 //                              Deletion of a node

 node * deletenode(node * root, int data)
 {
     if(root==nullptr)
        return nullptr;
     if(data<root->data)
        deletenode(root->left,data);
     else if(root->data==data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return nullptr;
        }
        if(root->left!=nullptr && root->right==nullptr)
        {
            node * temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==nullptr && root->right!=nullptr)
        {
            node * temp=root->right;
            delete root;
            return temp;
        }
        node * replace = root->right;
        while(replace->left!=NULL)
        {
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deletenode(root->right,replace->data);
        return root;
    }
    else
    {
      deletenode(root->right,data);
    }        
 }

 //                   Is Tree a BST or not

bool isBst(node * root, int minv,int maxv)
{
    if(root==nullptr)
       {return true;}
    if(root->data<=maxv && root->data>=minv && isBst(root->left,minv,root->data) && isBst(root->right,root->data,maxv))
       {return true;}
    return false;      

}

//                      Make BsT into linked list
class linkedlist
{
    public:
    node * head;
    node * tail;
};

linkedlist bsttoll(node * root)
{
    linkedlist l;
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL && root->right == NULL)
    {
        linkedlist leftll=bsttoll(root->left);
        leftll.tail->right=root;

        l.head=leftll.head;
        l.tail=root;
        return l;
    }
     if(root->left==NULL && root->right != NULL)
    {
       
        linkedlist rightll=bsttoll(root->right);
        rightll.head->left=root;

        l.tail=rightll.tail;
        l.head=root;
        return l;
    }

    linkedlist leftll=bsttoll(root->left);
    linkedlist rightll=bsttoll(root->right);

    leftll.tail->right=root;
    root->right=rightll.head;

    l.head=leftll.head;
    l.tail=rightll.tail;

    return l;
}

int main()
{
    //node * root=buildtree();  //  5 1 2 3 4 6 7 8 9 -1
    //printorder(root);
     //printpre(root);
     //cout<<endl;
    // search(root);
    // root=deletenode(root,1);
    // print(root);
    // cout<<isBst(root,INT_MIN,INT_MAX)<<endl;
    // if(isBst(root,INT_MIN,INT_MAX))
    //   {cout<<"True";}
    // else
    //   {cout<<"False";}
    //bsttoll(root);
    int arr[]={8,11,2,9,10,11,20,10};
    int n=sizeof(arr)/sizeof(int);
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*(it)<<" ";
    }
    
}