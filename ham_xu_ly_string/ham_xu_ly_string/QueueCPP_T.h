#pragma once

template<class T>
struct Queue {
	void *data;
};
template<class T>
void initQueue(Queue<T> &queue);

template<class T>
void closeQueue(Queue<T> &queue);

template<class T>
void enQueue(Queue<T> &queue,const T&item);

template<class T>
T deQueue(Queue<T> &queue);

template<class T>
T firstQueue(Queue<T> &queue);

template<class T>
bool isEmptyQ(Queue<T> &queue);