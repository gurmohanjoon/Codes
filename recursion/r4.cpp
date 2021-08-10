#include<iostream>
#include<vector>
using namespace std;
int queenCombination(int tnb,int tnq,int bno,int qno,string ans)
{
    if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=bno;i<tnb;i++)
    {
        count +=queenCombination(tnb,tnq,i+1,qno+1,ans+"b"+to_string(i)+"q"+to_string(qno)+" ");
    }
    return count;
}
int queenPermutation(vector<bool>&boxes,int tnq,int bno,int qno,string ans)
{
      if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=bno;i<boxes.size();i++)
    {
        if(!boxes[i])
        {
            boxes[i]=true;
            count +=queenPermutation(boxes,tnq,0,qno+1,ans+"b"+to_string(i)+"q"+to_string(qno));
            boxes[i]=false;
       }
    }
    return count;
}
int queencombination2d(vector<vector<bool>>&board,int tnq,int bno,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0,n=board.size(),m=board[0].size();
    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
        count +=queencombination2d(board,tnq ,i+1,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
    }
    return count;
}
int queenpermutation2d(vector<vector<bool>>&board,int tnq,int bno,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0,n=board.size(),m=board[0].size();
    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
        if(!board[r][c])
        {
            board[r][c]=true;
            count +=queenpermutation2d(board,tnq,0,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
            board[r][c]=false;
        }
    }
    return count;
}
void queenCombination()
{
    int tnb = 5, tnq = 3;
    vector<bool> boxes(tnb, false);
    //cout << queenCombination(tnb, tnq, 0, 0, "") << endl;
    //cout << queenPermutation(boxes, tnq, 0, 0, "") << endl;
    vector<vector<bool>> board(4,vector<bool>(4,false));
     //cout<< queencombination2d(board,4,0,0,"")<<endl;
     cout<< queenpermutation2d(board,4,0,0,"")<<endl;
}


//                          Queen safe

bool isqueensafe(vector<vector<bool>> board,int row,int col)
{
    int n=board.size(),m=board[0].size();
    //vector<vector<int>> dir= {{-1,0},{-1,-1},{0,-1,},{-1,1}};
    vector<vector<int>> dir= {{-1,0},{-1,-1},{0,-1,},{-1,1},{1,0},{1,1},{0,1,},{1,-1}};
    for(int d=0;d<dir.size();d++)
    {
        for(int rad=1;rad<board.size();rad++)
        {
           int r=row+rad*dir[d][0];
           int c=col+rad*dir[d][1];
           if(r>=0 && c>=0 && r<n &&c<m)
           {
                if(board[r][c])
                return false;
           }
           else
           break;
        }
    }
    return true;

}
int nQueen_1combi(vector<vector<bool>>&board,int tnq,int bno,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0,n=board.size(),m=board[0].size();
    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
            
            if(isqueensafe(board,r,c))
            {
                    board[r][c]=true;
                    count +=nQueen_1combi(board,tnq,i+1,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
                    board[r][c]=false;
            }
    }
    return count;
}

int nQueen_1permu(vector<vector<bool>>&board,int tnq,int bno,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0,n=board.size(),m=board[0].size();
    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
            if(isqueensafe(board,r,c)&& !board[r][c])
            {
                board[r][c]=true;
                count +=nQueen_1permu(board,tnq,0,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
                board[r][c]=false;
            }
    }
    return count;
}

