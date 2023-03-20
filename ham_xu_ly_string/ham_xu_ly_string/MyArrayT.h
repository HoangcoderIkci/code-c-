#pragma once
#include "myheader.h" 
static int dummy_nItem;
static int headSize = sizeof(dummy_nItem); 
template<class T> 
static int memSize(T *aData) {
	if (aData == NULL) return 0;
	return headSize + *(int *)origin_addr(aData) * sizeof(T);
}
template<class T>
static void *origin_addr(T *aData) {
	if (aData == NULL) return NULL;
	return (char *)aData - headSize;
}
template<class T>
static T*data_addr(T *origin) {
	if (origin == NULL) return NULL;
	return (T*)((char *)origin + headSize);
}
template<class T>
static void set_nItem(T *aData,int n) {
	if (aData == NULL) {
		cout << "con tro chua khoi tao\n"; system("pause");
	}
	*(int *)origin_addr(aData) = n;
}
template<class T>
static int get_nItem(T *aData) {
	if (aData == NULL) return 0;
	return *(int *)origin_addr(aData);
}
template<class T>
int arrSize(T* aData) {
	if (aData == NULL) return 0;
	return get_nItem(aData);
}
template<class T>
bool arrResize(T *&aData, int n_size) {
	int sz = headSize + n_size * sizeof(T);
	T *aNew = NULL; void *origin = NULL;
	if (aData != NULL) aNew = aData;
	origin = origin_addr(aNew);
	aNew = (T*)realloc(origin, sz);
	if (aNew != NULL) {
		if (aData == NULL) {
			memset(aNew, 0, sz);
		}
		aData = aNew;
		set_nItem(aData, n_size);
		return true;
	}
	return false;
}
template<class T>
void arrFree(T* &aData) {
	if (aData != NULL) {
		free(origin_addr(aData));
	}
}
template<class T>
bool arrPushBach(T* aData, T x) {
	int sizeArr = 0;
	if (aData != NULL) {

		sizeArr = get_nItem(aData);
	}
	if (arrResize(aData,sizeArr+1)) {
		aData[sizeArr] = x;
		return true;
	}
	return false;
}
template<class T>
T arrPopBack(T *&aData) {
	if (aData == NULL) {
		cout << "data is empty"; system("pause"); exit(0);
	}
	int sizeArr = arrSize(aData);
	T x = aData[sizeArr - 1];
	arrResize(aData, sizeArr - 1);
	return x;
}