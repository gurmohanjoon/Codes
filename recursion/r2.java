import java.util.*;
class r2
{
    private static int sr;
    private static int sc;
    private static int er;
    private static int ec;
    //Mazepath methods
    public static ArrayList<String> mazePath_hvd(sr,sc,er, ec)
    {
        if(sr==er&&sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> myans=new ArrayList<>(); 
        if(sr+1 <=er)
        {
            ArrayList<String> Vertical=mazePath_hvd(sr+1,sc,er,ec);
            for(String s: Vertical)
            myans.add("V"+s);
        }
        ArrayList<String> myans=new ArrayList<>(); 
        if(sr+1 <=er && sc+1<=ec)
        {
            ArrayList<String> Diagonal=mazePath_hvd(sr+1,sc+1,er,ec);
            for(String s: Diagonal)
            myans.add("D"+s);
        }
        ArrayList<String> myans=new ArrayList<>(); 
        if(sc+1 <=ec)
        {
            ArrayList<String> Horizontal=mazePath_hvd(sr,sc+1,er,ec);
            for(String s: Horizontal)
            myans.add("H"+s);
        }

    }
    public static void mazepath_hvd( sr, sc, er,ec)
    {
        
    }
    public static ArrayList<String> mazePath_hvd_multi(sr,sc,er,ec)
    {

    }
    public static void mazePath_hvd_multi( sr, sc, er, ec)
    {

    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);

    }
}