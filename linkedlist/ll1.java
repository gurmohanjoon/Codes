import java.util.*;
class ll1
{
    public static class linkedlist
    {
        int val;
        linkedlist next=null;
        linkedlist(int val)
        {
            this.val=val;
        }
    }
    public static linkedlist midNode(linkedlist head) {
        if(head==null || head.next==null)
        return head;
        linkedlist fast=head,slow=head;
         while(fast.next != null && fast.next.next != null)
         {
             fast=fast.next.next;
             slow=slow.next;
         }
         return slow;
     }
     public static linkedlist reverseList(linkedlist head) {
        if (head == null || head.next == null)
            return head;
            linkedlist prev = null, curr = head;
        while (curr != null) {
            linkedlist forw = curr.next; // backup
            curr.next = prev; // link
            prev = curr; // move
            curr = forw;
        }
        return prev;
    }
    public boolean isPalindrome(linkedlist head) {
        if(head==null && head.next == null)
            return true;
        boolean flag = true;
        linkedlist mid =midNode(head);
        linkedlist nhead=mid.next;
        mid.next=null;
        nhead = reverseList(nhead);
        linkedlist c1=head,c2=nhead;
        while(c1 != null && c2 != null)
        {
            if(c1.val != c2.val)
            { 
                flag=false;
                break;
            }
            c1=c1.next;
            c2=c2.next;
        }
        nhead = reverseList(nhead);
        mid.next=nhead;
        return flag;
    }
    public void fold(linkedlist head) {
        if(head==null && head.next == null)
            return;
        boolean flag = true;
        linkedlist mid =midNode(head);
        linkedlist nhead=mid.next;
        mid.next=null;
        nhead = reverseList(nhead);
        linkedlist c1=head,c2=nhead;
        while(c1 != null && c2!= null)
        {
            linkedlist f1=c1.next,f2=c2.next;
            c1.next=c2;
            c2.next=f1;
            c1=f1;
            c2=f2;
        }
    }
    public static void unfold(linkedlist head)
    {
         if(head == null && head.next ==null)
         return ;
         linkedlist c1=head,c2=head.next,nhead=c2;
         while(c1!=null && c2!= null)
         {
             linkedlist f1=c2.next;
             c1.next=f1;
             c2.next=f1.next;

             c1=f1;
             c2=c1.next;
         }
         c1.next=null;
         nhead=reverseList(nhead);
         c1.next=nhead;
    }
    public static 
    public static void main(String[] args)
    {
          
    }
}