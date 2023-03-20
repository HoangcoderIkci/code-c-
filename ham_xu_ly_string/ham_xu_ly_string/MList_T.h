#pragma once
#define n_T Node_T<T>

template<class T>
struct Node_T 
{
	T data;
	Node_T *pNext;
};

template<class T>
void insertFirst(n_T* &head,const T &dat) {
	if (head == NULL) {
		head = new n_T;
		head->data = dat;
		head->pNext = nullptr;
	}
	else {
		n_T*tmp = head;
		n_T*p = new n_T;
		if (p == nullptr)exit(-1);
		head = p;
		p->data = dat;
		p->pNext = tmp;
	}
}
template<class T>
void insertFirst(n_T* &head, n_T* &new_node) {
	if (head == nullptr) {
		head = new_node;
	}
	else {
		new_node->pNext = head;
		head = new_node;
	}
}
template<class T>
void freeList(n_T*&head) {
	if (head) {
		n_T* ptr;
		while (head->pNext)
		{
			ptr = head;
			head = head->pNext;
			free(ptr);
		}
		free(head);
		head = nullptr;
	}
}
template<class T>
void printfList(n_T *&head) {
	if (head == nullptr) {
		cout << "list is empty\n";
	}
	else {
		n_T* itr = head;
		while (itr->pNext)
		{
			cout << itr->data << "->";
			itr = itr->pNext;
		}
		cout << itr->data;
	}
	
}
template<class T>
int sizeList(n_T *&head) {
	int count = 0;
	n_T *itr = head;
	for (count = 0; itr; itr = itr->pNext, count++);
	return count;
}
template<class T>
int IsEmptyL(n_T *&head) {
	return (head == nullptr);
}
template<class T>
void insertEnd(n_T* &head, T d) {
	if (head == nullptr) {
		insertFirst(head, d);
	}
	else {
		n_T* itr = getTail(head);
		n_T*new_node = new n_T;
		new_node->data = d;
		new_node->pNext = nullptr;
		itr->pNext = new_node;
	}
}
template<class T>
n_T* getTail(n_T*&head) {
	n_T* itr;
	for (itr = head; itr->pNext; itr = itr->pNext);
	return itr;
}
template<class T>
n_T*findList(n_T* &head, const T&d) {
	n_T*itr = head;
	while (itr->data!=d)
	{
		itr = itr->pNext;
	}
	return itr;
}
template<class T>
n_T*findList(n_T* &head, n_T* &p) {
	if (p == nullptr) return nullptr;
	T d = p->data;
	return findList(head, d);
}
template<class T>
int countList(n_T* &head,const T&d) {
	if (head == nullptr) return 0;
	n_T* itr = head; int count = 0;
	while (itr)
	{
		if (itr->data == d) count++;
		itr = itr->pNext;
	}
	return count;
}
template<class T>
n_T*findList(n_T* &head, n_T* &p,bool(*cmp)(T&,T&)) {
	if (p == nullptr) return nullptr;
	T d = p->data;
	return findList(head, d);
}
template<class T,class T2>
n_T*findList_cmp(n_T* &head, const T2&d, bool(*cmp)(T*, T*)=nullptr) {
	if (head == nullptr) return nullptr;
	n_T*itr = head;
	bool(*chk)(T*, T*) = cmp;
	if (cmp == nullptr)chk = isEqual_default;
	while (itr)
	{
		if(chk(&itr->data, (T*)&d))
			break;
		itr = itr->pNext;
	}
	return itr;
}
template<class T>
bool isEqual_default(T *x, T*y) {
	return *x == *y;
}
template<class T>
n_T*insertAfter(n_T*&head, const T&X, const T&val, bool(*cmp)(T *, T*) = nullptr) {
	n_T *cur = findList_cmp(head, X, cmp);
	if (cur == nullptr) return nullptr;
	if (cur == head) {
		insertFirst(head, val);
		return head;
	}
	n_T*new_node = new n_T;
	if (new_node == nullptr) return new_node;
	new_node->data = val;
	new_node->pNext = cur->pNext;
	cur->pNext = new_node;
	return new_node;
}
template<class T>
n_T*insertBefore(n_T*&head, const T&X, const T&val, bool(*cmp)(T *, T*) = nullptr) {
	n_T *cur = findList_cmp(head, X, cmp);
	if (cur == nullptr) return nullptr;
	n_T*new_node = new n_T;
	if (new_node == nullptr) return new_node;
	*new_node = *cur;
	cur->pNext = new_node;
	cur->data = val;
	return cur;
}
template<class T>
T delBegin(n_T*&head) {
	T res = head->data;
	n_T* p = head;
	head = p->pNext;
	free(p);
	p = nullptr;
	return res;
}
template<class T>
T delEnd(n_T*&head) {
	if (head == nullptr) {
		cout << "error empty khong the delEnd\n"; system("pause"); exit(-1);
	}
	T res; n_T* tail;
	n_T* itr;
	for (itr = head; itr->pNext->pNext; itr = itr->pNext);
	tail = itr->pNext;
	res = tail->data;
	itr->pNext = nullptr;
	free(tail);
	return res;
}
template<class T>
n_T*find_next(n_T*head,T dat, bool(*cmp)(T *, T*) = nullptr) {
	bool ok = false;
	if (head == nullptr) return nullptr;
	n_T *itr = head;
	bool(*chk)(T *, T*) = cmp;
	if (chk == nullptr) chk = isEqual_default;
	while (itr->pNext)
	{
		if (chk(&itr->pNext->data, &dat)) { 
			ok = true; break;
		}
		itr = itr->pNext;
	}
	return (ok) ? itr : nullptr;
}
template<class T>
bool deleteNoteGiaTriX(n_T *&head, T X, bool(*cmp)(T *, T*) = nullptr) {
	if (head == nullptr) return false;
	if (head->data == X) {
		delBegin(head); return true;
	}
	n_T *itr; n_T *temp;
	itr = find_next(head, X);
	if (itr == nullptr) return false;
	temp = itr->pNext;
	if (temp->pNext == nullptr) {    // truong hop temp = tail
		itr->pNext = nullptr;
		free(temp);
		temp = nullptr; return true;
	}
	itr->pNext = temp->pNext;
	free(temp); temp = nullptr;
	return true;
}
template<class T>
bool deleteNodeAt(n_T *&head, int index, bool(*cmp)(T *, T*) = nullptr) {
	if (head == nullptr) return false;
	int sizeL = sizeList(head);
	if (index < 0 || index >= sizeL) return false;
	n_T *itr = head; int i; n_T *temp;
	if (index == 0) {
		head = head->pNext;
		free(itr);
		itr = nullptr;
		return true;
	}
	for (i = 0; i < index - 1; i++, itr = itr->pNext);
	temp = itr->pNext;
	if (temp == nullptr) {
		itr->pNext = nullptr; free(temp); temp = nullptr;
		return true;
	}
	itr->pNext = temp->pNext;
	free(temp); temp = nullptr;
	return true;
}
template<class T>
void writeList(ostream& outDev, n_T *head) {
	if (head == nullptr) {
		outDev << "list is empty\n";
	}
	else {
		n_T* itr = head;
		while (itr->pNext)
		{
			outDev << itr->data << "->";
			itr = itr->pNext;
		}
		outDev << itr->data;
	}
}
template<class T>
void readList(istream& inDev, n_T *&head) {
	T dat;
	while (inDev)
	{
		if(inDev >> dat)
		insertFirst(head, dat);
	}
}
template<class T>
void readListOrdered(istream& inDev, n_T *&head, bool(*cmp)(T *, T*) = nullptr) {
	T dat;
	while (inDev)
	{
		if (inDev >> dat)
			insertOrderedList(head, dat,cmp);
	}
}
template<class T>
void readListB(istream& inDev, n_T *&head) {
	T dat; n_T *p = head;
	while (inDev)
	{
		if(!(inDev >> dat))break;
		if (head == nullptr) {
			head = new n_T; p = head;
			p->data = dat;
			p->pNext = nullptr;
		}
		else {
			n_T *itr = new n_T;
			if (itr != nullptr) {
				itr->data = dat;
				itr->pNext = nullptr;
				p->pNext = itr;
				p = itr;
			}
		}
	}
}
template<class T>
n_T *makeNode(T X) {
	n_T *head = new n_T;
	if (head == nullptr) return nullptr;
	head->data = X;
	return head;
}
template<class T>
bool sapXepDefault(T *a, T *b) {
	return *a < *b;
}
template<class T>
n_T *insertOrderedList(n_T *&head,T X, bool(*cmp)(T *, T*) = nullptr) {
	n_T *cur; n_T *newNode = makeNode(X);
	if (newNode == nullptr) return nullptr;
	bool(*chk)(T *, T*) = cmp;
	if (cmp == nullptr) chk = sapXepDefault;
	if (head == nullptr|| (!chk(&head->data,&X))) {
		newNode->pNext = head;
		head = newNode;
		return head;
	}
	/*if (head->pNext == nullptr) {
		if (head->data <= X) {
			head->pNext = newNode;
			return newNode;
		}
		else {
			newNode->pNext = head;
			head = newNode;
			return newNode;
		}
	}*/
	cur = head;
	while (cur->pNext&&chk(&cur->pNext->data, &X))
	{
		cur = cur->pNext;
	}
	newNode->pNext = cur->pNext;
	cur->pNext = newNode;
	return newNode;
}
template<class T>
bool soSanhBang(T *a, T *b) {
	return *a == *b;
}
template<class T>
n_T *LoaiBoPhanTuGiongNhauListOrdered(n_T *&head) {
	n_T *cur; n_T *temp;
	if (head == nullptr) return nullptr;
	cur = head;
	while (cur&&cur->pNext)
	{
		while(cur->pNext!=nullptr && cur->data == cur->pNext->data) {
			temp = cur->pNext;
			cur->pNext = temp->pNext;
			delete temp;
			temp = nullptr;
		}
		cur = cur->pNext;
	}
	return head;
}