//
// Created by Whiteying on 2019/10/15.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);

bool LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    if(LevelorderTraversal(BST))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}


bool LevelorderTraversal(BinTree BT)
{
    BinTree *Queue = (BinTree*)malloc(sizeof(struct TNode) * 100);
    int front = -1;
    int rear = -1;
    if (BT == NULL)
        return true;
    bool first=true;
    bool Yes=true;
    Queue[++rear] = BT;
    bool tt=false;
    while (front != rear)
    {
        BinTree q = Queue[++front];
        if(tt)
        {
            if(q->Left!=NULL||q->Right!=NULL)
                Yes=false;
        }
        if(first)
        {
            printf("%d", q->Data);
            first=false;
        }
        else
            printf(" %d", q->Data);
        if (q->Left != NULL)
            Queue[++rear] = q->Left;
        if (q->Right != NULL)
            Queue[++rear] = q->Right;
        if(q->Left==NULL&&q->Right!=NULL)
            Yes=false;
        else if(q->Left!=NULL&&q->Right==NULL||q->Left==NULL&&q->Right==NULL)
            tt=true;
    }
    printf("\n");
    return Yes;
}

/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST, ElementType X)
{
    BinTree index = (BinTree)malloc(sizeof(struct TNode));
    index->Data = X;
    index->Left = NULL;
    index->Right = NULL;
    if (BST == NULL)
    {
        BST = index;
        return BST;
    }
    BinTree now = BST;
    while (1)
    {
        if (now->Data > X)
        {
            if (now->Right == NULL)
            {
                now->Right = index;
                return BST;
            }
            now = now->Right;
        }
        else if (now->Data < X)
        {
            if (now->Left == NULL)
            {
                now->Left = index;
                return BST;
            }
            now = now->Left;
        }
    }
}
