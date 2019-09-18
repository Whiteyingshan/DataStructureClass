#include<iostream>
using namespace std;
#include "LinkQueue.cpp"

int main()
{
    LinkQueue<int>Q;
    if(Q.Empty())
        cout<<"����Ϊ��"<<endl;
    else
        cout<<"���зǿ�"<<endl;
    try
    {
        Q.EnQueue(10);
        Q.EnQueue(15);
    }
    catch(char *wrong)
    {
        cout<<wrong<<endl;
    }
    cout<<"�鿴��ͷԪ�أ�"<<endl;
    cout<<Q.GetQueue()<<endl;
    cout<<"ִ�г��Ӳ�����"<<endl;
    try
    {
        Q.DeQueue();
    }
    catch(char *wrong)
    {
        cout<<wrong<<endl;
    }
    cout<<"�鿴��ͷԪ�أ�"<<endl;
    cout<<Q.GetQueue()<<endl;
}
