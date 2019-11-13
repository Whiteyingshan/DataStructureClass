#include<iostream>
using namespace std;
#include"MGraph.h"
extern int vis[MaxSize];

template<class DataType>
MGraph<DataType>::MGraph(DataType a[],int n,int e)
{
    int i,j,k;
    vertexNum=n;
    arcNum=e;
    for(int i=0; i<vertexNum; i++)
        vertex[i]=a[i];
    for(int i=0; i<vertexNum; i++)
        for(int j=0; j<vertexNum; j++)
            arc[i][j]=0;
    for(k=0; k<arcNum; k++)
    {
        cout<<"������ߵ������������ţ�";
        cin>>i>>j;
        arc[i][j]=1;
        arc[j][i]=1;
    }
}

template<class DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
    cout<<vertex[v];
    vis[v]=1;
    for(int j=0; j<vertexNum; j++)
        if(arc[v][j]==1&&vis[j]==0)
            DFSTraverse(j);
}

template<class DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
    int Q[MaxSize];
    int front=-1,rear=-1;
    cout<<vertex[v];
    vis[v]=1;
    Q[++rear]=v;
    while(front!=rear)
    {
        v=Q[++front];
        for(int j=0; j<vertexNum; j++)
            if(arc[v][j]==1&&vis[j]==0)
            {
                cout<<vertex[j];
                vis[j]=1;
                Q[++rear]=j;
            }
    }
}
