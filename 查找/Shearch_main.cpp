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
    cout<<"�����ҵ����еĳ��ȣ�";
    cin>>n;
    cout<<"�����ҵ������е�Ԫ�أ�";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"�����ҵ�Ԫ�أ�";
    cin>>key;
    cout<<"�������"<<endl;
    index=shearch.shearch1(arr,n,key);
    if(index==-1)
        cout<<"Ԫ�ز���������"<<endl;
    else
        cout<<"Ԫ�������еĵ�"<<index<<"��λ��"<<endl;
    sort(arr,arr+n);
    cout<<"�������"<<endl;
    index=shearch.shearch2(arr,n,key);
    if(index==-1)
        cout<<"Ԫ�ز���������"<<endl;
    else
        cout<<"Ԫ�������еĵ�"<<index<<"��λ��"<<endl;
    cout<<"�۰����"<<endl;
    index=shearch.bin_shearch(arr,n,key);
    if(index==-1)
        cout<<"Ԫ�ز���������"<<endl;
    else
        cout<<"Ԫ�������еĵ�"<<index<<"��λ��"<<endl;
    return 0;
}
