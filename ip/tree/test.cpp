#include<iostream>
#include<algorithm>
using namespace std;
void test(int arr[],int s) // {2,4,1,68,23,45,22,34,12}
 {

     int i,j;
     int mi=*min_element(arr,arr+s);
      int arr2[s];
     int idx;
     for(int i=0;i<s;i++)
    {
        if(mi==arr[i])
        idx=i+1;
    }
   
    int maxi=0,mini=99999;
     for( i=idx-1;i<s;i++)
     {  
        for(int i=0;i<s;i++)
        {
           if(mi==arr[i])
           idx=i+1;
        } 
          for(int l=0;l<idx-1;l++)
        {
        arr2[l]=arr[idx-1];
        }
         for( j=i+1;j<s-1;j++)
         {   
             mini=(mini,min(arr[i],arr[j]));
             maxi=(maxi,max(arr[i],arr[j]));
             
             if(i==s-1)
            {
              maxi=arr[i];
              mini=arr[i];
            }
         }
         if(i==s-1)
            { 
               arr2[s-1]=-arr[s-1];
            }
           else if(maxi==arr[i])
            {
               arr2[i]=-maxi;
            }
            else if (mini==arr[i])
            {
                arr2[i]=arr[j];
            }
     }
     
     for(int k=0;k<s;k++)
     {
         cout<<arr2[k]<<" ";
     }
 }
 int main()
 {
    int arr[]={2,4,1,68,23,45,22,34,11};
    int size=sizeof(arr)/sizeof(arr[0]);
    test(arr,size);
    return 0;
 }