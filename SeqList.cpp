#include<iostream>
using namespace std;
#include "SeqList.h"

SeqList::SeqList(int a[],int n)
{
    if(n>MaxSize) throw "�����Ƿ�";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length=n;
}

void SeqList::Insert(int i,int x)
{
    if(length>=MaxSize) throw "����";
    if(i<1||i>length+1) throw "λ�÷Ƿ�";
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

int SeqList::Delete(int i)
{
    if(length==0)   throw "����";
    if(i<i||i>length)   throw "λ�÷Ƿ�";
    int x=data[i-1];
    for(int j=i;j<length;j++)
        data[j-1]=data[j];
    length--;
    return x;
}

int SeqList::Locate(int x)
{
    for(int i=0;i<length;i++)
        if(data[i]==x)
            return i+1;
    return 0;
}

void SeqList::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
