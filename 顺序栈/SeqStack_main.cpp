#include<iostream>
using namespace std;
#include "SeqStack.cpp"

int main()
{
    SeqStack<int>S;
    if(S.Empty())
        cout<<"ջΪ��"<<endl;
    else
        cout<<"ջ�ǿ�"<<endl;
    cout<<"��15��10ִ����ջ����"<<endl;
    S.Push(15);
    S.Push(10);
    cout<<"ջ��Ԫ��Ϊ��"<<endl;
    cout<<S.GetTop()<<endl;
    cout<<"ִ��һ�γ�ջ����"<<endl;
    S.Pop();
    cout<<"ջ��Ԫ��Ϊ��"<<endl;
    cout<<S.GetTop()<<endl;
    return 0;
}
