#include<iostream>
#include<vector>
using namespace std;
class treenode
{
    public:
    int val=0;
    treenode *left=NULL;
    treenode *right=NULL;

    // treenode(int val)
    // {
    // this->val=val;
    // cout<<this<<endl;
    // }
     treenode(int n)
    {
    val=n;
    cout<<val<<endl;
    }
};
void roottoleaf(treenode* root,vector<vector<int>> &ans,vector<int> &smallans)
    {
         if(root==nullptr)
         return;
         if(root->left==nullptr && root->right==nullptr) 
         {
            vector<int> base(smallans);
            base.push_back(root->val);
            ans.push_back(base);
         }
         smallans.push_back(root->val);
         roottoleaf(root->left,ans,smallans);
         roottoleaf(root->right,ans,smallans);
         smallans.pop_back() ;
    }
     vector<vector<int>> roottoleaf(treenode* root)
    {
        vector<vector<int>> ans;
        vector<int> smallans;
        roottoleaf(root,ans,smallans);
        return ans;
    }
int main()
{
    treenode *node=new treenode(10);
    cout<<node;
    return 0;
}