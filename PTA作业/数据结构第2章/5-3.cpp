typedef struct LNode {
	int data;
	struct LNode* next;
} LinkNode;
///求单链表长度
int getLength(LinkNode* L) {
	if (L == NULL)
		return 0;
	return getLength(L->next)+1/*(4分)*/;
}
