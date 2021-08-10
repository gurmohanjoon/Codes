import java.util.*;
class r6
{
    public static void leftshift()
    {
        
        int mask;
       // mask ^= (5);
       // System.out.println(mask);



    }
    public static void rightshift()
    {
        int m=-80;
        //while(m!=0){
        // for(int i=1;i <= 4;i++)
        // {
        //     System.out.println((m>>>i));
        // }  
        System.out.println(m+"a "+(m>>=1));
        System.out.println(m+"b "+(m>>>=1));
       // }

    }
    public int hammingWeight(int n) {
        int count =0;
        for(int i=0;i<32;i++)
        {
            if((n & (1<<i))!=0)
                count++;
        }
        //System.out.print(count);
        return count;
    }

public static int[] countBits(int n)
{
    int[] count=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        int c=0;
      
       for(int j=0;j<32;j++)
       {
          // c=0;
           int m=i;
           if((i & (m<<j)) !=0)
               c++;
       }
        count[i]=c;       
    }
    return count;
}
public static int singleNumber(int[] nums) {
      int  ans=0;       ;
  
        //for(int i:nums)
            ans ^=(6);
           // ans ^=(6);

    return ans;
}


    public static void main(String[] args)
    {
        //leftshift();
       // rightshift();
        //System.out.print(countBits(3));
        //ispoweroftwo(int n) 
        int arr[] ={4,1,1,2,7,7,4};
        System.out.print(singleNumber(arr));



    }  
}