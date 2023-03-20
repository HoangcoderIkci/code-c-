#pragma once
#include "MY_NODE.h"

class my_list
{
public:
	MY_NODE<int>* l_head;
	MY_NODE<int>* l_tail;
	my_list() {
		l_head = new MY_NODE<int>;
		l_tail = new MY_NODE<int>;
	};
	my_list(MY_NODE<int> *n) {
		l_head = n;
		l_tail = n;
	};
	void addNodeHead(MY_NODE<int>* new_node) {
		if (l_head == NULL) {
			l_tail = new_node;
			l_head = new_node;
		}
		else {
			(*new_node).next = (this->l_head);
			l_head = new_node;
		}
	}
	void addNodeBack(MY_NODE<int>* new_node) {
		if (l_head == NULL) {
			l_tail = new_node;
			l_head = new_node;
		}
		else {
			(*l_tail).next = new_node;
			l_tail = new_node;
		}
	}
	int size_list() const{
		my_list l = *this;
		int res = 0;
		while (l.l_head!=NULL)
		{
			res++;
			l.l_head = l.l_head->next;
		}return res;
	}
	void addAt(MY_NODE<int>* new_node, int adr) {
		int size_l = this->size_list();
		if (adr == 1) {this->addNodeHead(new_node); return;}
		if (adr > size_l) {
			this->addNodeBack(new_node);
		}
		else {
			MY_NODE<int> *itr = this->l_head;
			loop(i, 2, adr) {
				itr = itr->next;
			}
			new_node->next = itr->next;
			itr->next = new_node;  
		}
	}
	bool isl_empty() {
		return !(this->l_head);
	}
	void erase_at_l(int id) {
		if (isl_empty()) return;
		if (id > this->size_list()) return;
		MY_NODE<int> * node_erase;
		MY_NODE<int> * itr = this->l_head;
		if (id == this->size_list()) {
			loop(i, 2, this->size_list()) {
				itr = itr->next;
			}
			this->l_tail = itr;
			itr = itr->next;
			itr = NULL;
			delete itr;
			return;
		}
		if (id == 1) {
			/*Node* node = l.head;
			x = node->data;      // L?u giá tr? c?a node head l?i
			l.head = node->next;
			delete node;*/
			this->l_head = itr->next;
			itr = NULL;
			delete itr;
		}
		else {
			loop(i, 2, id) {
				itr = itr->next;
			}
			node_erase = itr->next;
			itr->next = node_erase->next;
			node_erase = NULL;
			delete node_erase;
			//node_erase = NULL;
		}
			
	}
	MY_NODE<int> * findInList(const int&gt) const{
		MY_NODE<int> *itr = this->l_head;
		while (itr!=NULL)
		{
			if (itr->data == gt) return itr;
			itr = itr->next;
		}
		cout << "not find!!!\n";
		return NULL;
	}
	MY_NODE<int> * operator[](const int&id) const{
		if (id > this->size_list()-1) return NULL;
		if (id == 0) return this->l_head;
		if (id == this->size_list() - 1) return this->l_tail;
		MY_NODE<int> * itr = this->l_head;
		loop(i, 0, id) {
			itr = itr->next;
		}
		return itr;
	}
	friend ostream & operator<<(ostream &out, const my_list& l);/* {
		if (l.l_head == NULL) out << "empty\n"; else {
			do
			{
				out << (*l.l_head).data;
				l.l_head = l.l_head->next;
			} while (l.l_head!=l.l_tail);
		}
		return out;*/
};
inline	ostream & operator<<(ostream &out, const my_list& l_1) {
		my_list l = l_1;
		if (l.l_head == NULL) out << "empty\n"; else {
			do
			{
				out << (*l.l_head).data << "-->";
				l.l_head = l.l_head->next;
			} while (l.l_head != l.l_tail);
			out << (*l.l_tail).data << '\n';
		}
		return out;
	}
