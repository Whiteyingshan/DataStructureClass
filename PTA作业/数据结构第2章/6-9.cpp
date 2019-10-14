#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;    /*元素的数据类型*/

typedef struct LNode {    /*单链表结点类型定义*/
    ElemType data;        /*结点的数据域*/
    struct LNode *next;    /*指向后继结点*/
} LinkNode;            /*单链表结点类型*/

/*尾插法建立单链表,细节不表*/
LinkNode *CreateListR(ElemType a[], int n);

/*输出线性表,细节不表*/
void DispList(LinkNode *L);

/*删除排序链表中的重复元素*/
LinkNode *deleteDuplicates(LinkNode *L);

int main() {
    ElemType a[10000], x;
    int n = 0;

    while (scanf("%d", &x) != EOF) {
        a[n++] = x;
    }

    LinkNode *L = CreateListR(a, n);

    L = deleteDuplicates(L);
    DispList(L);

    return 0;
}

/* 请在下面填写答案 */

/*删除排序链表中的重复元素*/
LinkNode *deleteDuplicates(LinkNode *L) {
    for (LinkNode *first = L; first != NULL; first = first->next) {
        for (LinkNode *second = first->next, *s = first; second != NULL;) {
            if (first->data == second->data) {
                s->next = second->next;
                delete second;
                second = s->next;
            } else {
                second = second->next;
                s = s->next;
            }
        }
    }
    return L;
}
