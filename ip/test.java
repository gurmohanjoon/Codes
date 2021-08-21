import java.util.*;
class test
{
    public static void pair(String s)
    {
        int count=0;
        int Rpair=0;
        int Lpair=0;
        int size=s.length();
        
        for(int i=0;i<size;i++)
        { 
            for(int j=0;j<size;j++)
            {
                int a=s.charAt(i);
                int b=s.charAt(i);
                if(a==b && a=='R')
                {
                    Rpair++;
                
                }
                if(a==b && a=='L')
                {
                    Lpair++;
                
                }

            }
            if(Rpair==Lpair)
            {
                count++;
            }

            
        }
            
   
    }
}