#pragma once
int *IntArrayResize(int *&arr, int nItem);
int IntArraySize(int *arr);
void IntArrayFree(int *&arr);
int *IntArrayPushBack(int *&arr, int nvalue);
int  IntArrayPopBack(int *&arr);
void IntArrayOutput(int *arr);
int *IntArrayInPut();