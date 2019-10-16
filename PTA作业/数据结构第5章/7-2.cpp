//
// Created by Whiteying on 2019/10/16.
//

#include <iostream>
#include <cstring>
using namespace std;
int n;
int Inorder[35];
int Postorder[35];
int Levelorder[10005];
int xIndex;

void LevelorderTraversal(int l,int r,int index)
{
    if(l>r)
        return;
    Levelorder[index]=Postorder[xIndex];
    xIndex--;
    for(int i=l;i<=r;i++)
    {
        if(Inorder[i]==Postorder[xIndex])
        {
            LevelorderTraversal(i+1,r,index*2+2);
            LevelorderTraversal(l,i-1,index*2+1);
        }
    }
}


int main()
{
    cin>>n;
    xIndex=n;
    for(int i=1; i<=n; i++)
        cin>>Postorder[i];
    for(int i=1; i<=n; i++)
        cin>>Inorder[i];
    memset(Levelorder,-1,sizeof(Levelorder));

    LevelorderTraversal(1,n,0);
    int num=1;
    for(int i=0;i<10005;i++)
    {
        if(Levelorder[i]!=-1)
        {
            if(num==n)
            {
                cout<<Levelorder[i]<<endl;
                break;
            }
            else
            {
                cout<<Levelorder[i]<<" ";
                num++;
            }
        }
    }
    return 0;
}
