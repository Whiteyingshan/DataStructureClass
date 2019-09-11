#include<iostream>
using namespace std;
#include "LinkList.h"

template <class DataType>
LinkList<DataType>::LinkList()
{
    first=new Node<DataType>;
    first->next=NULL;
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
    Node<DataType> *r,*s;
    first=new Node<DataType>;
    r=first;
    for (int i=0;i<n;i++)
    {
        s=new Node<DataType>;
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

template <class DataType>
LinkList<DataType>::~LinkList()
{
    Node<DataType> *q=NULL;
    while(first!=NULL)
    {
        q=first;
        first=first->next;
        delete q;
    }
}

template<class DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
    Node<DataType> *p=first,*s=NULL;
    int count=0;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL) throw "Œª÷√";
    else
    {
        s=new Node<DataType>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node <DataType> *p=first,*q=NULL;
    DataType x;
    int count=0;
    while(p!=NULL&&count <i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL||p->next==NULL)
        throw "Œª÷√";
    else
    {
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node <DataType>*p=first->next;
    int count=1;
    while(p!=NULL)
    {
        if(p->data==x)
            return count;
        p=p->next;
        count++;
    }
    return 0;
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
    Node <DataType>*p=first->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
