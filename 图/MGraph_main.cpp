#include<iostream>
using namespace std;
#include"MGraph.cpp"
int vis[MaxSize]= {0};


int main()
{
    char ch[]= {'A','B','C','D','E'};
    MGraph<char> MG(ch,5,6);
    for(int i=0; i<MaxSize; i++)
        vis[i]=0;
    cout<<"深度优先遍历的序列是：";
    MG.DFSTraverse(0);
    cout<<endl;
    for(int i=0; i<MaxSize; i++)
        vis[i]=0;
    cout<<"广度优先遍历的序列是：";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
