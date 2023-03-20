//#pragma once
#include "QueueCPP_T.h"
#include "myheader.h"
template<class T>
struct Node {
	T data;
	Node<T> *pNext;
};

template<class T>
struct listImp {
	Node<T> *head, *tail;
};

template<class T>
void initQueue(Queue<T> &queue) {
	listImp<T> *Lst = new listImp<T>;
	queue.data = Lst;
	if (Lst) {
		Lst->head = Lst->tail = nullptr;
	}
}

template<class T>
void closeQueue(Queue<T> &queue) {
	listImp<T> *lst = (listImp<T>*)queue.data;
	if (lst == nullptr) return;
	if (lst->head == nullptr) return;
	Node<T> *cur = lst->head;
	while (cur)
	{
		Node<T> *tmp = cur;
		cur = cur->pNext;
		delete tmp;
	}
	delete lst;
}
template<class T>
Node<T> *makeNode(T X) {
	Node<T> *newNode = new Node<T>;
	if (newNode == nullptr) return nullptr;
	newNode->data = X;
	newNode->pNext = nullptr;
	return newNode;
}

template<class T>
void enQueue(Queue<T> &queue, const T&item) {
	Node<T> *newNode;
	listImp<T> *lst = (listImp<T> *)queue.data;
	if (lst == nullptr) return;
	if (lst->head == nullptr) {
		newNode = makeNode(item);
		if (newNode == nullptr) return;
		lst->head = lst->tail = newNode;
	}
	else {
		lst->tail->pNext = makeNode(item);
		lst->tail = lst->tail->pNext;
	}
}

template<class T>
T deQueue(Queue<T> &queue) {
	static T dummy;
	listImp<T> *lst = (listImp<T> *)queue.data;
	if (lst == nullptr || lst->head == nullptr) return dummy;
	T res;
	res = lst->head->data;
	Node<T> *nd = lst->head;
	lst->head = lst->head->pNext;
	if (lst->head == nullptr) lst->tail = nullptr;
	delete(nd);
	return res;
}
template<class T>
T firstQueue(Queue<T> &queue) {
	static T dummy;
	//if (queue == nullptr) return dummy;
	listImp<T> *lst = (listImp<T> *) queue.data;
	if (lst == nullptr) return dummy;
	if (lst->head == nullptr) return dummy;
	return lst->head->data;
}
template<class T>
bool isEmptyQ(Queue<T> &queue) {
	listImp<T> *lst = (listImp<T> *)queue.data;
	if (lst == nullptr || lst->head == nullptr) return true;
	return false;
}