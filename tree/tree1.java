import java.lang.reflect.Array;
import java.util.*;
import java.util.ArrayList;
class tree1
{
    public static class treenode
    {
        int val;
        treenode left;
        treenode right;
        treenode(int val)
        {
            this.val=val;
            left=null;
            right=null;
        }
    }

//                   Create tree

    public static treenode createtree()
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
    public static ArrayList<treenode> nodetorootpath(treenode root,int data)
    {
        ArrayList<treenode> ans=new ArrayList<>();
        nodetorootpath(root,ans,data);
        return ans;
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
    public static List<Integer> kdistance2(treenode root,treenode target,int k)
    { 
        ArrayList<treenode> path = new ArrayList<>();
        path=nodetorootpath(root,target.val);
        List<Integer> ans = new ArrayList<>();
        treenode block=null;
        for(int i=0;i<path.size();i++)
        {
            kdown(path.get(i),k-i,block,ans);
            block=path.get(i);
        }
        return ans;
    }

    //       Burning tree 

   public static void burningtreenode(treenode root,int time,treenode blockode,ArrayList<ArrayList<Integer>> ans)
   {
       if(root==null || root==blockode)
         return ;
       if(time==ans.size())
          ans.add(new ArrayList<>());
        ans.get(time).add(root.val);
        
        burningtreenode(root.left, time+1, blockode, ans);
        burningtreenode(root.right, time+1, blockode, ans);
         

   }
   public static int burningtreenode(treenode root,int firenode,ArrayList<ArrayList<Integer>>ans)
   {
        if(root==null)
        return -1;
        if(root.val==firenode)
        {
            burningtreenode(root,0,null,ans);
            return 1;
        }
        int lt=burningtreenode(root.left, firenode, ans);
        if(lt!=-1)
        {
            burningtreenode(root, lt, root.left, ans);
            return lt+1;
        }
        int rt=burningtreenode(root.right, firenode, ans);
        if(rt!=-1)
        {
            burningtreenode(root, rt, root.right, ans);
            return rt+1;
        }
        return -1;
   }
   public static void burningtreenode(treenode root,int data)
   {
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        burningtreenode(root,data,ans);
   }

   //                      Node with water and ice
   
   public static void burningtreewithwater(treenode root,int time,treenode blockode,HashSet<Integer> waterset,ArrayList<ArrayList<Integer>> ans)
   {
       if(root==null || root==blockode || waterset.contains(root.val))
         return ;
       if(time==ans.size())
          ans.add(new ArrayList<>());
        ans.get(time).add(root.val);
        
        burningtreenode(root.left, time+1, blockode, ans);
        burningtreenode(root.right, time+1, blockode, ans);
         

   }
   public static int burningtreewithwater(treenode root,int firenode,HashSet<Integer> waterset,ArrayList<ArrayList<Integer>>ans)
   {
        if(root==null)
        return -1;
        if(root.val==firenode)
        {
            if(!waterset.contains(root.val))
            {
              burningtreewithwater(root,0,null,waterset,ans);
              return 1;
            }
            return -2;
        }
        int lt=burningtreewithwater(root.left, firenode,waterset, ans);
        if(lt>0)
        {
            if(!waterset.contains(root.val))
            {
                burningtreewithwater(root, lt, root.left,waterset, ans);
                return lt+1;
            }
            return -2;
        }
        if(lt==-2)
        {return -2;}
        int rt=burningtreewithwater(root.right, firenode,waterset, ans);
        if(rt!=-1)
        {
            if(!waterset.contains(root.val))
            {
                burningtreewithwater(root, rt, root.right,waterset, ans);
                return rt+1;
            }
            return -2;
        }
        if(rt==-2)
        {return -2;}
        return -1;
   }

   public static void burningtreewithwater(treenode root,int data)
   {
       HashSet<Integer> waterset = new HashSet<>();
       ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

       burningtreewithwater(root,data,waterset,ans);
       System.out.println(ans);
   }

   //            Lowest Common Ancesstor
   treenode lcanode;
   public boolean lca(treenode root,treenode p,treenode q)
   {
      if(root==null)
      return false;
      boolean self=(root==p||root==q);
      boolean left=lca(root.left,p,q);
      {
          if(lcanode!= null)
          return true;
      }
      boolean right=lca(root.right,p,q);
      {
        if(lcanode!= null)
        return true;
      }
      if((left && right) || (left && self) || (right && self))
      {
          lcanode=root;
      }
      return left||right||self;
    }

    public static void main(String[] args)
    {
        treenode t;
        treenode root=createtree();
        // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
       // 1 2 4 6 -1 -1 7 10 -1 -1  11 -1 -1 5 8 -1 -1 9 -1 -1  3 -1 -1
       print(root);

        //return 0;
    }
}