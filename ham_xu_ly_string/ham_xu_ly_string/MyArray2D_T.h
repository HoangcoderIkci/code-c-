#pragma once
#include "myheader.h"
static int mOffs = 0; static int nOffs = 1;
static int headSize = 2 * sizeof(int);
template<class T>
bool alloc2D_T(T**&a, const int &m, const int &n) {
	if (m <= 0 || n <= 0) return false;
	int *buffS = nullptr; void *src = nullptr;
	void **aNew = nullptr;
	void *data = nullptr;
	size_t sz1, sz2, szRow;
	szRow = n*sizeof(T);
	sz1 = m*sizeof(T*);
	sz2 = m*szRow;
	src = calloc(headSize + sz1 + sz2, 1);
	if (src == nullptr) return false;
	buffS = (int*)src;
	buffS[mOffs] = m;
	buffS[nOffs] = n;
	aNew = (void**)((char*)src + headSize);
	aNew[0] = data =(void*)((char*)aNew + sz1);
	loop(i, 1, m) {
		data = (void*)((char*)data + szRow);
		aNew[i] = data;
	}
	a = (T**)aNew;
	return true;
}
template<class T>
int arrnSize(T**arr) {
	int *ns =(int*) ((char*)arr - headSize);
	return ns[nOffs];
}
template<class T>
int arrmSize(T**arr) {
	int *ns =(int*) ((char*)arr - headSize);
	return ns[mOffs];
}
template<class T>
bool arrResize(T **&arr, int m_new, int n_new) {
	if (m_new <= 0 || n_new <= 0) return false;
	int m_old, n_old; m_old = arrmSize(arr); n_old = arrnSize(arr);
	T **a_new = nullptr;
	if (alloc2D_T(a_new, m_new, n_new)) {
		int i=0, j=0;
		for (i = 0; i <m_new&&i<m_old ; i++)
		{
			for (j = 0; j<n_old&&j<n_new; j++)
			{
				a_new[i][j] = arr[i][j];
			}
		}
		arr = a_new;
		return true;
	}
	return false;
}
template<class T>
void arrIn(T**&a) {
	int m, n;
	m = arrmSize(a);
	n = arrnSize(a);
	printf("\nkhoi tao mang: \n");
	loop(i, 0, m) {
		loop(j, 0, n) {
			printf("a[%i][%i] = ",i,j);
			cin >> a[i][j];
		}
	}
}
template<class T>
void arrOut(T**a) {
	int m, n;
	m = arrmSize(a);
	n = arrnSize(a);
	//printf("\nkhoi tao mang: \n");
	loop(i, 0, m) {
		loop(j, 0, n) {
			cout << a[i][j] << '\t';
		}printf("\n");
	}
}
template<class T>
void arrFree(T **a) {
	if (a) {
		void*temp = (char*)a - headSize;
		free(temp);
	}
}