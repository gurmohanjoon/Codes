import java.util.*;
class r7
{
    public static boolean issafetoplace(char[][] board,int r,int c,int num)
    {
        //row
        for(int i=0;i<9;i++)
        {
         if(board[r][i]-'0'==num)                 
             return false;
        }
        //col
        for(int i=0;i<9;i++)
        {
                if(board[i][c]-'0'==num)
                return false;
        }    
        //matrix
         r=(r/3)*3;
                c=(c/3)*3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[r+i][c+j]-'0'==num)
                    return false;
            }
        }
    return true;
    
    }
    public static boolean solvesudoku(char[][] board,ArrayList<Integer> emptyindex,int idx) {
        if(idx==emptyindex.size())
            return true;
        int cell=emptyindex.get(idx);
        int r=cell/9;
        int c=cell%9;
        for(int num=1;num<=9;num++)
        {
            if(issafetoplace(board,r,c,num))
            {
                board[r][c]=(char)(num+'0');
                if(solvesudoku(board,emptyindex,num+1))
                    return true;
                board[r][c]='.';
                
            }
        }
        return false; 
    }
    public static void solvesudoku(char[][] board)
    {
        ArrayList<Integer> emptyindex=new ArrayList<>();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    emptyindex.add(i*9+j);
            }
        }
        solvesudoku(board,emptyindex,0);
    }
    public static void main(String[] args)
    {
       

        //solvesudoku(board);

    }
}