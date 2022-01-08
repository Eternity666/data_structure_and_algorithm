#include<iostream>
using namespace std;
#define DEFAULT_SIZE 100

template<class Elemtype>
class SqList
{
protected:
    int count;
    int maxSize;
    elemType *elems;

public:
    SqList(int size=DEFAULT_SIZE);
    virtual ~SqList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void(*visit)(const ElemType &)) const;
    bool GetElem(int position, ElemType &e) const;
    bool SetElem(int position, const ElemType &e);
    bool Delete(int position, ElemType &e);
    bool Insert(int position, const ElemType &e);
    SqList(const SqList<Elemtype> &copy);
    SqList<ElemType>&operater = (const SqList<ElemType> &copy);
};

template<class ElemType>
SqList<ElemType>::SqList(int size)
{
    maxSize = size;
    elems = new ElemType[maxSize];
    count = 0;
}

template<class ElemType>
SqList<ElemType>::~SqList()
{
    delete [] elems;
}

template<class ElemType>
int SqList<ElemType>::Length() const
{
    return count;
}

template<class ElemType>
bool SqList<ElemType>::Empty() const
{
    return count==0;
}

template<class ElemType>
void SqList<ElemType>::Clear()
{
    count = 0;
}

template<class ElemType>
void SqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for(int pos = 1; pos <= Length(); pos++)
    {
        (*visit)(elems[pos-1]);
    }
}

template<class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &e) const
{
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        e = elems[position-1];
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int position, const ElemType &e)
{
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        elems[position-1] = e;
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::Insert(int position, const ElemType &e)
{
    ElemType tmp;
    if(count == maxSize)
    {
        return false;
    }
    else if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        count++;
        for(int pos=Length(); pos>=position; pos--)
        {
            GetElem(pos, tmp);
            SetElem(pos+1, tmp);
        }
        SetElem(position, e);
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::Delete(int position, ElemType &e)
{
    ElemType tmp;
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        GetElem(position, e);
        for(int pos=position+1; pos<=Length(); pos++)
        {
            GetElem(pos, tmp);
            SetElem(pos-1, tmp);
        }
        count--;
        return true;
    }
}

template<class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> &copy)
{
    maxSize = copy.maxSize;
    elems = new ElemType[maxSize];
    count = copy.count;

    for(int pos=1; pos<=Length(); pos++)
    {
        elems[pos-1]=copy.elems[pos-1];
    }
}

template<class ElemType>
SqList<ElemType> &SqList<ElemType>::operator=(const SqList<ElemType> &copy)
{
    if(&copy != this)
    {
        maxSize = copy.maxSize;
        if(elems!=NULL)
        {
            delete[]elems;
        }
        elems = new ElemType[maxSize];
        count = copy.count;

        for(int pos=1; pos<=Length(); pos++)
        {
            elems[pos-1] = copy.elems[pos-1];
        }
    }
    return *this;
}

int main()
{
    for(int i=0; i<10; i++)
    {
        SqList
    }
}
