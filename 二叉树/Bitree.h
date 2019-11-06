#ifndef BiTree_H
#define BiTree_H

struct BiNode
{
    char data;
    BiNode *lchild,*rchild;
};

class BiTree
{
public:
    BiTree()
    {
        root=Creat(root);
    }
    ~BiTree()
    {
        Release(root);
    }
    void PreOrder()
    {
        PreOrder(root);
    }
    void InOrder()
    {
        InOrder(root);
    }
    void PostOrder()
    {
        PostOrder(root);
    }
private:
    BiNode *root;
    BiNode *Creat(BiNode *bt);
    void Release(BiNode *bt);
    void PreOrder(BiNode *bt);
    void InOrder(BiNode *bt);
    void PostOrder(BiNode *bt);
};

#endif // BiTree_H
