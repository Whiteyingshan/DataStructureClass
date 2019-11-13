#ifndef Shearch_H
#define Shearch_H
template<class DataType>
class sequence
{
public:
    int shearch1(DataType *k,int n,DataType key);
    int shearch2(DataType *k,int n,DataType key);
    int bin_shearch(DataType *k,int n,DataType key);
};


#endif // Shearch_H
