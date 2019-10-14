#include <stdio.h>

void InitList(DLinkNode *&L);        //裁判程序实现，略去不表
void DestroyList(DLinkNode *&L);  //裁判程序实现，略去不表
bool ListInsert(DLinkNode *&L, int i, ElemType e);//裁判程序实现，略去不表
//要求写出以下函数实现
void DispList(DLinkNode *L);

int Symm(DLinkNode *L);

int main() {
    DLinkNode *h;
    ElemType e;
    InitList(h);
    int i = 1;
    char ch;
    while ((ch = getchar()) != '\n') {
        ListInsert(h, i, ch);
        i++;
    }
    DispList(h);

    if (Symm(h) == 1)
        printf("yes\n");
    else if (Symm(h) == 0)printf("no\n");
    else printf("NULL\n");
    DestroyList(h);
    return 0;
}

/* 请在这里填写答案 */
void DispList(DLinkNode *L) {
    DLinkNode *now = L->next;
    while (now != L) {
        printf("%c ", now->data);
        now = now->next;
    }
    printf("\n");


}

int Symm(DLinkNode *L) {
    if (L->next == L)
        return -1;
    DLinkNode *Head = L->next, *Push = L->prior;
    while (Head != Push && Push->next != Head) {
        if (Head->data != Push->data)
            return 0;
        Head = Head->next;
        Push = Push->prior;
    }
    return 1;
}
