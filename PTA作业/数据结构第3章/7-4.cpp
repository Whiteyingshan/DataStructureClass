//
// Created by Whiteying on 2019/9/25.
//

#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    MyQueue(int n);
    void push(int x);
    int pop();
    int size();
    ~MyQueue();
private:
    int front;
    int end;
    int *num;
};

MyQueue::MyQueue(int n)
{
    num=new int[n];
    front=0;
    end=0;
}
MyQueue::~MyQueue()
{
    delete []num;
}
void MyQueue::push(int x)
{
    num[end++]=x;
}

int MyQueue::pop()
{
    if(front==end)
        return -1;
    return num[front++];
}

int MyQueue::size()
{
    return end-front;
}


int main()
{
    int n;
    cin>>n;
    MyQueue Queue(n);
    for(int i=1;i<=n;i++)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x;
            cin>>x;
            Queue.push(x);
        }
        else if(opt==2)
        {
            int num=Queue.pop();
            if(num==-1)
                cout<<"Invalid"<<endl;
            else
                cout<<num<<endl;
        }
        else if(opt==3)
        {
            cout<<Queue.size()<<endl;
        }

    }
    return 0;
}