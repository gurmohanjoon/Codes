import java.util.*;
class tree1
{
    public static class treenode
    {
        int val=0;
        treenode left=null;
        treenode right=null;

        treenode(int val)
        {
            this.val=val;
            System.out.println(this);
        }    
    }
    public static int size(treenode root)
    {
        return root==null?0:size(root.left)+size(root.right)+1;
    }
    public static int height(treenode root)
    {
        return root==null?-1:Math.max(height(root.left),height(root.right))+1;
    }
    public static int max(treenode root)
    {
        return root==null?-(int)1e9:Math.max(max(root),(Math.max(max(root.left),max(root.right))));
    }
    public static int min(treenode root)
    {
        return root==null?(int)1e9:Math.min(min(root),(Math.min(min(root.left),min(root.right))));
    }
    public static boolean find(treenode root,int data)
    {
        if(root==null)
        return false;
         if(root.val==data)
         return true;

         return find(root.left,data) || find(root.right,data);
    }
    public static ArrayList<treenode> nodetoroot(treenode root,int data)
    {
        if(root==null)
        return new ArrayList<>();

        if(root.val==data)
        {
            ArrayList<treenode> base=new ArrayList<>();
            base.add(root);
            return base;
        }
        ArrayList<treenode> left=nodetoroot(root.left,data);
        if(left.size() !=0)
        {
            left.add(root);
            return left;
        }
        ArrayList<treenode> right=nodetoroot(root.right,data);
        if(right.size() !=0)
        {
            right.add(root);
            return right;
        }
        return new ArrayList<>();

    }
    public static boolean nodetoroot2(treenode root,int data,ArrayList<treenode> ans)
    {
        if(root==null)
        return false;

        if(root.val==data)
        {
            ans.add(root);
            return true;
        }
        boolean res = nodetoroot2(root.left,data,ans) ||  nodetoroot2(root.right,data,ans);
        if(res);
        ans.add(root);
        return res;

    }
    public static void roottoleaf(treenode root,ArrayList<ArrayList<Integer>> ans,ArrayList<Integer> smallans)
    {
         if(root==null)
         return;
         if(root.left==null && root.left==null)
         {
            ArrayList<Integer> base=new ArrayList<>(smallans);
            base.add(root.val);
            ans.add(base);
         }
         smallans.add(root.val);
         roottoleaf(root.left,ans,smallans);
         roottoleaf(root.right,ans,smallans);
         smallans.remove(smallans.size()-1);
    }
    public static ArrayList<ArrayList<Integer>> roottoleaf(treenode root)
    {
        ArrayList<ArrayList<Integer>> ans =new ArrayList<>();
        ArrayList<Integer> smallans =new ArrayList<>();
        roottoleaf(root,ans,smallans);
        return ans;
    }

    public static void main(String[] args)    {
        treenode node=new treenode(10);
        //System.out.println(node);
       

    }
}