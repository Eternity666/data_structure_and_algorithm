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
class SimpleLinkList
{
//链表实现的数据成员
protected:
    Node<ElemType> *head;   //头结点指针

//辅助函数模板
    Node<ElemType> *GetElemPtr(int position) const;
                            //返回指向第position个结点的指针

public:
//抽象数据类型方法声明及重载编译系统方法声明
    SimpleLinkList();
    virtual ~SimpleLinkList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void (*visit)(const ElemType &)) const;
    bool GetElem(int position, ElemType &e) const;
    bool SetElem(int position, const ElemType &e);
    bool Delete(int position, ElemType &e);
    bool Insert(int position, const ElemType &e);
    SimpleLinkList(const SimpleLinkList<ElemType> &copy);
    SimpleLinkList<ElemType> &operator = (const SimpleLinkList<ElemType> &copy);
};

template<class ElemType>
Node<ElemType> *SimpleLinkList<ElemType>::GetElemPtr(int position) const
//操作结果：返回指向第position个结点的指针
{
    Node<ElemType> *tmpPtr = head;   //用tmpPtr遍历线性表以查找第position个结点
    int pos = 0;

    while(tmpPtr!=NULL && pos<position)
    {   //顺指针向后查找，直到tmpPtr指向第position个结点
        tmpPtr = tmpPtr->next;
        pos++;
    }

    if(tmpPtr!=NULL && pos==position)
    {   //查找成功
        return tmpPtr;
    }
    else
    {   //查找失败
        return NULL;
    }
}

template<class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
//操作结果：构造一个空链表
{
    head = new Node<ElemType>;   //生成头结点
}

template<class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()
{
    Clear();
    delete head;
}

template<class ElemType>
int SimpleLinkList<ElemType>::Length() const
{
    int count = 0;
    for(Node<ElemType> *tmpPtr=head->next; tmpPtr!=NULL; tmpPtr=tmpPtr->next)
    {
        count++;
    }
    return count;
}

template<class ElemType>
bool SimpleLinkList<ElemType>::Empty() const
{
    return head->next == NULL;
}

template<class ElemType>
void SimpleLinkList<ElemType>::Clear()
{
    ElemType tmpElem;
    while(!Empty())
    {
        Delete(1, tmpElem);
    }
}

template<class ElemType>
void SimpleLinkList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for(Node<ElemType> *tmpPtr=head->next; tmpPtr!=NULL; tmpPtr=tmpPtr->next)
    {
        (*visit)(tmpPtr->data);
    }
}

template<class ElemType>
bool SimpleLinkList<ElemType>::GetElem(int position, ElemType &e) const
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
bool SimpleLinkList<ElemType>::SetElem(int position, const ElemType &e)
{
    if(position<1 || position>Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *tmpPtr;
        tmpPtr=GetElemPtr(position);
        tmpPtr->data = e;
        return true;
    }
}

template<class ElemType>
bool SimpleLinkList<ElemType>::Insert(int position, const ElemType &e)
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

template<class ElemType>
bool SimpleLinkList<ElemType>::Delete(int position, ElemType &e)
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
        delete nextPtr;
        return true;
    }
}


