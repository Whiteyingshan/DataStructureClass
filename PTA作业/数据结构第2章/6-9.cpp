#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;    /*Ԫ�ص���������*/

typedef struct LNode {    /*�����������Ͷ���*/
    ElemType data;        /*����������*/
    struct LNode *next;    /*ָ���̽��*/
} LinkNode;            /*������������*/

/*β�巨����������,ϸ�ڲ���*/
LinkNode *CreateListR(ElemType a[], int n);

/*������Ա�,ϸ�ڲ���*/
void DispList(LinkNode *L);

/*ɾ�����������е��ظ�Ԫ��*/
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

/* ����������д�� */

/*ɾ�����������е��ظ�Ԫ��*/
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
