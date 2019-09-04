#ifndef SEQLIST_H
#define SEQLIST_H
const int MaxSize=10;
class SeqList
{
public:
    SeqList(){length=0;}
    SeqList(int a[],int n);
    ~SeqList(){}
    void Insert(int i,int x);
    int Delete(int i);
    int Locate(int x);
    void PrintList();
private:
    int data[MaxSize];
    int length;
};


#endif
