#pragma once
#include "Header_list.h"
template<class T=int>
class MY_NODE
{
public:
	T data;
	MY_NODE<T> *next;
	MY_NODE() {
		this->next = NULL;
	};
	MY_NODE(T d) {
		this->data = d;
		this->next = NULL;
	};
};

