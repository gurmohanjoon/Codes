import java.util.*;
class r4
{
    public static int permutatuioninfcoin(int[] arr,int tar,String ans)
    {
        if(tar==0)
       {
           System.out.println(ans);
           return 1;

       }
        int count =0;
        for(int i:arr)
        {
            if(tar-i>=0)
            count+=permutatuioninfcoin(arr,tar-i,ans+i);
        }
        return count;
    }
    public static int combinationinfcoin(int[] arr,int tar,int idx, String ans)
    {
        if(tar==0)
       {
           System.out.println(ans);
           return 1;

       }
        int count =0;
        for(int i=idx;i<arr.length;i++)
        {
            if(tar-arr[i]>=0)
            count+=combinationinfcoin(arr,tar-arr[i],i,ans+arr[i]);
        }
        return count;
    }
    public static int permutatuionsinglecoin(int[] arr,int tar,String ans)
    {
        if(tar==0)
       {
           System.out.println(ans);
           return 1;

       }
        int count =0;
        for(int i=0;i<arr.length;i++)
        {
           
            if(arr[i]>0 && tar-arr[i]>=0)
            {
                int val=arr[i];
                arr[i]=-val;
                count+=permutatuionsinglecoin(arr,tar-val,ans+val);
                arr[i]=val;
            }
        }
        return count;
    }
    public static int combinationsinglecoin(int[]arr,int tar,int idx,String ans)
    {
        if(tar==0)
       {
           System.out.println(ans);
           return 1;

       }
        int count =0;
        for(int i=0;i<arr.length;i++)
        {
            if(tar-arr[i]>=0)
            count+=combinationinfcoin(arr,tar-arr[i],i+1,ans+arr[i]);
        }
        return count;
    }
    //sub sequence part=======================================================================================================================
    public static int combinationsinglecoin_sub(int[]arr,int tar,int idx,String ans)
    {
        if(tar==0 || idx==arr.length)
       {
           if(tar==0)
           {
           System.out.println(ans);
           return 1;
           }
           return 0;

       }
        int count =0;
            if(tar-arr[idx]>=0)
            count+=combinationsinglecoin_sub(arr,tar-arr[idx],idx+1,ans+arr[idx]);
            count+=combinationsinglecoin_sub(arr,tar,idx+1,ans);
        return count;
    }
    public static int combinationinfcoin_sub(int[]arr,int tar,int idx,String ans)
    {
        if(tar==0 || idx==arr.length)
       {
           if(tar==0)
           {
           System.out.println(ans);
           return 1;
           }
           return 0;

       }
        int count =0;
            if(tar-arr[idx]>=0)
            count+=combinationinfcoin_sub(arr,tar-arr[idx],idx,ans+arr[idx]);
            count+=combinationinfcoin_sub(arr,tar,idx+1,ans);
        return count;
    }
    public static int permutatuionsinglecoin_sub(int[] arr,int tar,int idx,String ans)
    {
        if(tar==0 || idx==arr.length)
        {
            if(tar==0)
            {
            System.out.println(ans);
            return 1;
            }
            return 0;
 
        }
         int count =0;
         
             if(arr[idx]>0 && tar-arr[idx]>=0)
 
             {
                 int val=arr[idx];
                 arr[idx]=-val;
             count+=permutatuionsinglecoin_sub(arr,tar-val,0,ans+val);
             arr[idx]=val;
             }
             count+=permutatuionsinglecoin_sub(arr,tar,idx+1,ans);

         return count;
       
    }
    public static int permutatuioninfcoin_sub(int[] arr,int tar,int idx,String ans)
    {
        if(tar==0 || idx==arr.length)
        {
            if(tar==0)
            {
            System.out.println(ans);
            return 1;
            }
            return 0;
 
        }
         int count =0;
             if(tar-arr[idx]>=0)
             count+=permutatuioninfcoin_sub(arr,tar-arr[idx],0,ans+arr[idx]);
             count+=permutatuioninfcoin_sub(arr,tar,idx+1,ans);
         return count;
    }
    public static void percom()
    {
        int[] arr={2,3,5,7};
        //System.out.println(permutatuioninfcoin(arr,10,""));
      //System.out.println(combinationinfcoin(arr,10,0,""));
      // System.out.println(permutatuionsinglecoin(arr,10,""));
       //System.out.println(combinationsinglecoin(arr,10,0,""));
       ///////////////                                                 Subseq part
       System.out.println(combinationsinglecoin_sub(arr,10,0,""));
       System.out.println(permutatuionsinglecoin_sub(arr,10,0,""));
       System.out.println(permutatuioninfcoin_sub(arr,10,0,""));
       System.out.println(combinationinfcoin_sub(arr,10,0,""));
    } 
    public static void main(String[] args)
    {
        percom();

    }
}