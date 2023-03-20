#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <cstring>
//#include <string>
//#include <vector>
#define loop(i,a,n) for (int i = a; i < n; i++)
using namespace std;
class my_string;
class my_string {
public:
	char *my_tr=new char[100];
	my_string(){};
	my_string(char*);
	my_string operator+(const my_string& str_2);
	bool operator<(const my_string& str_2);
	bool operator==(const my_string& str_2);
	bool operator>(const my_string& str_2);
	void operator=(const my_string& str_2) {
		
		strcpy(my_tr, str_2.my_tr);
	}
};
template<class T>
class myArr {
public:
	int _size;
	T *bang_gia_tri;
	myArr(int sz) {
		_size = sz;
		if (bang_gia_tri != nullptr) {
			bang_gia_tri = new T[sz];
		}
		else {
			delete[]bang_gia_tri;
			bang_gia_tri = new T[sz];
		}
		
	}

	friend class my_string;
	void display();
	T _get_sum();
	T _get_max();
	T _get_min();
	void _xu_Ly();
};




template<class T>
T *_get_data_from_file(T arg, char name[], char typ[]) {
	int column = 9;
	T *my_str = new T[column];
	int i = 0;
	FILE *fi = fopen(name, typ);
	while (!feof(fi))
	{	
		if (arg==1) {
			fscanf(fi, "%d", &my_str[i]);
			i++;
		}
		else {
			fscanf(fi, "%f", &my_str[i]);
			i++;
		}
		
	}
	fclose(fi);
	return my_str;
}

char **_get_data_from_file_2(char[],char[]);

template<class T>
T get_min_max_2(T arr[], int sz, bool is_true = true) {
	T res = arr[0];
	if (is_true)
	{
		loop(i, 1, sz) {
			if (arr[i] < res) res = arr[i];
		}
	}
	else {
		loop(i, 1, sz) {
			if (arr[i] > res) res = arr[i];
		}
	}
	return res;
}

template<class T>
inline void myArr<T>::display()
{
	int typp;
	printf("\ndisplay string chon 0.");
	printf("\ndisplay float chon 1.");
	printf("\ndisplay int chon 2.");
	cin >> typp;
	switch (typp)
	{
	case 0:
		for (int i = 0; i < _size-2; i++)
		{
			printf("%s", bang_gia_tri[i]);
		}
		printf("\nmax : %s", bang_gia_tri[_size - 2]);
		printf("\nsum : \n%s", bang_gia_tri[_size - 1]);
		break;
	case 1:
		for (int i = 0; i < _size-2; i++)
		{
			printf("%f\n", bang_gia_tri[i]);
		}printf("\nmax : %f", bang_gia_tri[_size - 2]);
		printf("\nsum : %f\n", bang_gia_tri[_size - 1]);
		break;
	case 2:
		for (int i = 0; i < _size-2; i++)
		{
			printf("%d\n", bang_gia_tri[i]);
		}printf("\nmax : %d", bang_gia_tri[_size - 2]);
		printf("\nsum : %d\n", bang_gia_tri[_size - 1]);
	
		break;
	default:
		printf("chon lai di\n");
		break;
	}
}

template<class T>
inline T myArr<T>::_get_sum()
{
	T sum;sum = bang_gia_tri[0];
	
	for (int i = 1; i < _size; i++) {
		sum = sum + bang_gia_tri[i];
	}
		
	return sum;
}

template<class T>
inline T myArr<T>::_get_max()
{
	T res; res = bang_gia_tri[0];
	for (int i = 1; i < _size; i++)
	{
		if (bang_gia_tri[i] > res)res = bang_gia_tri[i];
	}
	return res;
}

template<class T>
inline T myArr<T>::_get_min()
{
	T res;res = bang_gia_tri[0];
	for (int i = 1; i < _size; i++)
	{
		if (bang_gia_tri[i] < res)res = bang_gia_tri[i];
	}
	return res;
}


template<class T>
inline void myArr<T>::_xu_Ly()
{
	myArr<T> res(_size + 2);
	loop(i, 0, _size) {
		res.bang_gia_tri[i] = this->bang_gia_tri[i];
	}
	T sum = this->_get_sum();
	T maxx = this->_get_max();
	//cout << this->bang_gia_tri[0] << "\n\n";
	T minn = this->_get_min();
	//cout << this->bang_gia_tri[0] << "\n\n";
	
	res.bang_gia_tri[_size] = maxx;
	res.bang_gia_tri[_size + 1] = sum;
	res.display();
	printf("\n");
}


