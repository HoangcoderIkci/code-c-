#include "myheader.h"
#include "MyArray2D.h"

#pragma pack(1)
typedef struct
{
	int m, n,sizeItem;
	void *Data[1];
}aStruct;
static aStruct adummy;
static int headSize = sizeof(adummy.m) + sizeof(adummy.n) + sizeof(adummy.sizeItem);
void **alloc2D(int m, int n, int sizeItem) {
	if (m <= 0 || n <= 0 || sizeItem <= 0) return nullptr;
	aStruct *as;
	void **temp = nullptr; void *buffer = nullptr; void *data = nullptr;
	size_t sz1, sz2, szRow;
	sz1 = m*sizeof(void *); szRow = n*(size_t)sizeItem;
	sz2 = szRow*m;
	buffer = calloc(headSize + sz1 + sz2, 1);
	if (buffer == nullptr) return nullptr;
	as = (aStruct*)buffer;
	as->m = m; as->n = n; as->sizeItem = sizeItem;
	data = (void*)((char*)buffer + headSize + sz1);
	as->Data[0] = data;
	loop(i, 1, m) {
		data = (char*)data + szRow;
		as->Data[i] = data;
	}
	return as->Data;
}
void Free2D(void**a) {
	if (a) {
		void* dest = (char*)a - headSize;
		free(dest);
	}
}
void **arrResize(void **a,int m_new, int n_new) {
	if (n_new <= 0) return nullptr;
	int m_old, n_old,sItem;
	void **aNew = nullptr;
	aStruct *as = (aStruct*)((char*)a - headSize);
	sItem = as->sizeItem;
	aNew=alloc2D(m_new, n_new,sItem);
	if (aNew == nullptr) {
		printf("resize fail\n"); system("pause"); return a;
	}
	m_old = as->m; n_old = as->n;
	int i = 0, j = 0;
	for (i = 0; i <m_old&&i<m_new; i++)
		for (j = 0; j < n_new&&j<n_old; j++)
		{
			char*dest = (char*)aNew[i] + j*sItem;
			char*src = (char*)a[i] + j*sItem;
			memcpy(dest, src, sItem);
		}
	Free2D(a);
	return aNew;
}
int arrRow(void **a) {
	aStruct *sz =(aStruct*)((char*)a - headSize);
	return sz->m;
}
int arrColumn(void **a) {
	aStruct *sz = (aStruct*)((char*)a - headSize);
	return sz->n;
}
