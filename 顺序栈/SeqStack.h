#ifndef SeqStack_H
#define SeqStack_H
const int StackSize=10;
template<class DataType>
class SeqStack
{
public:
    SeqStack();
    ~SeqStack(){}
    void Push(DataType x);
    DataType Pop();
    DataType GetTop();
    int Empty();
private:
    DataType data[StackSize];
    int top;
};


#endif // SeqStack_H
