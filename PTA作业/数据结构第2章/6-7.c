#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

ElementType FindKth(List L, int K);

int main() {
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType FindKth(List L, int K) {
    if (K <= 0)
        return ERROR;
    PtrToLNode now = L;
    for (int i = 1; i < K && now != NULL; i++) {
        now = now->Next;
    }
    if (now != NULL)
        return now->Data;
    else
        return ERROR;
}
