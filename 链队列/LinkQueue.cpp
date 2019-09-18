#include<iostream>
using namespace std;
#include "LinkQueue.h"

template<class DataType>
LinkQueue<DataType>::LinkQueue()
{
    Node <DataType> *s=NULL;
    s=new Node<DataType>;
    s->next=NULL;
    front=rear=s;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue()
{
    Node<DataType> *p=NULL;
    while(front!=NULL)
    {
        p=front->next;
        delete front;
        front=p;
    }
}

template<class DataType>
void LinkQueue<DataType>::EnQueue(DataType x)
{
    Node<DataType> *s=NULL;
    s=new Node <DataType>;
    s->data=x;
    s->next=NULL;
    rear->next=s;
    rear=s;
}

template <class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
    Node <DataType> *p=NULL;
    int x;
    if(rear==front) throw "ÏÂÒç";
    p=front->next;
    x=p->data;
    front->next=p->next;
    if(p->next==NULL)   rear=front;
    delete p;
    return x;
}

template<class DataType>
DataType LinkQueue<DataType>::GetQueue()
{
    if(front!=rear)
        return front->next->data;
}

template<class DataType>
int LinkQueue<DataType>::Empty()
{
    if(front ==rear)
        return 1;
    else
        return 0;
}
