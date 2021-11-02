#include<iostream>
#include<list>
using namespace std;
class graph
{
    int v;
    list<int> *l;
    public:
    graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int nbr:l[i])
            cout<<nbr<<",";
            cout<<endl;
        }

    }
};
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,3);
    g.print();

    return 0;
}

 //             Destination and distance

 #include <iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

class graph
{
  map<string,list<pair<string,int>>> l;  
  public:
    void addedge(string x,string y,bool res,int n)
    {
        l[x].push_back(make_pair(y,n));
        if(res)
        {
            l[y].push_back(make_pair(x,n));
        }
    }
    void print()
    {
        for(auto p:l)
        {
            string city=p.first;
            list<pair<string,int>> nbrs=p.second;
            cout<<city<<"-> ";
            for(auto nbr:nbrs)
            {
                string dest=nbr.first;
                int dist=nbr.second;
                cout<<dest<<" "<<dist<<",";
                
            }
            cout<<endl;
        }
    }
};

int main() {
	graph g;
	g.addedge("A","B",true,20);
	g.addedge("A","C",true,10);
	g.addedge("B","D",true,30);
	g.addedge("C","D",true,40);
	g.addedge("A","D",false,50);
	g.print();
	return 0;
}


