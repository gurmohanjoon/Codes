import java.util.*;
class r1
{
    public static void count(int n)
    {
        if(n==0) return;
        System.out.print(n+" ");
        count(n-1);
    }
    public static void oddeven(int n)
    {
        if(n==0) return;
        if(n%2==0) System.out.println(n);
        oddeven(n-1);
        if(n%2!=0) System.out.println(n);
    }
    public static int factorial(int n)
    {
        return n==0?1:factorial(n-1) * n;
    }
    public static int power(int a,int b)
    {
        return b==0 ? 1 : power(a,b-1) * a;
    }
    public static int maxelement(int[] arr,int idx)
    {
        if (idx==arr.length) return -(int)1e9;
        return Math.max(arr[idx],maxelement(arr,idx+1));
    }
    public static int minelement(int[] arr,int idx)
    {
        if (idx==arr.length) return (int)1e9;
        return Math.min(arr[idx],minelement(arr,idx+1));
    }
    public static void subseq(int[] arr)
    {
                    
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        //count(scn.nextInt());
        //oddeven(scn.nextInt());
        //System.out.println(factorial(scn.nextInt()));
        System.out.println(power(scn.nextInt(),scn.nextInt()));
    }
}