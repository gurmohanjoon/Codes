#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public: 
        string key;
        T value;
        Node<T> * next;

        Node(string key,T val)
        {
            this->key=key;
            value=val;
            next = NULL;
        }
        ~Node()
        {
            if(next!=NULL)
            {
                delete next;
            }
        }
        
};

int main()
{
    
}