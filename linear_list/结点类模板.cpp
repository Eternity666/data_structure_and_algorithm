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
