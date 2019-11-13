#include"Shearch.h"

template<class DataType>
int sequence<DataType>::shearch1(DataType *k,int n,DataType key)
{
    for(int i=0;i<n;i++)
        if(k[i]==key)
            return i;
    return -1;
}

template<class DataType>
int sequence<DataType>::shearch2(DataType *k,int n,DataType key)
{
    for(int i=0;i<n;i++)
    {
        if(k[i]==key)
            return i;
        else if(k[i]>key)
            return -1;
    }
    return -1;
}

template<class DataType>
int sequence<DataType>::bin_shearch(DataType *k,int n,DataType key)
{
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(k[mid]==key)
            return mid;
        else if(k[mid]>key)
            r=mid-1;
        else if(k[mid]<key)
            l=mid+1;
    }
    return -1;
}