int nQueen_1combi_sub(vector<vector<bool>>&board,int tnq,int idx,int qno,string ans)
{
     int count = 0,n=board.size(),m=board[0].size();
     if(qno==tnq || idx==n*m)
    {
        if(qno==tnq)
        cout<<ans<<endl;
        return tnq==qno?1:0;
    }
    //int count = 0,n=board.size(),m=board[0].size();
        int r=idx/m;
        int c=idx%m;
            
            if(isqueensafe(board,r,c))
            {
                    board[r][c]=true;
                    count +=nQueen_1combi_sub(board,tnq,idx+1,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
                    board[r][c]=false;
            }
             count +=nQueen_1combi_sub(board,tnq,idx+1,qno,ans);
    return count;
}

int nQueen_1permu_sub(vector<vector<bool>>&board,int tnq,int idx,int qno,string ans)
{
     int count = 0,n=board.size(),m=board[0].size();
     if(qno==tnq || idx==n*m)
    {
        if(qno==tnq)
        cout<<ans<<endl;
        return tnq==qno?1:0;
    }
    //int count = 0,n=board.size(),m=board[0].size();
        int r=idx/m;
        int c=idx%m;
            if(isqueensafe(board,r,c)&& !board[r][c])
            {
                board[r][c]=true;
                count +=nQueen_1permu_sub(board,tnq,0,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
                board[r][c]=false;
            }
             count +=nQueen_1permu_sub(board,tnq,idx+1,qno,ans);
    return count;
}

vector<bool> row;
vector<bool> col;
vector<bool> dia;
vector<bool> adia;
int nQueen_2combi(int n,int m,int tnq,int idx,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=idx;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
            
            if(!row[r]&&!col[c]&&!dia[r+c]&&!adia[r+c+m-1])
            {
                    row[r]=col[c]=dia[r+c]=adia[r+c+m-1]=true;
                    count +=nQueen_2combi(n,m,tnq,i+1,qno+1,ans+"("+to_string(r)+" , "+to_string(c)+") ");
                    row[r]=col[c]=dia[r+c]=adia[r+c+m-1]=false;
            }
    }
    return count;
}

int nQueen_2permu(int n,int m,int tnq,int bno,int qno,string ans)
{
     if(qno==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;
            if(!row[r]&&!col[c]&&!dia[r+c]&&!adia[r+c+m-1])
            {
                row[r]=col[c]=dia[r+c]=adia[r+c+m-1]=true;
                count +=nQueen_2permu(n,m,tnq,0,qno+1,ans+" ("+to_string(r)+" , "+to_string(c)+") ");
                row[r]=col[c]=dia[r+c]=adia[r+c+m-1]=false;
            }
    }
    return count;
}

int nQueen_3combi(int n,int m,int tnq,int floor,string ans)
{
     if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for (int room = 0; room < m; room++)
    {
        int r = floor, c = room;
        if (!row[r] && !col[c] && !dia[r + c] && !adia[r - c + m - 1])
        {
            row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = true;
            count += nQueen_3combi(n, m, tnq - 1, floor + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = false;
        }
    }
    return count;
}
int nQueen_3permu(int n,int m,int tnq,int r,string ans)
{
    //  int r = floor;
    //  if(tnq==0||r==n)
    // {
    //     if(tnq==0)
    //     cout<<ans<<endl;
    //     return tnq==0?1:0;
    // }
    // int count = 0;
    // for (int room = 0; room < m; room++)
    // {
    //         count += nQueen_3permu(n, m, tnq, r + 1, ans);

    //     int c = room;
    //     if (!row[r] && !col[c] && !dia[r + c] && !adia[r - c + m - 1])
    //     {
    //         row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = true;
    //         count += nQueen_3permu(n, m, tnq - 1, 0, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
    //         row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = false;
    //     }

    // }
    // return count;
    if (tnq == 0 || r == n)
    {
        if (tnq == 0)
            cout << ans << endl;
        return tnq == 0 ? 1 : 0;
    }

    int count = 0;
    // calls++;

    count += nQueen_3permu(n, m, tnq, r + 1, ans);

    for (int c = 0; c < m; c++)
    {
        if (!row[r] && !col[c] && !dia[r + c] && !adia[r - c + m - 1])
        {
            row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = true;
            count += nQueen_3permu(n, m, tnq - 1, 0, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = dia[r + c] = adia[r - c + m - 1] = false;
        }
    }

    return count;
}
void nQueen()
{
    int n=4,m=4;
    vector<vector<bool>> board(n,vector<bool>(m,false));
    //cout<<nQueen_1combi(board,4,0,0,"");
    //cout<<nQueen_1permu(board,4,0,0,"");
   //cout<<nQueen_1combi_sub(board,4,0,0,"");
    //cout<<nQueen_1permu_sub(board,4,0,0,"");
    row.resize(n,false);
    col.resize(n,false);
    dia.resize(n,false);
    adia.resize(n,false);
    // cout<<nQueen_2combi(n,m,3,0,0,"");
    // cout<<nQueen_2permu(n,m,3,0,0,"");
    //cout<<nQueen_3combi(n,m,3,0,"");
        cout<<nQueen_3permu(n,m,3,0,"");


}


int main()
{
    //queenCombination();
    nQueen();
    return 0;
}
