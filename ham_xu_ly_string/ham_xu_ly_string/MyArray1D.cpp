#include "MyArray1D.h"
#include "myheader.h"
static int sz_nItem;
static int sz_sizeItem;
static int headSize = sizeof(sz_nItem) + sizeof(sz_sizeItem);

static int memSize(int nItem,int sizeItem) {    // so luong byte duoc cap phat.
	if (sizeItem < 0)sizeItem = -sizeItem;
	if (sizeItem == 0)sizeItem = 1;
	if (nItem < 0)nItem = -nItem;
	return headSize + sizeItem*nItem;
}

static void* origin_addr(void *aData) {
	if(aData!= NULL)
	return (char*)aData - headSize;
	return NULL;
}

static void* data_addr(void *origin) {
	if (origin == NULL) return NULL;
	return (char*)origin + headSize;
}
static int *nItem_addr(void *aData) {
	if (aData == NULL) return NULL;
	return (int*)origin_addr(aData);
}
static int *sizeItem_addr(void *aData) {
	if (aData == NULL) return NULL;
	return (int *)(char *)aData - sizeof(sz_sizeItem);
}

void *arrInit(int nItem, int sizeItem) {
	void *aOrigin = NULL; void *aData = NULL;
	int sz = memSize(nItem, sizeItem);
	aOrigin = malloc(sz);
	if (aOrigin != NULL) {
		memset(aOrigin, 0, sz);
		aData = data_addr(aOrigin);
		*nItem_addr(aData) = nItem;
		*sizeItem_addr(aData) = sizeItem;
	}return aData;
}
int arrSize(void *aData) {
	if (aData == NULL) return 0;
	return *nItem_addr(aData);
}
int arrSizeItem(void *aData) {
	if (aData == NULL) return 0;
	return *sizeItem_addr(aData);
}
void *arrResize(void *&aData,int nItem) {
	int sz, szItem;
	if (nItem < 0) return NULL;
	if (aData == NULL) {
		aData = arrInit(nItem, sz_sizeItem);
			return aData;
	}
	void *aOrigin = NULL; void *aNew = NULL;
	aOrigin = origin_addr(aData);
	szItem = *sizeItem_addr(aData);
	sz = memSize(nItem, szItem);
	aNew = realloc(aOrigin, sz);
	if (aNew != NULL) {
		aData = data_addr(aNew);
		*nItem_addr(aData) = nItem;
		return aData;
	}return NULL;
}
void* arrPushBack(void*&aData, void *x) {
	int nItem = arrSize(aData);
	int sizeItem = *sizeItem_addr(aData);
	void *aNew = NULL; void *arr = NULL;
	if (aData != NULL) arr = aData;
	aNew = arrResize(arr, nItem+1);
	if (aNew != NULL) {
		memcpy((char*)aNew + nItem*sizeItem, x, sizeItem);
		aData = aNew;
	}
	return aData;
}
void* arrPopBack(void*&aData) {
	if (aData == NULL) return NULL;
	int nItem = arrSize(aData);
	int szItem = *sizeItem_addr(aData);
	void *x = malloc(szItem);
	memcpy((char*)x, (char*)aData + nItem - 1, szItem);
	arrResize(aData,nItem-1);
	return x;
}
