#pragma once
#include "myheader.h"
#define ref Node*
struct Node
{
	int key;
	ref next;
};

ref GetNode(int k);
bool addFirst(ref& head, ref& tail, int k);
bool addLast(ref &head, ref &tail, int k);
ostream& operator<<(ostream& out, ref l);
void destroyList(ref&head);
bool insertAfter(ref& q, int k);
bool insertBefore(ref &tail, ref& q, int k);
void delBeg(ref &head, ref &tail);
void delEnd(ref &head, ref &tail);
void deleteMid(ref head, ref tail, ref q);
int length(ref head);
bool insertAt(ref &head, ref &tail, int pos, int k);
void KhoiTaoList(ref &h, ref &tail);
bool deleteAt(ref &head, ref &tail, int pos);
void makeOrderedList(ref &head, int k);
ref KhoiTaoList();