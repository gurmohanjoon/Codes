#include<iostream>
#include<queue>
#include<climits>
#include<set>
using namespace std;
typedef multiset<int>::iterator it;

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
    // int arr[]={8,11,2,9,10,11,20,10};
    // int n=sizeof(arr)/sizeof(int);
    
    //               Set

    // set<int> s;
    // for(int i=0;i<n;i++)
    // {
    //     s.insert(arr[i]);
    // }
    // auto it=s.find(11);
    // s.erase(it);
    // s.erase(10);
    // for(set<int>::iterator it=s.begin();it!=s.end();it++)
    // {
    //     cout<<*(it)<<" ";
    // }
    // s.erase(20);
        // set<pair<int,int>> s;
        // s.insert(make_pair(10,1));
        // s.insert(make_pair(10,4));
        // s.insert(make_pair(10,8));
        // s.insert(make_pair(13,5));
        // s.insert(make_pair(5,4));
        // s.insert(make_pair(5,1));
        // s.erase(s.find(make_pair(5,4)));
        // s.insert(make_pair(8,9));
        // auto it=s.lower_bound(make_pair(10,1));
        // {
        //    cout<<it->first<<" , "<<it->second<<endl;
        // }
        // auto its=s.upper_bound(make_pair(10,INT_MAX));
        // {
        //     cout<<its->first<<" , "<<its->second<<endl;
        // }
        // for(auto p:s)
        // cout<<p.first<<" and "<<p.second<<endl;
        
        // Multiset -> That can store multiple elements that have same elements
        // Sorted in specific -> Sorted according to internal comparision object
        // int arr[]={10,20,10,30,20,30,30,30,40,30,10,76,88,96,80};
        // int size=sizeof(arr)/sizeof(int);
        // multiset<int> s(arr,arr+size);
        // //s.erase(20);
        // s.insert(33);
        // for(int x:s)
        // cout<<x<<" ";
        // cout<<"\n"<<s.count(10)<<endl;
        // auto io=s.find(30);
        // cout<<(*io)<<endl;
        // pair<it,it> p=s.equal_range(30);
        // for(auto it =p.first;it!=p.second;it++)
        //   cout<<*it<< " ";
        // cout<<endl;
        // //lower bound and upper bound 
        // for(auto it=s.lower_bound(10);it!=s.upper_bound(80);it++)
        //   cout<<*it<<" "; 
        // pair<string,int> p1=make_pair("A",120);
        // pair<string,int> p2=make_pair("B",34);
        // pair<string,int> p3=make_pair("c",160);
        // pair<string,int> p4=make_pair("D",30);
        // multiset<pair<string,int>> s;
        // s.insert(p1);
        // s.insert(p2);
        // s.insert(p3);
        // s.insert(p4);
        // for(auto p:s)
        // cout<<p.first<<" "<<p.second<<endl;

    return 0;
}