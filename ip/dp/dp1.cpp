#include<bits/stdc++.h>
using namespace std;

//   Fibonic Series

int fab(int n,int dp[])
{
    if(n==0 || n==1)
       return n;
    if(dp[n]!=0)
       return dp[n];
    dp[n]=fab(n-1,dp)+fab(n-2,dp);
    return dp[n];
}
int fabbu(int n)
{
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fab2(int n)
{
   int a=0,b=1,c;
   for(int i=2;i<=n;i++)
   {
       c=a+b;
       a=b;
       b=c;
   }
   return c;
}

//                  Minimum steps to one  n-> n/3 n/2 n-1

int ministeps(int n,int dp[])      // top down approach
{
    if(n==1)
      return 0;
   int op1,op2,op3;
   op1=op2=op3=INT_MAX;        // #include<climits>
   if(dp[n]!=0)
   return dp[n];
   if(n%3==0)
      op1=ministeps(n/3,dp)+1;
    if(n%2==0)
      op2=ministeps(n/2,dp)+1;
    op3=ministeps(n-1,dp)+1;

    return dp[n]=min(min(op1,op2),op3);

}
int ministeps2(int n)
{
    int dp[100] ={0};
    dp[1]=0;
    

    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
         op1=op2=op3=INT_MAX;
       if(n%3==0)
          op1=dp[i-3];
        if(n%2==0)
           op2=dp[i-2];
        op3=dp[i-1];

         dp[i]=min(min(op1,op2),op3)+1;   
         
    }
    return dp[n];
}

// Minimum coin change
int minicoins(int target,int coins[],int t,int dp[])
{
    if(target==0)
       return 0;

    int ans=INT_MAX;

    if(dp[target] != 0)
      return dp[target];

    for(int i=0;i<t;i++)
    {
        if(target-coins[i] >= 0)
        {
            int temp=minicoins(target-coins[i],coins,t,dp);
            ans=min(ans,temp+1);
        }
        dp[target]=ans;
    }
    
    return dp[target];
}

int minicoins2(int n,int coins[], int t)
{
    int dp[100]={0};

     if(dp[n] != 0)
       return dp[n];

    for(int i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<t;j++)
        {
            if(i-coins[j]>=0)
            {
                int temp=dp[i-coins[j]];
                dp[i]=min(dp[i],temp+1);
            }
        }
    }
        return dp[n];
    }   
    
//             Wines Problem
int wineprofit(int wines[],int i,int j,int y,int dp[][100])
{
    if(i>j)
      return 0;

      if(dp[i][j]!=0)
         return dp[i][j];

    int op1=wines[i]*y + wineprofit(wines,i+1,j,y+1,dp);
    int op2=wines[j]*y + wineprofit(wines,i,j-1,y+1,dp);
     return dp[i][j] = max(op1,op2);

}    

//    maximum sub array

int maxsub(int arr[], int n)
{
    int dp[100]={0};
    int maxi=arr[0]>0?arr[0]:0;

    for(int i=1;i<n;i++)
    { dp[i]=dp[i-1] + arr[i];
    if(dp[i]<0)
       dp[i]=0;
    maxi=max(dp[i],maxi);   

    }
    return maxi;
}

int main()
{
    int n;
   // cin>>n;
    //int dp[100]={0};
   // cout<<fab(n,dp);
   //cout<<fab2(n);
 // cout<< ministeps(n,dp);
    //cout<<ministeps2(n);
    // int arr[] = {1,7,10};
    // cout<<minicoins(n,arr,3,dp);
    //cout<<minicoins2(n,arr,3);
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    n=sizeof(arr)/sizeof(int);
    // int dp[100][100]={0};
    // cout<<wineprofit(arr,0,n-1,1,dp);
    cout<<maxsub(arr,n);
    return 0;
    

}