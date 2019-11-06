#include<iostream>
using namespace std;
#include"Bitree.h"

BiNode *BiTree::Creat(BiNode *bt)
{
    char ch;
    cout<<"请输入创建一颗二叉树的结点数据"<<endl;
    cin>>ch;
    if(ch=='#')
        return NULL;
    else
    {
        bt=new BiNode;
        bt->data=ch;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}

void BiTree::Release(BiNode *bt)
{
    if(bt!=NULL)
    {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

void BiTree::PreOrder(BiNode *bt)
{
    if(bt==NULL)return;
    else
    {
        cout<<bt->data<<" ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

void BiTree::InOrder(BiNode *bt)
{
    if(bt==NULL)return;
    else
    {
        InOrder(bt->lchild);
        cout<<bt->data<<" ";
        InOrder(bt->rchild);
    }
}


void BiTree::PostOrder(BiNode *bt)
{
    if(bt==NULL)return;
    else
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data<<" ";
    }
}
