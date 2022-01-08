#include<iostream>
using namespace std;

template<class ElemType>
class SimpleCircLinkList
{
protected:
    Node<ElemType> *head;
    Node<ElemType> *GetElemPtr(int position) const;

public:
    SimpleCircLinkList();
    virtual
};
