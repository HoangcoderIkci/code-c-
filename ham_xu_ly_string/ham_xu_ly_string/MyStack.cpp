#include "MyStack.h"
bool isEmpty(ref h) {
	return (h == nullptr);
}
void push(ref &s, int k) {
	ref p;
	p = GetNode(k);
	if (p) {
		p->next = s;
		s = p;
	}
}
ref pop(ref &s) {
	if (isEmpty(s)) {
		cout << "stack is empty\n"; exit(-1);
	}
	ref p; p = s;
	s = s->next;
	//int k = s->key;
	p->next = nullptr;
	return p;
}