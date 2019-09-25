#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */

Polynomial Add( Polynomial a, Polynomial b )
{
    Polynomial c=malloc(sizeof(Polynomial));
    c->Next=NULL;
    Polynomial cHead=c;
    a=a->Next;
    b=b->Next;
    while(a&&b)
    {

        if(a->Exponent>b->Exponent)
        {
            Polynomial now=a;
            a=a->Next;
            now->Next=NULL;
            c->Next=now;
            c=now;
        }
        else if(a->Exponent<b->Exponent)
        {
            Polynomial now=b;
            b=b->Next;
            now->Next=NULL;
            c->Next=now;
            c=now;
        }
        else if(a->Coefficient+b->Coefficient)
        {
            Polynomial now=a;
            now->Coefficient=a->Coefficient+b->Coefficient;
            a=a->Next;
            b=b->Next;
            now->Next=NULL;
            c->Next=now;
            c=now;
        }
        else
        {
            a=a->Next;
            b=b->Next;
        }
    }
    if(a==NULL)
    {
        while(b)
        {
            Polynomial now=b;
            b=b->Next;
            now->Next=NULL;
            c->Next=now;
            c=now;
        }
    }
    else if(b==NULL)
    {
        while(a)
        {
            Polynomial now=a;
            a=a->Next;
            now->Next=NULL;
            c->Next=now;
            c=now;
        }
    }
    return cHead;
}
