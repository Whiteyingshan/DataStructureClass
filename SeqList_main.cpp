#include<iostream>
using namespace std;
#include "SeqList.h"

int main()
{
    int r[5]={1,2,3,4,5};
    SeqList L(r,5);
    cout<<"ִ�в������ǰ����Ϊ��"<<endl;
    L.PrintList();
    try
    {
        L.Insert(2,3);
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"ִ�в������������Ϊ��"<<endl;
    L.PrintList();
    cout<<"ֵΪ3��Ԫ��λ��Ϊ��";
    cout<<L.Locate(3)<<endl;
    cout<<"ִ��ɾ����һ��Ԫ�ز�����ɾ��ǰ����Ϊ"<<endl;
    L.PrintList();
    try
    {
       L.Delete(1);
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"ɾ��������Ϊ��"<<endl;
    L.PrintList();
}
