import java.util.*;
class test
{
    public static int solve(int[] arr,int target,int idx,int max,int ans)
    {
        if(arr.length==0)
        return -1;
        if(target>0)
        return 0;
            if(target==0)
             {
                if(max<=ans)
                {
                    max=ans;
                    return max;
                }
                return max;
             }

        if(idx<arr.length)
        {
            if(tar-idx>=0){ 
           solve(arr,target-idx,idx+1,max,ans+arr[idx-1]);
           solve(arr,target,idx+1,max,ans);
            }

        }
        return max;
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int t=scn.nextInt();
        while(t-->0)
        {
            int n=scn.nextInt();
            int[] arr =new int[n];
            for(int i=0;i<n;i++)
            {
                 arr[i]=scn.nextInt();
            }
            System.out.print(solve(arr,n,1,0,0));

        }
        
    }
}