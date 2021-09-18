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
    public static void main(String[] args)
    {
          
    }
}