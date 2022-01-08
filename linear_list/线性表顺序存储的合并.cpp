#include<iostream>
using namespace std;
#define DEFAULT_SIZE 100

template<class ElemType>
class SqList
{
protected:
    int count;
    int maxSize;
    ElemType *elems;

public:
    SqList(int size=DEFAULT_SIZE);
    SqList(ElemType a[], int n);
    virtual ~SqList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse() const;
    bool GetElem(int position, ElemType &e) const;
    bool SetElem(int position, const ElemType &e);
    bool Delete(int position, ElemType &e);
    bool Insert(int position, const ElemType &e);
    bool Add(ElemType e);
    SqList(const SqList<ElemType> &copy);
};

template<class ElemType>
SqList<ElemType>::SqList(int size)
{
    maxSize = size;
    elems = new ElemType[maxSize];
    count = 0;
}

template<class ElemType>
SqList<ElemType>::SqList(ElemType a[], int n)
{
    maxSize = n;
    elems = new ElemType[maxSize];
    for(int i=0; i<n; i++)
        elems[i] = a[i];
    count = n;
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
void SqList<ElemType>::Traverse() const
{
    for(int i=0; i<Length(); i++)
    {
        cout<<elems[i]<<" ";
    }
    cout<<endl;
}

template<class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &e) const
{
    if(position<1 || position>maxSize)
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
    if(position<1 || position>maxSize)
    {
        return false;
    }
    else
    {
        cout<<"a"<<endl;
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
bool SqList<ElemType>::Add(ElemType e)
{
    if(count == maxSize)
    {
        return false;
    }
    else
    {
        elems[count] = e;
        count++;
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
void Merge(const SqList<ElemType> &la, const SqList<ElemType> &lb, SqList<ElemType> &lc)
{
    int alen=la.Length(), blen=lb.Length();
    ElemType aElem, bElem;
    lc.Clear();
    int k;
    for(int i=1; i<=alen; i++)
    {
        la.GetElem(i, aElem);
        lc.Add(aElem);
    }
    for(int j=1; j<=blen; j++)
    {
        lb.GetElem(j, bElem);
        for(k=1; k<=alen; k++)
        {
            la.GetElem(k, aElem);
            if(aElem==bElem)
                break;
            else
                continue;
        }
        if(k==alen+1)
        {
            lc.Add(bElem);
        }
        else
            continue;
    }
}

int main()
{
    int na,nb,nc;
    nc = na + nb;
    cout<<"请输入la的长度：";
    cin>>na;
    cout<<"请输入lb的长度：";
    cin>>nb;
    //SqList<int> la(na), lb(nb), lc(nc);
    int a[na],b[nb];
    cout<<"请输入la的元素：";
    for(int i=0; i<na; i++)
    {
        cin>>a[i];
    }
    cout<<"请输入lb的元素：";
    for(int i=0; i<nb; i++)
    {
        cin>>b[i];
    }
    SqList<int> la(a,na), lb(b,nb), lc(nc);
    la.Traverse();
    lb.Traverse();
    Merge(la,lb,lc);
    lc.Traverse();
    return 0;
}


