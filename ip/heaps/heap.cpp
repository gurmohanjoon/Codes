#include<iostream>
#include<vector>
using namespace std;
class Heap
{ 
    vector<int> v;
    bool minHeap;
    bool compare(int a,int b)
    {
        if(minHeap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }
        void heapify(int idx)
        {
            int left=2*idx;
            int right=left+1;
            int min=idx;
            int last=v.size()-1;  
             if(left<=last && compare(v[left],v[idx]))
             {
                 min=left;
             }
             if(right<=last && compare(v[right],v[min]))
             {
                 min=right;
             }
             if(min!=idx)
             {
                 swap(v[idx],v[min]);
                 heapify(min);
             }
        }
    
    public:
         Heap(int size=10,bool type=true)
         {
             v.reserve(size);
             v.push_back(-1);
             minHeap=type;
         }
         void push(int d)
         {
             v.push_back(d);
             int idx=v.size()-1;
             int parent=idx/2;
             while(idx>1 and compare(v[idx],v[parent]))
             {
                 swap(v[idx],v[parent]); 
                 idx=parent;
                 parent=parent/2; 
             }

         }
         int top()
         {
             return v[1];
         }
         void pop()
         {
             int last=v.size()-1;
             swap(v[1],v[last]);    
             v.pop_back();
             heapify(1);
         }
         bool empty()
         {
             return v.size()==1;
         }
};
int main()
{
    Heap h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}
