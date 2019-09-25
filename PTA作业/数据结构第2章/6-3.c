#include <stdio.h>
#include <stdlib.h>//malloc����

struct Node {    //������
    int data;    //����
    struct Node* link;    //ָ����һ������ָ��
};

/* β�巨�������������ص������ͷָ�� */
struct Node* buildLinkedList(int* arr, int n); /* β�巨���������� */
void printLinkedList(struct Node* head);       /* ��ӡ���� */

int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));	//��̬�ڴ������������ռ�
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    struct Node* head = NULL;	//����һ��ָ�����head

    //���������ѷ��ص�ͷָ�븳ֵ��headָ�����
    head = buildLinkedList(a, n);

    //��ӡ��������������head������
    printLinkedList(head);

    free(a);	//�ͷŴ洢�ռ�

    return 0;
}

/* ����������д�� */
struct Node* buildLinkedList(int* arr, int n) /* β�巨���������� */
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* r=head;
    for(int i=0;i<n;i++)
    {
        struct Node* s=(struct Node*)malloc(sizeof(struct Node));
        s->data=arr[i];
        r->link=s;
        r=s;
    }
    r->link=NULL;
    return head;
}
void printLinkedList(struct Node* head)       /* ��ӡ���� */
{
    struct Node* now=head->link;
    for(;now->link!=NULL;now=now->link)
    {
        printf("%d ",now->data);
    }
    printf("%d\n",now->data);
}
