//        Ske tree int which all the nodes are in one side only
#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left =nullptr;
    node* right=nullptr;
    node(int d)
    {
        data=d;
    }
};
node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    return nullptr;
    node * root = new node(d);
    root->left=buildtree();
    root->right=buildtree();

}
void print(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    
}
//            Preorder->Inorder->Postorder

void printIn(node * root)
{
    if(root==NULL)
    return;
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPost(node * root)
{
    if(root==NULL)
    return;
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";

}
void preinpost(node * root)
{
    cout<<"Preorder\n";
    print(root);
    cout<<endl;
    cout<<"Inorder\n";
    printIn(root);
    cout<<endl;
    cout<<"Postorder\n";
    printPost(root);
}

//      Level order Print          
int height(node * root)
{
    if(root==nullptr)
    return 0;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
void printklevel(node * root , int k)
{
    if(root == NULL)
    return;
    if(k==0)
    cout<<root->data<<" ";
    printklevel(root->left,k-1);
    printklevel(root->right,k-1);
}
void printallorder(node * root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        cout<<i<<" ";printklevel(root,i);
        cout<<endl;
    }
}

//                Binary tree traversal

void bfs(node * root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* f= q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
    return;
}
void bfs2(node * root)
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

//                Count and sum of nodes
int countnodes(node * root)
{
    if(root==nullptr)
        return 0;
    int c1 = countnodes(root->left);
    int c2 = countnodes(root->right);
    return 1+c1+c2;
}
int sumofnodes(node * root)
{
    if(root==nullptr)
        return 0;
    int s1=sumofnodes(root->left);
    int s2=sumofnodes(root->right);
    return root->data+s1+s2;

}
//             Diameter of tree
int diameter(node *root)
{
   if(root==nullptr)
      return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));

}
class Pair
{
    public:
    int height;
    int diameter;
};
Pair fastdiameter(node *root)
{
    Pair p;
    if(root == nullptr)
    { 
        p.height = p.diameter=0;
        return p;
    }
    Pair left=fastdiameter(root->left);
    Pair right=fastdiameter(root->right);

    p.height=max(left.height,right.height) +1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;

}
//         Replace each node by sum of nodes and not change leaf node
int replace(node*root)
{
    if(root==nullptr)
        return 0;
    if(root->left==nullptr&&root->right==nullptr)
       return root->data; 
    int s1=replace(root->left);
    int s2 =replace(root->right);    
    int temp=root->data;   
    root->data = s1+s2;
    return root->data + temp;

}
//           Height of a balance tree     (height of a balanced tree |h1-h2|<=1 at every node)
class hbpair
{
    public:
    int height;
    int balance;
};
hbpair balancedtree(node * root)
{   hbpair  hb;
    if(root==NULL)
    {
        hb.height =0;
        hb.balance=true;
        return hb;
    }
    hbpair h1 = balancedtree(root->left);  
    hbpair h2 = balancedtree(root->right);
    hb.height=max(h1.height,h2.height)+1;
    if(abs(h1.height-h2.height)<=1 && h1.balance && h2.balance)
       hb.balance=true;
    else 
       hb.balance=false;
    return hb;    
}
//           Building a height balanced tree  from an array 
node * buildtreefromarray(int * a,int s, int e) // 1 2 3 4 5 6 7
{
    if(s>e)
     return nullptr;
    int mid= (s+e)/2;
    node * root=new node(a[mid]);
    root->left=buildtreefromarray(a,s,mid-1); 
    root->right=buildtreefromarray(a,mid+1,e);  
    return root;
}

//           Building a tree from preorder and postorder

node * createtree(int *in ,int * pre,int s, int e)
{
    static int i=0;
    if(s>e)
      return nullptr;
    node * root = new node(pre[i]);
    int ind=-1;
    for(int j=s;s<=e;j++)
    {
        if(in[j]==pre[i])
        {ind=j;
        break;}
    }  
    i++;
    root->left=createtree(in,pre,s,ind-1);
    root->right=createtree(in,pre,ind+1,e);
    return root;
}

//               Right view of a tree

void printrightview(node * root,int level,int &maxlevel)
{
      if(root ==nullptr)
        return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel = level;
    }    
    printrightview(root->right,level+1,maxlevel);
    printrightview(root->left,level+1,maxlevel);
}

