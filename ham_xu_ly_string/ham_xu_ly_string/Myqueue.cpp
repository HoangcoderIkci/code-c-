#include "MyQueue.h"
void enQueue(ref &Q,ref &T, int k) {
	ref p;
	p = GetNode(k);
	if (p == nullptr) cout << "faiil!! het bo nho\n"; return;
	if (isEmptyQ(Q))Q = T = p;
	else {
		T->next = p;
		T = p;
	}
}
bool isEmptyQ(ref Q) {
	return (Q == nullptr);
}

ref deQueue(ref &Q,ref &T) {
	if (isEmptyQ(Q)) {
		cout << "stack is empty\n"; exit(-1);
	}
	ref p; p = Q;
	Q = Q->next;
	//int k = s->key;
	p->next = nullptr;
	return p;
}
int deQueueGetKey(ref &Q, ref &T) {
	if (isEmptyQ(Q)) {
		cout << "stack is empty\n"; exit(-1);
	}
	ref p; p = Q;
	Q = Q->next;
	//int k = s->key;
	p->next = nullptr;
	return p->key;
}