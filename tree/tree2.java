            //      BST
import java.lang.reflect.Array;
import java.util.*;
import java.util.ArrayList;
class tree2
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

    //              MAX Element in BST
   public static int max(treenode root)
   {
       treenode curr=root;
       while(curr.right!=null)
       {
           curr=curr.right;
       }
       return curr.val;
   }
   //                   MIN element in bst
   public static int min(treenode root)
   {
       treenode curr=root;
       while(curr.left!=null)
       curr=curr.left;
       return curr.val;
   }

   //                  find data in bst
   public static boolean find(treenode root,int data)
   {
        treenode curr=root;
        while(curr!=null)
        {
            if(curr.val==data)
            return true;        
            else if(curr.val<data)
            curr=curr.left;
            else 
            curr=curr.right;

        }
        return false;
   }
   
   //                 node to root path
   public static ArrayList nodetorootpath(treenode root,int data,ArrayList<Integer> ans)
   {
      treenode curr=root;
      while(curr!=null)
      {
          ans.add(curr.val);
          if(curr.val==data)
          break;
          else if(curr.val<data)
          curr=curr.right;
          else
          curr=curr.left;
      }
      return ans;

   }

   //               LCA of BST

   public static treenode lca(treenode root,treenode p,treenode q)
   {
       treenode lca=null,curr=root;
       while(curr!=null)
       {
           if(curr.val<p.val && curr.val<q.val)
           curr=curr.right;
           else if(curr.val>p.val && curr.val>q.val)
           curr=curr.left;
           else
           {
               lca=curr;
               break;
           }
       }
       return (lca!=null && find(lca,p.val) && find(lca,q.val)) ? lca : null;
   }
}

//            