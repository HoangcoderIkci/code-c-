#pragma once
#include "myFunction.h"
#include "myDaThuc.h"
#include "POLE.h"
template<class T=int>
class matrix
{
public:
	int s_row;
	int s_column;
	vector<vector<T> > matrann;
	// khai bao mac dinh r=cl=0,
	matrix();
	// khai bao cho matran vuong
	matrix(const int& sz);
	// khai bao cho matran khong vuong
	matrix(const int&, const int&);
	// khoi tao gia tri
	matrix(vector<vector<T> >);
	friend ostream& operator<<(ostream & out, const matrix<T>& mt) {
		out << mt.matrann;   
		return out;
	}
	friend istream& operator>>(istream & in, matrix& mt) {
		cout << "nhap so row matrix: "; cin >> mt.s_row;
		cout << "nhap so column matrix: "; cin >> mt.s_column;
		cout << "nhap ma tran:\n";
		matrix phu(mt.s_row, mt.s_column);
		mt = phu;
		loop(i, 0, mt.s_row)
			loop(j, 0, mt.s_column) {
			cout << "a[" << i << "][" << j << "]: "; in >> mt.matrann[i][j];
		}
		return in;
	}
	vector<T>& operator[](int);
	matrix<T> operator*(const matrix<T>&);
	matrix<T> operator+(const matrix<T>&);
	matrix<int> operator%(const int& ml) {
		loop(i,0,this->s_row)
			loop(j, 0, this->s_column) {
			(*this)[i][j] %= ml;
		}
		return *this;
	}
	matrix<T> getMatrixFromFile(char[],int bgin=0);
	friend matrix pow_mtr(const matrix& mt, const int&hs) {
		if (hs == 0) {
			matrix res(mt.s_row, mt.s_row);
			loop(i, 0, mt.s_row) {
				res[i][i] = 1;
			}
			return res;
		}
		matrix <T> res = mt;
		loop(i, 0, hs - 1) {
			res = res*mt;
		}
		return res;
	}
	friend class DaThuc;
};

template<class T>
inline matrix<T>::matrix()
{
	int fomat_cho_btap_kthuoc=6;
	this->s_row = fomat_cho_btap_kthuoc; this->s_row = fomat_cho_btap_kthuoc;
	this->matrann.resize(fomat_cho_btap_kthuoc);
	loop(i, 0, fomat_cho_btap_kthuoc) {
		this->matrann[i].resize(fomat_cho_btap_kthuoc);
	}
	
}

template<class T>
inline matrix<T>::matrix(const int & sz)
{
	this->s_row = sz;
	this->s_column = sz;
	matrann.resize(sz);
	loop(i, 0, sz) {
		matrann[i].resize(sz);
	}
}

template<class T>
inline matrix<T>::matrix(const int & r, const int & cl)
{
	s_row = r; s_column = cl;
	vector<vector<T> >vec(r,vector<T>(cl));
	matrann = vec;
}

template<class T>
inline matrix<T>::matrix(vector<vector<T> >v)
{
	matrann = v;
	s_row = v.size();
	s_column = v[0].size();
}



template<class T>
inline vector<T>& matrix<T>::operator[](int idex)
{
	vector<T>err(1);
	if (idex >= s_row)
	{
		cout << "error!!vuot qua chi so mang\n"; return err;
	}
	return this->matrann[idex];
}

template<class T>
inline matrix<T> matrix<T>::operator*(const matrix<T>& a)
{
	int r = this->s_row;
	int l = a.s_column;
	matrix<T>res(r,l);
	res.matrann = this->matrann*a.matrann;
	return res;
}

template<class T>
inline matrix<T> matrix<T>::operator+(const matrix<T>&a)
{
	if (this->s_row != a.s_row || this->s_column != a.s_column) {
		cout << "matrix khong phu hop kich thuoc\n";
		system("pause"); exit(1);
	}
	matrix<T> res = *this;
	res.matrann = res.matrann + a.matrann;
	return res;
}

template<class T>
inline matrix<T> matrix<T>::getMatrixFromFile(char name[],int bgin)
{
	fstream f;
	f.open(name, ios_base::in);
	if (f.fail()) {
		cout << "not found file!!"; exit(1);
	}
	char ch;
	int dem = -1;
	do 
	{
		f >> ch;
		if (ch == '.')dem++;
		//cout << ch;

	} while (ch!='.'||dem!=bgin);
	loop(i, 0, this->s_row) {
		loop(j, 0, this->s_column) {
			f >> (*this)[i][j];
		}
	}
	f.close();
	return *this;
}












