#ifndef _FUNTION_H
#define _FUNTION_H
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define loop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

template<class T_2> class Arrayy;
template<class T_2> class Arrayy {
private:
	vector<T_2> arr;
	int size_arr;
public:
	Arrayy(vector<T_2>, int s = 0);
	void display_arr();
};
template<class T>
vector<T> operator-(vector<T> a, vector<T> b) {
	loop(i, 0, a.size()) a[i] -= b[i];
	return a;
}
vector<int> operator+(vector<int>, vector<int>);
vector<int> operator++(vector<int>&);
vector<int> operator--(vector<int>&,int);
template<typename T>
T sum(T x, T y) { return x + y; };
template<class T_1, class T_2>
bool so_sanh(const T_1& a, const T_2& b) {
return (a >(b)) ? true : false;
}

template<class T_2>
Arrayy<T_2>::Arrayy(vector<T_2> v, int s) {
	
		arr = v;
		size_arr = v.size();
	
}
template<class T_2>
void Arrayy<T_2>::display_arr() {
	for (auto x : arr) cout << x << ' ';
}

#endif