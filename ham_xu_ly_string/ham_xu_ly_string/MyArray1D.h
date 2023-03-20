#pragma once

void *arrInit(int nItem, int sizeItem);
int arrSize(void *aData);
int arrSizeItem(void *aData);
void *arrResize(void *&aData, int nItem);
void *arrPushBack(void*&aData, void *x);
void* arrPopBack(void*&aData);