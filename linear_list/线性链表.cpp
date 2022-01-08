#include<iostream>
using namespace std;

template<class ElemType>
struct Node
{
    ElemType data;
    Node<ElemType> *next;

    Node();   //�޲����Ĺ��캯��ģ��
    Node(ElemType item, Node<ElemType> *link=NULL);   //��֪����Ԫ�غͺ��ָ�뽨���ṹ

};

template<class ElemType>
Node<ElemType>::Node()
//������ָ��Ϊ�յĽ��
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
//����ʵ�ֵ����ݳ�Ա
protected:
    Node<ElemType> *head;   //ͷ���ָ��

//��������ģ��
    Node<ElemType> *GetElemPtr(int position) const;
                            //����ָ���position������ָ��

public:
//�����������ͷ������������ر���ϵͳ��������
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
//�������������ָ���position������ָ��
{
    Node<ElemType> *tmpPtr = head;   //��tmpPtr�������Ա��Բ��ҵ�position�����
    int pos = 0;

    while(tmpPtr!=NULL && pos<position)
    {   //˳ָ�������ң�ֱ��tmpPtrָ���position�����
        tmpPtr = tmpPtr->next;
        pos++;
    }

    if(tmpPtr!=NULL && pos==position)
    {   //���ҳɹ�
        return tmpPtr;
    }
    else
    {   //����ʧ��
        return NULL;
    }
}

template<class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
//�������������һ��������
{
    head = new Node<ElemType>;   //����ͷ���
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


