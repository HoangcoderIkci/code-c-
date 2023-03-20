#pragma once
#include "myFunction.h"
#include "matrix.h"
template<class T=int>
class myDaThuc {
public:
	myDaThuc() {};
	myDaThuc(vector<matrix<T> >);
	vector<matrix<T> > arr_dt;
	int bac_da_thuc;
	int kich_thuoc;
	int modul;
	void Get_dt(const int&);
	//matrix pow_dt(const int &);
	//myDaThuc Get_Da_thuc();
	friend istream& operator>>(istream& in,myDaThuc&dt) {
		cout << "nhap bac cua da thuc: \n"; in >> dt.bac_da_thuc;
		dt.arr_dt.resize(dt.bac_da_thuc + 1);
		loop(i, 0, dt.bac_da_thuc + 1) {
			cout << "nhap he so bac " << i<<'\n'; in >> dt.arr_dt[i];
		}
		dt.kich_thuoc = dt.arr_dt[0].s_row;
		return in;
	}
	friend ostream& operator<<(ostream& out, const myDaThuc&dt) {
		out << "bac da thuc: " << dt.bac_da_thuc << '\n';
		loop(i, 0, dt.bac_da_thuc + 1) {
			out << dt.arr_dt[i] << " x^" << i<<'\n';
		}
		return out;
	}
	matrix<T> operator() (const matrix<T>& mt){
		matrix<T> res;
		res = this->arr_dt[this->bac_da_thuc] * pow_mtr(mt, bac_da_thuc);
		loop(i, 0, this->bac_da_thuc) {
			res = res + (this->arr_dt[i] * pow_mtr(mt, i));
		}
		return res;
	}
};

template<class T>
inline myDaThuc<T>::myDaThuc(vector<matrix<T>>)
{
}

template<class T>
inline void myDaThuc<T>::Get_dt(const int&)
{
	int fomat_r = 6, fomat_cl = 6;
	cout << "bac dathuc: ";
	cin >> this->bac_da_thuc;
	arr_dt.resize(bac_da_thuc + 1);
	loop(i, 0, bac_da_thuc + 1) {
		this->arr_dt[i].s_row = fomat_r;
		this->arr_dt[i].s_column = fomat_cl;
		this->arr_dt[i].getMatrixFromFile("dshs.txt", i+1);
		this->arr_dt[i] = this->arr_dt[i] % 5;
	}

}

