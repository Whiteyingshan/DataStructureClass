#include<iostream>
using namespace std;
#include "LinkQueue.cpp"

int main()
{
    LinkQueue<int>Q;
    if(Q.Empty())
        cout<<"队列为空"<<endl;
    else
        cout<<"队列非空"<<endl;
    try
    {
        Q.EnQueue(10);
        Q.EnQueue(15);
    }
    catch(char *wrong)
    {
        cout<<wrong<<endl;
    }
    cout<<"查看队头元素："<<endl;
    cout<<Q.GetQueue()<<endl;
    cout<<"执行出队操作："<<endl;
    try
    {
        Q.DeQueue();
    }
    catch(char *wrong)
    {
        cout<<wrong<<endl;
    }
    cout<<"查看队头元素："<<endl;
    cout<<Q.GetQueue()<<endl;
}
