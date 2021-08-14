import java.util.*;
import java.util.ArrayList;
class tree1
{
    class treenode
    {
        int val;
        treenode left=null;
        treenode right=null;
        treenode(int val)
        {
            this.val=val;
        }
    }

//                   Create tree

    public  treenode createtree()
    {
        Scanner scn=new Scanner(System.in);
        int  val=scn.nextInt();
        if(val==-1)
        {
            return null;
        }
        treenode root=new treenode(val);
        root.left=createtree();
        root.right=createtree();
        return root;
    }
//            Print of tree    
    public static void print(treenode root)
    {
        if(root==null)
        return;
        System.out.print(root.val + " ");
        print(root.left);
        print(root.right);
    }

//               Size of tree

    public static int size(treenode root)
    {
        return root==null ? 0 : size(root.left) + size(root.right) +1;
    }    

//                Height of a tree 

    public static int height(treenode root)
    {
        return root==null ? -1 : Math.max(height(root.left) , height(root.right)) +1;
    }
   
//               max and min node of a tree    

    public static int max(treenode root)
    {
         return root == null ? -(int)1e9 : Math.max(root.val,Math.max(max(root.left),max(root.right)));
    }
    public static int min(treenode root)
    {
         return root == null ? (int)1e9 : Math.min(root.val,Math.min(max(root.left),min(root.right)));
    }
   
//              Find the data 

    public static boolean find(treenode root,int data)
    {
        if(root==null)
        return false;
        if(root.val==data)
        return true;
        boolean res;
        res=find(root.left,data);
        res=find(root.left,data);
        if(res)
        return true;
        else
        return false;
    }
    public static boolean find2(treenode root,int data)
    {
        if(root==null)
        return false;
        if(root.val==data)
        return true;
        return find2(root.left,data) || find2(root.right,data);
    }

//          Node to Root Path

    public static boolean nodetorootpath(treenode root,ArrayList<treenode> ans,int data)
    {
        if(root==null)
        {
            return false;
        }
        if(root.val==data)
        {
            ans.add(root);
            return true;
        }
        // if(nodetorootpath(root.left,ans,data))
        // {
        //     ans.add(root.val);
        //     return true;
        // }
        // if(nodetorootpath(root.right,ans,data))
        // {
        //     ans.add(root.val);
        //     return true;
        // }
        // return false ;

        boolean res = nodetorootpath(root.left,ans,data) || nodetorootpath(root.right,ans,data);
        if(res)
        ans.add(root);   
        return res; 

    }

    //         Node to all root path

    public static void nodetoallnodepath2(treenode root,ArrayList<ArrayList<Integer>> ans,ArrayList<Integer> smallans)
    {
        if(root==null )
        return;
        if(root.left==null && root.right==null)
        {
            ArrayList<Integer> base=new ArrayList<>(smallans);
            base.add(root.val);
            ans.add(base);
            return;
        }
        smallans.add(root.val);
        nodetoallnodepath2(root.left,ans,smallans);
        nodetoallnodepath2(root.right,ans,smallans);
        smallans.remove(smallans.size()-1);
    }
    public static ArrayList<ArrayList<Integer>> nodetoallnodepath(treenode root)
    {
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        ArrayList<Integer> smallans=new ArrayList<>();
        nodetoallnodepath2(root,ans,smallans);
        return ans;
    }

    //                   Exactly one child

    public static void onechild(treenode root,ArrayList<Integer> ans)
    {
        if(root==null || root.left==null && root.right==null )
        return;
        if(root.left==null || root.right==null)
        ans.add(root.val);
        onechild(root.left,ans);
        onechild(root.right,ans);
    }

    public static ArrayList<Integer>  onechild(treenode root)
    {
        ArrayList<Integer> ans=new ArrayList<>();
        onechild(root,ans);
        return ans;
    }

//                    K distance from the root all nodes

    public static void kdown(treenode root,int k,treenode block,List<Integer>ans)
    {
        if(root==null || k<0 || root==block)
        return;

        if(k==0)
        {
            ans.add(root.val);
            return;
        }
        kdown(root.left,k-1,block,ans);
        kdown(root.right,k-1,block,ans);
    }

    public static int kdistance(treenode root, treenode target ,int k, List<Integer>ans)
    {
        if(root==null)
           return -1;

        if(root==target)
        {
            kdown(root,k,null,ans);
            return 1;
        }   
        int l=(kdistance(root.left,target,k,ans));
        if(l!=-1)
        {
            kdown(root,k-l,root.left,ans);
            return l+1;
        }
        int r=(kdistance(root.left,target,k,ans));
        if(l!=-1)
        {
            kdown(root,k-r,root.left,ans);
            return r+1;
        }
        return -1;
    }
    public static void main(String[] args)
    {
        
    }
}