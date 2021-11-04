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
    //return dp[n];

}
int main()
{
    int n;
    cin>>n;
    int dp[100]={0};
   // cout<<fab(n,dp);
   //cout<<fab2(n);
  cout<< ministeps(n,dp);
}