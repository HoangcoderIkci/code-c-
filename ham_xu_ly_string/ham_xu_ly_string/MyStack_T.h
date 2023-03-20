#pragma once
template<class T>
struct Stack {
	void *data;
};
template<class T>
Stack<T> initStack();

template<class T>
void closeStack(Stack<T> &);

template<class T>
T pushStack(Stack<T> &, T );

template<class T>
T popStack(Stack<T> &);

template<class T>
T topStack(Stack<T> &);

template<class T>
bool isEmptySt(Stack<T> &);

template<class T>
Stack<T> DaoNguocStack(Stack<T> &St);