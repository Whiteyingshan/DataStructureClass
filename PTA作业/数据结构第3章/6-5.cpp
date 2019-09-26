//
// Created by Whiteying on 2019/9/26.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10

typedef char ElemType;
typedef struct   // 顺序循环队列结点定义
{
    ElemType *name[MaxSize];   //小孩姓名
    int front,rear;		//队首和队尾指针
} SqQueue;
void InitQueue(SqQueue *&q);   //初始化队列；
void DestroyQueue(SqQueue *&q);  //销毁队列；
bool QueueEmpty(SqQueue *q);  //判定队列为空时返回true; 否则返回false;
bool enQueue(SqQueue *&q,ElemType *e);  // e 入队；成功入队返回true; 否则返回false;
bool deQueue(SqQueue *&q,ElemType *&e);  //出队，返回出队元素e，且成功出队返回true,否则返回false;

int main()
{
    ElemType *e;
    int n,i;
    SqQueue *q;
    InitQueue(q);
    scanf("%d",&n);
    while(1)
    {
        char *name=(char *)malloc(sizeof(char)*N);
        scanf("%s",name);
        if( (strcmp("-1",name)==0)||!enQueue(q,name))
            break;
    }
    i=n-1;
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        if(i-->0)
            enQueue(q,e);
        else
        {
            printf("%s\n",e);
            i=n-1;
            free(e);
        }
    }
    DestroyQueue(q);
    return 0;
}


/* 请在这里填写答案 */
void InitQueue(SqQueue *&q)   //初始化队列；
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->rear=0;
    q->front=0;
    for(auto & i : q->name)
        i=(char *)malloc(sizeof(char)*N);
}
void DestroyQueue(SqQueue *&q)  //销毁队列；
{
    for(auto & i : q->name)
        free(i);
    free(q);
}
bool QueueEmpty(SqQueue *q)  //判定队列为空时返回true; 否则返回false;
{
    return q->front == q->rear;
}
bool enQueue(SqQueue *&q,ElemType *e)  // e 入队；成功入队返回true; 否则返回false;
{
    if((q->front+1)%MaxSize==q->rear)
        return false;
    strcpy(q->name[q->front],e);
    q->front=(q->front+1)%MaxSize;
    return true;
}
bool deQueue(SqQueue *&q,ElemType *&e)  //出队，返回出队元素e，且成功出队返回true,否则返回false;
{
    if(q->front==q->rear)
        return false;
    ElemType *p=(char *)malloc(sizeof(char)*N);
    strcpy(p,q->name[q->rear]);
    e=p;
    q->rear=(q->rear+1)%MaxSize;
    return true;
}
