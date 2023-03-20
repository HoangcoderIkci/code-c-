#include "myLitst.h"
//#include "myheader.h"
ostream& operator<<(ostream& out, ref l) {
	if (l == nullptr) {
		out << "danh sach trong .";
		return out;
	}

	ref ptr = l;
	while (ptr->next)
	{
		out << ptr->key << "->";
		ptr = ptr->next;
	}
	out << ptr->key;
	return out;
}
ref GetNode(int k) {
	ref ptr;
	ptr = (ref)malloc(sizeof(Node));
	if (ptr == nullptr) {
		cout << "\n!!het bo nho\n";
		system("pause"); exit(-1);
	}
	ptr->key = k;
	ptr->next = nullptr;
	return ptr;
}
bool addFirst(ref& head, ref& tail, int k) {
	ref p = GetNode(k);
	if (head == nullptr) {
		head = tail = p;
	}
	else {
		p->next = head;
		head = p;
	}
	return true;
}
bool  addLast(ref &head, ref &tail, int k) {
	ref p = GetNode(k);
	if (!p) return false;
	if (head == nullptr) {
		head = tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
	return true;
}

void destroyList(ref&head) {
	if (head == nullptr) return;
	ref p;
	while (head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}
bool insertAfter(ref& q, int k) {
	ref p = GetNode(k);
	if (!p) return false;
	p->next = q->next;
	q->next = p;
	return true;
}
bool insertBefore(ref &tail, ref& q, int k) {
	ref	p = (ref)malloc(sizeof(Node));
	if (p == nullptr) return false;
	*p = *q;
	q->next = p;
	q->key = k;
	if (tail->next)
		tail = tail->next;
	return true;
}
void delBeg(ref &head, ref &tail) {
	if (head == tail) {
		free(head);
		head = tail = nullptr;
	}
	else {
		ref p = head;
		head = head->next;
		free(p);
	}
}
void delEnd(ref &head, ref &tail) {
	if (head == tail) {
		free(head);
		head = tail = nullptr;
	}
	else {
		ref p = head;
		while (p->next != tail)
		{
			p = p->next;
		}
		free(tail);
		tail = p;
		p->next = nullptr;
	}
}
void deleteMid(ref head, ref tail, ref q) {
	if (q == head) {
		delBeg(head, tail);
		return;
	}
	if (q == tail) {
		delEnd(head, tail);
		return;
	}
	ref r;
	for (r = head; r->next != q; r = r->next);
	r->next = q->next;
	free(q);
	q = nullptr;
}
/*
void delMid(ref q) {
ref r;
r = q->next;
*q = *r;
free(r);
r = nullptr;
}*/
int length(ref head) {
	if (!head) return 0;
	ref p = head;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}
bool insertAt(ref &head, ref &tail, int pos, int k) {
	int n = length(head);
	if (pos < 0 || pos>n) {
		cout << "vi tri chen ngoai pham vi list\n"; system("pause");
		return false;
	}
	if (pos == 0) {
		if (addFirst(head, tail, k))
			return true;
		return false;
	}
	if (pos == n) {
		if (addLast(head, tail, k))
			return true;
		return false;
	}
	ref p = head;
	loop(i, 0, pos) {
		p = p->next;
	}
	if (insertBefore(tail, p, k))
		return true;
	return false;
}
void KhoiTaoList(ref &h, ref &tail) {
	int k;
	cout << "khoi tao list:  \n";
	while (cin >> k)
	{
		addLast(h, tail, k);
	}
}
bool deleteAt(ref &head, ref &tail, int pos) {
	if (head == nullptr) return true;
	int n = length(head);
	if (pos < 0 || pos >= n) {
		cout << "vi tri xoa khong hop le!1\n"; return false;
	}
	if (pos == 0)delBeg(head, tail);
	else if (pos == n - 1) {
		delEnd(head, tail);
	}
	else {
		int i; ref ptr = head;
		for (i = 0; i < pos; i++, ptr = ptr->next);
		deleteMid(head, tail, ptr);
	}
	return true;
}
void makeOrderedList(ref &head, int k) {
	ref p; ref p1; ref p2;
	p1 = head; p2 = head->next;
	while (p2&&p2->key < k)
	{
		p1 = p2;
		p2 = p2->next;
	}
	p = GetNode(k);
	p1->next = p;
	p->next = p2;
}
ref KhoiTaoList() {
	ref h = (ref)malloc(sizeof(Node));
	if (h == nullptr) return nullptr;
	h->next = nullptr;
	int k, n;
	do 
	{
		cout << "nhap so luong node: ";
		cin >> n;
	} while (n<1);
	loop(i, 0, n) {
		printf("nhap gia tri node[%d] :", i); scanf("%d", &k);
		makeOrderedList(h, k);
	}
	h = h->next;
	return h;
}
