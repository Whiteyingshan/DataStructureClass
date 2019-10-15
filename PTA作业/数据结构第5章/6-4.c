//
// Created by Whiteying on 2019/10/14.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);

BinTree Delete(BinTree BST, ElementType X);

Position Find(BinTree BST, ElementType X);

Position FindMin(BinTree BST);

Position FindMax(BinTree BST);

int main() {
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}

void PreorderTraversal(BinTree BT) {
    if (BT == NULL)
        return;
    printf(" %d", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void InorderTraversal(BinTree BT) {
    if (BT == NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %d", BT->Data);
    InorderTraversal(BT->Right);
}

/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST, ElementType X) {
    BinTree index = malloc(sizeof(struct TNode));
    index->Data = X;
    index->Left = NULL;
    index->Right = NULL;
    if (BST == NULL) {
        BST = index;
        return BST;
    }
    BinTree now = BST;
    while (1) {
        if (now->Data < X) {
            if (now->Right == NULL) {
                now->Right = index;
                return BST;
            }
            now = now->Right;
        } else if (now->Data > X) {
            if (now->Left == NULL) {
                now->Left = index;
                return BST;
            }
            now = now->Left;
        }
    }
}

BinTree Delete(BinTree BST, ElementType X) {
    BinTree now = BST;
    BinTree nowFather = NULL;
    while (1) {
        if (now == NULL) {
            printf("Not Found\n");
            return BST;
        }
        if (now->Data == X) {
            if (nowFather == NULL) {
                if (now->Left == NULL && now->Right == NULL) {
                    free(now);
                    return NULL;
                } else if (now->Right == NULL) {
                    BST = now->Left;
                    free(now);
                    return BST;
                } else if (now->Left == NULL) {
                    BST = now->Right;
                    free(now);
                    return BST;
                } else {
                    BinTree par = now;
                    BinTree s = now->Right;
                    while (s->Left != NULL) {
                        par = s;
                        s = s->Left;
                    }
                    now->Data = s->Data;
                    if (par == now) par->Right = s->Right;
                    else par->Left = s->Right;
                    free(s);
                    return BST;
                }
            }
            if (now->Left == NULL && now->Right == NULL) {
                if (nowFather->Left == now)
                    nowFather->Left = NULL;
                else if (nowFather->Right == now)
                    nowFather->Right = NULL;
                free(now);
                return BST;
            } else if (now->Right == NULL) {
                if (nowFather->Left == now)
                    nowFather->Left = now->Left;
                else if (nowFather->Right == now)
                    nowFather->Right = now->Left;
                free(now);
                return BST;
            } else if (now->Left == NULL) {
                if (nowFather->Left == now)
                    nowFather->Left = now->Right;
                else if (nowFather->Right == now)
                    nowFather->Right = now->Right;
                free(now);
                return BST;
            } else {
                BinTree par = now;
                BinTree s = now->Right;
                while (s->Left != NULL) {
                    par = s;
                    s = s->Left;
                }
                now->Data = s->Data;
                if (par == now) par->Right = s->Right;
                else par->Left = s->Right;
                free(s);
                return BST;
            }
        } else if (now->Data > X) {
            nowFather = now;
            now = now->Left;
        } else if (now->Data < X) {
            nowFather = now;
            now = now->Right;
        }
    }
}

Position Find(BinTree BST, ElementType X) {
    Position now = BST;
    while (1) {
        if (now == NULL)
            return NULL;
        if (now->Data == X)
            return now;
        else if (now->Data > X)
            now = now->Left;
        else if (now->Data < X)
            now = now->Right;
    }
}

Position FindMin(BinTree BST) {
    if (BST == NULL)
        return NULL;
    Position MinPos = BST;
    while (MinPos->Left != NULL) {
        MinPos = MinPos->Left;
    }
    return MinPos;
}

Position FindMax(BinTree BST) {
    if (BST == NULL)
        return NULL;
    Position MaxPos = BST;
    while (MaxPos->Right != NULL) {
        MaxPos = MaxPos->Right;
    }
    return MaxPos;
}