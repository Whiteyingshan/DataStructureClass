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
    cout<<"������ȱ����������ǣ�";
    MG.DFSTraverse(0);
    cout<<endl;
    for(int i=0; i<MaxSize; i++)
        vis[i]=0;
    cout<<"������ȱ����������ǣ�";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
