#include<iostream>
using namespace std;

template<class ElemType>
struct Node
{
    ElemType data;
    Node<ElemType> *next;

    Node();   //无参数的构造函数模板
    Node(ElemType item, Node<ElemType> *link=NULL);   //已知数据元素和后继指针建立结构

};

template<class ElemType>
Node<ElemType>::Node()
//构造后继指针为空的结点
{
    next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
{
    data = item;
    next = link;
}

template<class ElemType>
class SimpleCircLinkList
{
protected:
    Node<ElemType> *head;
    Node<ElemType> *GetElemPtr(int position) const;

public:
    SimpleCircLinkList();
    virtual ~SimpleCircLinkList();
    void Clear();
    bool Empty() const;
    int Length() const;
    bool GetElem(int position, ElemType &e) const;
    bool Delete(int position, ElemType &e);
    bool Insert(int position, const ElemType &e);
};

template<class ElemType>
Node<ElemType> *SimpleCircLinkList<ElemType>::GetElemPtr(int position) const
{
    if(position==0)
    {
        return head;
    }

    Node<ElemType> *tmpPtr = head->next;
    int pos = 1;

    while(tmpPtr!=head && pos<position)
    {
        tmpPtr = tmpPtr->next;
        pos++;
    }

    if(tmpPtr!=head && pos==position)
    {
        return tmpPtr;
    }
    else
    {
        return NULL;
    }
}

template<class ElemType>
SimpleCircLinkList<ElemType>::SimpleCircLinkList()
{
    head = new Node<ElemType>;
    head->next = head;
}

template<class ElemType>
SimpleCircLinkList<ElemType>::~SimpleCircLinkList()
{
    Clear();
    delete head;
}

template<class ElemType>
void SimpleCircLinkList<ElemType>::Clear()
{
    ElemType tmpElem;
    while(!Empty())
    {
        Delete(1, tmpElem);
    }
}

template<class ElemType>
bool SimpleCircLinkList<ElemType>::Empty() const
{
    return head->next == head;
}

template<class ElemType>
int SimpleCircLinkList<ElemType>::Length() const
{
    int count = 0;
    for(Node<ElemType> *tmpPtr=head->next; tmpPtr!=head; tmpPtr=tmpPtr->next)
    {
        count++;
    }
    return count;
}

template<class ElemType>
bool SimpleCircLinkList<ElemType>::GetElem(int position, ElemType &e) const
{
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position);
        e = tmpPtr->data;
        return true;
    }
}

template<class ElemType>
bool SimpleCircLinkList<ElemType>::Delete(int position, ElemType &e)
{
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position-1);
        Node<ElemType> *nextPtr = tmpPtr->next;
        e = nextPtr->data;
        tmpPtr->next = nextPtr->next;
        delete nextPtr;
        return true;
    }
}

template<class ElemType>
bool SimpleCircLinkList<ElemType>::Insert(int position, const ElemType &e)
{
    if(position<1 || position>Length()+1)
    {
        return false;
    }
    else
    {
        Node<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position-1);
        Node<ElemType> *newPtr;
        newPtr = new Node<ElemType>(e, tmpPtr->next);
        tmpPtr->next = newPtr;
        return true;
    }
}

void Josephus(int n, int m)
{
    SimpleCircLinkList<int> la;
    int position = 0;
    int out, winner;
    for(int k=1; k<=n; k++)
    {
        la.Insert(k,k);
    }
    cout<<"出列者：";
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            position++;
            if(position>la.Length())
            {
                position = 1;
            }
        }
        la.Delete(position--, out);
        cout<<out<<" ";
    }
    la.GetElem(1, winner);
    cout<<endl<<"优胜者："<<winner<<endl;
}

int main()
{
    Josephus(8,6);
    return 0;
}
