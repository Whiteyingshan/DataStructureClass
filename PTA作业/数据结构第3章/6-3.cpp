//
// Created by Whiteying on 2019/9/26.
//

#include <malloc.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode * next;
}LNode,*LinkList;

Status InitList(LinkList *L);
Status List(LinkList L);
Status ListInsert(LinkList L,int i,ElemType e);
int main()
{

    LinkList L;
    int x;
    InitList(&L);
    Push(L,1);Push(L,2);Push(L,3);
    List(L);
    Pop(L,&x);
    printf(" %d\n",x);
    List(L);
    return 0;
}

/* 请在这里填写答案 */
Status Push(LinkList L,ElemType e)
{
    LinkList s=(LinkList)malloc(sizeof(struct LNode));
    s->data=e;
    s->next=L->next;
    L->next=s;
}

Status Pop(LinkList L,ElemType *e)
{
    LinkList s=L->next;
    *e=s->data;
    L->next=s->next;
    free(s);
}