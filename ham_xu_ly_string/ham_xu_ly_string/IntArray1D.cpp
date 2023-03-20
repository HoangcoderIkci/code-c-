#pragma once
#include "IntArray1D.h"
#include "myheader.h"
static int dummy_nItem;
static int headSize = sizeof(dummy_nItem);
static int memSize(int nItem) {
	if (nItem < 0) nItem = -nItem;
	return headSize + nItem*sizeof(int);
}
static void *Origin_add(void *aData) {
	return (char*)aData - headSize;
}
static int *Data_addr(void *origin) {
	return (int*)((char*)origin + headSize);
}
static void set_nItem(int *aData, int nItem) {
	*(int*)Origin_add(aData) = nItem;
}
static int get_nItem(int *&aData) {
	return *(int*)Origin_add(aData);
}
int *IntArrayResize(int *&aData, int nItem) {
	int sz = memSize(nItem);
	int *aNew = NULL; void *origiaddr = NULL;
	if (aData!=NULL)
		origiaddr = Origin_add(aData);
	aNew = (int *)realloc(origiaddr, sz);
	if (aNew) {
		if (aData == NULL) {
			memset(aNew, 0, sz);
		}
		aData = Data_addr(aNew);
		set_nItem(aData, nItem);
	}
	//cout << IntArraySize(aData);
	return aData;
}
/*
int *IntArrayResize(int *aData, int nItem) {
	int sz = memSize(nItem);
	int *aNew = NULL; void *originAddr = NULL;
	if (aData)
		originAddr = Origin_add(aData);
	aNew = (int *)realloc(originAddr, sz);
	if (aNew) {
		if (aData==NULL) {
			memset(aNew, 0, sz);
		}
		aData = Data_addr(aNew);
		set_nItem(aData, nItem);
	}
	return aData;
}*/
int IntArraySize(int *aData) {
	if (aData == NULL) return 0;
	return get_nItem(aData);
}
void IntArrayFree(int *&aData) {
	if (!aData)
		free(Origin_add(aData));
}
int *IntArrayPushBack(int *&aData, int nvalue) {
	int n_size=1;
	int *a_new = NULL;
	if (aData) {
		n_size = IntArraySize(aData) + 1;
		
	}
	a_new=IntArrayResize(aData, n_size);
	if (a_new) {
		a_new[n_size - 1] = nvalue;
		aData = a_new;
	}
	return aData;
}
int IntArrayPopBack(int *&aData) {
	int res;
	if (!aData)
		return -17;
	int nItem = IntArraySize(aData);
	if (nItem >= 0) {
		res = aData[nItem-1];
		IntArrayResize(aData, nItem-1);
	}
	return -17;
}
void IntArrayOutput(int *arr) {
	int i,n = IntArraySize(arr);
	for (i = 0; i < n; i++)
		printf("%d\t", arr[i]);
}
int *IntArrayInPut() {
	int *arr = NULL; int x;
	while (scanf("%d",&x))
	{
	IntArrayPushBack(arr,x);	
	}
	return arr;
}