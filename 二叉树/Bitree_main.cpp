#include<iostream>
using namespace std;
#include"Bitree.h"

int main()
{
    BiTree T;
    cout<<"-----ǰ�����-----"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"-----�������-----"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"-----�������-----"<<endl;
    T.PostOrder();
    cout<<endl;
    return 0;
}
