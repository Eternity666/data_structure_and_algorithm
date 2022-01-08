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
    //SimpleLinkList(ElemType a[], int n);
    virtual ~SimpleLinkList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse() const;
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
void SimpleLinkList<ElemType>::Traverse() const
{
    for(Node<ElemType> *tmpPtr=head->next; tmpPtr!=NULL; tmpPtr=tmpPtr->next)
    {
        cout<<tmpPtr->data<<" ";
    }
    cout<<endl;
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
        if(position==Length()+1)
        {
            newPtr->next = NULL;
        }
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

template<class ElemType>
void Merge(const SimpleLinkList<ElemType> &la, const SimpleLinkList<ElemType> &lb, SimpleLinkList<ElemType> &lc)
{
    int alen=la.Length(), blen=lb.Length();
    ElemType aElem, bElem;
    lc.Clear();
    int k, cCur=1;
    for(int i=1; i<=alen; i++)
    {
        la.GetElem(i, aElem);
        lc.Insert(cCur++, aElem);
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
            lc.Insert(cCur++, bElem);
        }
        else
            continue;
    }
}

int main()
{
    int na,nb,nc;
    nc = na + nb;
    cout<<"������la�ĳ��ȣ�";
    cin>>na;
    cout<<"������lb�ĳ��ȣ�";
    cin>>nb;
    int a;
    SimpleLinkList<int> la, lb, lc;
    cout<<"������la��Ԫ�أ�";
    for(int i=0; i<na; i++)
    {
        cin>>a;
        la.Insert(i+1, a);
    }
    cout<<"������lb��Ԫ�أ�";
    for(int i=0; i<nb; i++)
    {
        cin>>a;
        lb.Insert(i+1, a);
    }
    la.Traverse();
    lb.Traverse();
    Merge(la,lb,lc);
    lc.Traverse();
    return 0;
}
