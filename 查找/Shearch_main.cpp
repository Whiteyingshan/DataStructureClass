#include<iostream>
#include<algorithm>
#include"Shearch.cpp"
using namespace std;
const int MaxNum=10;
int arr[MaxNum];

int main()
{
    int n,index,key;
    sequence<int> shearch;
    cout<<"待查找的序列的长度：";
    cin>>n;
    cout<<"待查找的序列中的元素：";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"待查找的元素：";
    cin>>key;
    cout<<"无序查找"<<endl;
    index=shearch.shearch1(arr,n,key);
    if(index==-1)
        cout<<"元素不在序列中"<<endl;
    else
        cout<<"元素在序列的第"<<index<<"个位置"<<endl;
    sort(arr,arr+n);
    cout<<"有序查找"<<endl;
    index=shearch.shearch2(arr,n,key);
    if(index==-1)
        cout<<"元素不在序列中"<<endl;
    else
        cout<<"元素在序列的第"<<index<<"个位置"<<endl;
    cout<<"折半查找"<<endl;
    index=shearch.bin_shearch(arr,n,key);
    if(index==-1)
        cout<<"元素不在序列中"<<endl;
    else
        cout<<"元素在序列的第"<<index<<"个位置"<<endl;
    return 0;
}
