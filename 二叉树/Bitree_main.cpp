#include<iostream>
using namespace std;
#include"Bitree.h"

int main()
{
    BiTree T;
    cout<<"-----前序遍历-----"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"-----中序遍历-----"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"-----后序遍历-----"<<endl;
    T.PostOrder();
    cout<<endl;
    return 0;
}
