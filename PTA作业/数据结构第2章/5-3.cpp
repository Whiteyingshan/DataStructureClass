typedef struct LNode {
	int data;
	struct LNode* next;
} LinkNode;
///��������
int getLength(LinkNode* L) {
	if (L == NULL)
		return 0;
	return getLength(L->next)+1/*(4��)*/;
}
