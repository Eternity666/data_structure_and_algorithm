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
