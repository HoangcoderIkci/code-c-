#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
struct Tree
{
	int data;
	Tree *nextLeft;
	Tree *nextRight;
};
Tree *getNode(int dat) {
	Tree *nNode = new Tree;
	if (nNode == nullptr) return nullptr;
	nNode->data = dat;
	nNode->nextLeft = NULL;
	nNode->nextRight = NULL;
	return nNode;
}

void findEndReplace1(Tree *&ptr, Tree *&root) {
	if (root->nextLeft) {
		findEndReplace1(ptr, root->nextLeft);
	}
	else {
		ptr->data = root->data;
		ptr = root;
		root = root->nextRight;
	}
}

void insertNode(Tree *&root,int dat) {
	if (root == nullptr) root = getNode(dat);
	else 
		if (root->data == dat) return;
	else if (dat > root->data) insertNode(root->nextRight, dat);
	else insertNode(root->nextLeft, dat);
}
Tree *search(Tree *&itr, int dat) {
	if (itr == nullptr) return nullptr;
	else if (itr->data == dat) return itr;
		else if (itr->data < dat) search(itr->nextRight,dat);
		else search(itr->nextLeft,dat);
}
void destroyNode(Tree *&root) {
	if (root) {
		destroyNode(root->nextLeft);
		destroyNode(root->nextRight);
		delete root;
	}
}
void printf(Tree *root) {
	if (root) {
		cout << root->data << '\n';
		printf(root->nextLeft);
		printf(root->nextRight);
	}
}
void DeleteNode(Tree *&root, int dat) {
	if (root == nullptr) {
		cout << "khong tim duoc phan tu xoa!!!\n";
	}else
	if (root->data > dat) {
		DeleteNode(root->nextLeft,dat);
	}
	else if (root->data < dat) DeleteNode(root->nextRight, dat);
	else {
		Tree *ptr = root;
		if (!root->nextLeft) {
			root = root->nextRight;
		}
		else if (!root->nextRight)
			root = root->nextLeft;
		else {
			findEndReplace1(ptr, root->nextRight);
		}
		delete ptr;
	}
}
int main() {
	Tree *root = nullptr;
	insertNode(root, 5);
	insertNode(root, 4);
	insertNode(root, 7);
	insertNode(root, 6);
	for (size_t i = 1; i < 10; i++)
	{
		insertNode(root, i);
	}
	printf(root);
	DeleteNode(root, 5);
	cout << "Sau khi xoa\n";
	printf(root);
	destroyNode(root);
	cout << '\n';
	system("pause");
	return 0;
}
