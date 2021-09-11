import java.util.LinkedList;

class tree3
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
    public static treenode getrightmost(treenode node,treenode curr)
    {
        while(node.right !=null && node.right != curr)
        {
            node=node.right;
        }
        return node;
    }
    public boolean isValidBST(treenode root) 
    {
        treenode curr = root;
        long prev=-(long)1e13;
        while(curr!=null)
        {
            treenode left=curr.left;
            if(left==null)
            {
                if(prev>=curr.val)
                    return false;
                prev=curr.val;
                curr=curr.right;
                
            }
            else
            {
                treenode rightmost=getrightmost(left,curr);
                if(rightmost.right==null)
                {
                    rightmost.right=curr;
                    curr=curr.left;
                }
                
                else
                {
                    rightmost.right=null;
                    if(prev>=curr.val)
                        return false;
                    prev= curr.val;    
                    curr=curr.right;
                }
            }
        }
        return true;
    }
    public void insertleft(treenode root,LinkedList<treenode> st)
    {
        while(root!=null)
        {
            st.addFirst(root);
            root=root.left;
        }

    }
    public boolean isValidBST2(treenode root)
    {
        LinkedList<treenode> st=new LinkedList<>();
        insertleft(root,st);
        long pre=-(int)1e13;
        while(st.size() != 0)
        {
            treenode rnode=st.removeFirst();
            if(pre>=rnode.val)
               return false;
            pre=rnode.val;
            insertleft(rnode,st);
        }
        return true;
    }

    Excel clone is built using electron framework with technologies such as HTML, CSS, JQuery and Ejs as a templating engine .

}