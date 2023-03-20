#pragma once
#include"Header.h"

int poww_of_int(const int&t1, const int& t2);
template<class T>
ostream& operator<<(ostream& out, const vector<T>&a) {
	out << a[0];
	loop(i, 1, a.size())
		out <<' '<<a[i];
	return out;
}
template<class T>
ostream& operator<<(ostream& out, const vector<vector<T> >&a) {
	loop(i, 0, a.size()-1) {
		out << a[i] << '\n';
	}
	out << a[a.size()-1];
	return out;
}
template<class T,class T_2>
vector<T> operator*(const vector<T>& vec,const T_2 &hs) {
	vector<T> res = vec;
	loop(i, 0, vec.size())
		res[i] = res[i] * hs;
	return res;
}

template<class T>
vector<vector<T> > operator*(const vector<vector<T> >& vec_1, const vector<vector<T> >& vec_2) {
	if (vec_1[0].size() != vec_2.size()) {
		cout << "kich thuoc 2 matrix khong phu hop!!!\n";
			system("pause");
		exit(0);
	}
	vector<vector<T> > v_p_1 = vec_1;
	vector<vector<T> > v_p_2 = vec_2;
	vector<vector<T> >res(v_p_1.size(), (vector<T>(v_p_2[0].size(),0)));
	loop(i, 0, v_p_1.size()) {
		res[i] = vec_2[0] * v_p_1[i][0];
		loop(j, 1, v_p_1[0].size()) {
			res[i] = res[i] + v_p_2[j] * v_p_1[i][j];
		}
	}
	return res;
}

template<class T>
vector<T> operator+(const vector<T>& vec_1, const vector<T>& vec_2) {
	int len = (vec_1.size() > vec_2.size()) ? vec_1.size() : vec_2.size();
	vector<T> res;
	res = vec_1;
	res.resize(len);
	loop(i, 0, vec_2.size())
		res[i] = res[i]+ vec_2[i];
	return res; 
}
// tim ucln


vector<vector<int> > get_UCLN_int(const int& a, const int& b);
// au+bv=1, b<a;
int get_v(const int& a, const int& b);
int get_u(const int& a, const int& b);

// tim bac cua phan tu trong pole Z_n
int TimBacElTrongZn(const int& i_v, const int&md);
