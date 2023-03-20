#pragma once
/*
#include "myheader.h"
#include "MyStack_T.h"
#include "MList_T.h"*/

template<class T>
struct listImp
{
	n_T *head;
};
template<class T>
Stack<T> initStack() {
	Stack<T> St;
	listImp<T> *lst = new listImp<T>;
	if (lst == nullptr) {
		cout << "het bo nho!!!"; system("pause"); exit(-1);
	}
	St.data = lst; lst->head = nullptr;
	return St;
}

template<class T>
void closeStack(Stack<T> &St) {
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr || lst->head == nullptr) return;
	n_T *node = lst->head;
	while (node)
	{
		lst->head = node->pNext;
		delete node;
		node = lst->head;
	}
	delete lst;
}

template<class T>
T pushStack(Stack<T> &St, T dat) {
	static T dummy;
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr) return dummy;
	insertFirst(lst->head, dat);
	if (lst->head->data == dat) return dat;
	return dummy;
}

template<class T>
T popStack(Stack<T> &St) {
	static T dummy;T res;
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr) return dummy;
	res=delBegin(lst->head);
	return res;
}

template<class T>
T topStack(Stack<T> &St) {
	static T dummy;
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr) return dummy;
	return lst->head->data;
}

template<class T>
bool isEmptySt(Stack<T> &St) {
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr || lst->head == nullptr) return true;
	return false;
}

template<class T>
Stack<T> DaoNguocStack(Stack<T> &St) {
	listImp<T> *lst = (listImp<T> *)St.data;
	if (lst == nullptr || lst->head == nullptr) return St;
	Stack<T> newSt = initStack<T>();
	while (!isEmptySt(St))
	{
		pushStack(newSt, popStack(St));
	}
	St = newSt;
	return St;
}