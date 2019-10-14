//
// Created by Whiteying on 2019/9/26.
//

#include <stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct {
    LinkList front, rear; /* 队头、队尾指针 */
} LinkQueue;

/* 带头结点的链队列的基本操作 */
Status InitQueue(LinkQueue *Q) { /* 构造一个空队列Q */
    LinkList p;
    p = (LNode *) malloc(sizeof(LNode));
    p->next = NULL;
    (*Q).rear = (*Q).front = p;
    return OK;
}

Status List(LinkList L) {
    LinkList p;
    if (!L) return ERROR;
    p = L->next;

    while (p) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int QueueLenth(LinkQueue Q) {
    int n = 0;
    LinkList p;
    if (Q.rear == Q.front)
        return 0;
    p = Q.front->next;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}

int main() {
    int x;
    LinkQueue Q;
    InitQueue(&Q);
    QueueInsert(&Q, 1);
    QueueInsert(&Q, 2);
    QueueInsert(&Q, 3);
    List(Q.front);
    QueueDelete(&Q, &x);
    printf(" %d %d\n", x, QueueLenth(Q));
    QueueDelete(&Q, &x);
    QueueDelete(&Q, &x);
    printf(" %d %d\n", x, QueueLenth(Q));
    return 0;
}

/* 请在这里填写答案 */
Status QueueInsert(LinkQueue *Q, ElemType e) {
    LinkList p;
    p = (LNode *) malloc(sizeof(struct LNode));
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    p->data = e;
}

Status QueueDelete(LinkQueue *Q, ElemType *e) {
    LinkList p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;
    free(p);
}