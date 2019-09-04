#include<iostream>
using namespace std;
#include "SeqList.h"

int main()
{
    int r[5]={1,2,3,4,5};
    SeqList L(r,5);
    cout<<"执行插入操作前数据为："<<endl;
    L.PrintList();
    try
    {
        L.Insert(2,3);
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"执行插入操作后数据为："<<endl;
    L.PrintList();
    cout<<"值为3的元素位置为：";
    cout<<L.Locate(3)<<endl;
    cout<<"执行删除第一个元素操作，删除前数据为"<<endl;
    L.PrintList();
    try
    {
       L.Delete(1);
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"删除后数据为："<<endl;
    L.PrintList();
}
