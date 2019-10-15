//
// Created by Whiteying on 2019/10/14.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight(BinTree BT);

int main() {
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

/* 你的代码将被嵌在这里 */
int GetHeight(BinTree BT) {
    if (BT == NULL)
        return 0;
    int l = GetHeight(BT->Left);
    int r = GetHeight(BT->Right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}