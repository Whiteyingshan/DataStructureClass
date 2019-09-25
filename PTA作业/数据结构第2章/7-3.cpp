#include<iostream>
using namespace std;

#define LL long long
//n个人编号为1到n，从1开始报数，报到k出列，返回m(<=n)个出列的人
LL Josephus(LL n,LL k,LL m)
{
	if(k==1)return m;
	LL x=(k-1)%(n+1-m);
	for(LL i=n+1-m;i<n;)
	{
		LL y=min((i-x+k-2)/(k-1)-1,n-i);
		if(y)x+=y*k,i+=y;
		else ++i,x=(x+k)%i;
	}
	return x+1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)
        cout<<Josephus(n,m,i)<<" ";
    cout<<Josephus(n,m,n)<<endl;
    return 0;
}
