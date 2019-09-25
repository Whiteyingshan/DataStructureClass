#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

LinkList Create();/* 细节在此不表 */
void print( LinkList L);
int insert_link ( LinkList L,int i,ElemType e);

int main()
{
	int position,insert_data;int flag;
	LinkList L = Create();
	scanf("%d",&position);
	scanf("%d",&insert_data);
	flag=insert_link(L,position,insert_data);
	if(flag)
	{
		print(L);
	}
	else
	{
		printf("Wrong Position for Insertion");
	}
	return 0;
}
void print(LinkList L)
{
	LinkList p;
	p=L->next;
	while (p)
	{
	     printf("%d ", p->data);
 	     p =p->next;
	}
}
/* 请在这里填写答案 */
int insert_link ( LinkList L,int i,ElemType e)
{
    LinkList now=L;
    int p=1;
    for(;p<i&&now->next!=NULL;now=now->next,p++);
    if(p!=i)
        return 0;
    else
    {
        LinkList num=malloc(sizeof(LNode));
        num->data=e;
        num->next=now->next;
        now->next=num;
        return 1;
    }
}
