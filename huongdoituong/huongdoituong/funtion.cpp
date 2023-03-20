#ifndef _FUNTION_CPP
#define _FUNTION_CPP

#include "funtion.h"

vector<int> operator+(vector<int> v_1, vector<int> v_2) {
	
	vector<int> resul;
	if (v_1.size() < v_2.size()) {
		resul = v_2;
		loop(i, 0, v_1.size())
			resul[i] += v_1[i];
	} 
	else {
		resul = v_1;
		loop(i, 0, v_2.size())
			resul[i] += v_2[i];
	}
	return resul;
}

vector<int> operator++(vector<int> &vec_a) {
	vector<int> vec_b(vec_a.size(), 1);
	vec_a = vec_a + vec_b;
	return vec_a;
}
vector<int> operator--(vector<int>&a, int) {
	vector<int> res(a.size(), -1);
	a = a + res;
	return a;
}




#endif