//        Binary tree node at k distance from given target

int printtargetkdistance(node *root,node * target,int k)
{

    if(root==nullptr)
    return -1;
    if(root==target)
    {
       printklevel(target,k);
       return 0;
    }
    int dl=printtargetkdistance(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        cout<<root->data;
        else
        printklevel(root->right,k-2-dl);
        return 1+dl;
    }
     int dr=printtargetkdistance(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        cout<<root->data;
        else
        printklevel(root->left,k-2-dl);
        return 1+dl;
    }
    return -1;  
}

//              Lowest Common Ancestor
node * lca(node * root,int a,int b)
{
    if(root==nullptr)
       return nullptr;
    if(root->data==a || root->data==b)
      return root;
    node * lans=lca(root->left,a,b);
    node * rans=lca(root->right,a,b);
    if(lans!=nullptr and rans!=nullptr)
       return root;
    if(lans!=nullptr)
      return lans;
    return rans;          
}

// Max sum path from any node t0 any node

// class Pair
// {
//     public:
//     int branchsum;
//     int maxsum;
//     Pair()
//     {
//         branchsum=0;
//         maxsum=0;
//     }
// };

int sumpath2(node * root,int & ans)
{
    if(root==nullptr)
      return 0;
    int lans=sumpath2(root->left,ans);
    int rans=sumpath2(root->right,ans);
    ans=max(ans,root->data);
    ans=max(ans,lans + root->data);
    ans=max(ans,rans + root->data);
    ans=max(ans,lans + rans + root->data); 
    return max(root->data,root->data + max(lans,rans));
}

// int sumpath(node* root, int &result)
// {
//     if (root == nullptr) {
//         return 0;
//     }
//      int left = sumpath(root->left, result);
//      int right = sumpath(root->right, result);
//      result = max(result, root->data);
//     result = max(result, root->data + left);
//     result = max(result, root->data + right);
//     result = max(result, root->data + left + right);
//     return max(root->data, root->data + max(left, right));
// }

//  Shortest distance 2 nodes A and B
int search(node * root,int val,int level)
{
    if(root==nullptr)
       return -1;
    if(root->data==val)
      return level;
    int left=search(root->left,val,level+1);
       if(left!=-1)
          return left;
    return search(root->right,val,level+1);           
}
 
 int finddistance(node * root,int a , int b)
 {
     node * lcanode = lca(root,a,b);
     int l1=search(lcanode,a,0);
     int l2=search(lcanode,b,0);
     return l1+l2;  
 }

//             Main function

int main()
{
    node* root=buildtree();
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// 1 2 4 6 -1 -1 7 10 -1 -1  11 -1 -1 5 8 -1 -1 9 -1 -1  3 -1 -1
    //preinpost(root);
    // print(root);
    // cout<<endl<<height(root);
    //cout<<endl;
    //printklevel(root,3);
    // cout<<endl;
    // printallorder(root);
    //bfs2(root);
    //bfs2(root);
    //cout<<countnodes(root);
    //cout<<endl<<sumofnodes(root);
    //cout<<diameter(root);
    // Pair p=fastdiameter(root);
    // cout<<p.height<<endl<<p.diameter<<endl;
    //cout<<endl<<replace(root)<<endl;
    // bfs2(root);
    // if(balancedtree(root).balance)
    // cout<<"Balance tree";
    // else
    // cout<<"Unbalance tree";
    // return 0;
    // int arr[]={1,2,3,4,5,6,7};
    // node * root=buildtreefromarray(arr,0,6);
    // bfs2(root);
    // int in[]={3,2,8,4,1,6,7,5};
    // int pre[]={1,2,3,4,8,5,6,7};
    // int n=sizeof(in)/sizeof(int);    
    // node * root=createtree(in,pre,0,n-1);
    //  bfs2(root);    
    //  int maxlevel=-1;
    // printrightview(root,0,maxlevel);
        bfs2(root);
   // printtargetkdistance(root,root->left->left,3);
//    node * ans=lca(root,11,9); 
//    cout<<"LCA of 11 and 9 are "<<ans->data;
    // int ans=0;
    // sumpath2(root,ans);
    // cout<<ans;
    //cout<<"distance "<<finddistance(root,7,9);
return 0; 
}