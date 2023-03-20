#pragma once
#include "myFuntionOFPole.h"

template<class T>
class ELEMENTOFPOLE
{
public:
	/*int _bac_of_elem;
	T _gia_tri_elem;
	T _elem_ndao;
	T _elem_dxung;
	T _modul;
	ELEMENTOFPOLE() {};
	ELEMENTOFPOLE(const T&md, const T&gt);
	//ELEMENTOFPOLE(const T&, const T&) {};
	ELEMENTOFPOLE<T> operator()(const T&, const T&);
	ELEMENTOFPOLE<T> operator+(const ELEMENTOFPOLE&); 
	ELEMENTOFPOLE<T> operator*(const ELEMENTOFPOLE&);
	bool operator==(const ELEMENTOFPOLE<T>&);
	bool operator!=(const ELEMENTOFPOLE<T>&);
	friend bool operator==(const ELEMENTOFPOLE<T>&el, const int&a) {
		ELEMENTOFPOLE<T> ss(el._modul, a);
		return ss == el;
	}
	friend ostream & operator<<(ostream&out,const ELEMENTOFPOLE<T>& el) {
		out << el._gia_tri_elem;
		return out;
	}*/
	/*friend istream & operator>>(istream&in, ELEMENTOFPOLE<int>& el) {
		cout << "nhap md elem: ";
		int gtri, md;
		in >> md;
		cout << "nhap gia tri elem: ";
		in >> gtri;
		el(md, gtri);
		return in;
	}*/
};



/*
template<class T>
inline ELEMENTOFPOLE<T>::ELEMENTOFPOLE(const T&md, const T &gt)
{
	this->_modul = md;
	this->_gia_tri_elem = gt%md;
	this->_elem_dxung = md - gt;
	this->_elem_ndao = (((Tim_U_V_int(md, gt)._v_int) % md) + md) % md;
	if (gt == 0) {
		this->_bac_of_elem = -17;
		this->_elem_dxung = -17;
	}
	else
	{
		this->_bac_of_elem = getBacElem(gt, md);
	}

}

template<class T>
inline ELEMENTOFPOLE<T> ELEMENTOFPOLE<T>::operator()(const T &_md, const T &_gt)
{
	ELEMENTOFPOLE<T> new(_md, _gt);
	*this = new;
	return *this;
}


template<class T>
inline ELEMENTOFPOLE<T> ELEMENTOFPOLE<T>::operator+(const ELEMENTOFPOLE &el_2)
{
	if (this->_modul != el_2._modul) {
		cout << "ERROR 2 elem khac modul.\n";
		system("pause"); exit(1);
	}
	int sum = (this->_gia_tri_elem + el_2._gia_tri_elem) % this->_modul;
	ELEMENTOFPOLE res(this->_modul, sum);
	return res;
}

template<class T>
inline ELEMENTOFPOLE<T> ELEMENTOFPOLE<T>::operator*(const ELEMENTOFPOLE &el_2)
{
	if (this->_modul != el_2._modul) {
		cout << "ERROR!! khac modul.\n";
		system("pause"); exit(-1);
	}
	T _tich = this->_gia_tri_elem*el_2._gia_tri_elem;
	ELEMENTOFPOLE<T> res(this->_modul, _tich);
	return res;
}

template<class T>
inline bool ELEMENTOFPOLE<T>::operator==(const ELEMENTOFPOLE<T>&el_2)
{
	if (this->_modul != el_2._modul) {
		cout << "ERRROR!! khac modul.\n"; exit(-1);
	}
	return this->_gia_tri_elem== el_2._gia_tri_elem;
}

template<class T>
inline bool ELEMENTOFPOLE<T>::operator!=(const ELEMENTOFPOLE<T>&el_2)
{
	if (this->_modul != el_2._modul) {
		cout << "ERRROR!! khac modul.\n"; exit(-1);
	}
	return this->_gia_tri_elem!=el_2._gia_tri_elem;
}*/


// pole Zn: 
template<>
class ELEMENTOFPOLE<int>
{
public:
	//friend class MYDATHUC<ELEMENTOFPOLE<int> >;
	int _bac_of_elem;;
	int _gia_tri_elem;
	int _elem_ndao;
	int _elem_dxung;
	int _modul=-17;
	ELEMENTOFPOLE();
	ELEMENTOFPOLE(const int&md, const int&gt);
	ELEMENTOFPOLE<int> operator()(const int&, const int&);
	ELEMENTOFPOLE<int> operator[](const int&b) const;
	friend ELEMENTOFPOLE<int> operator/(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2);
	friend ELEMENTOFPOLE<int> operator+(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2);
	friend ELEMENTOFPOLE<int> operator-(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2);
	friend ELEMENTOFPOLE<int> operator*(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2);
	friend bool operator==(const ELEMENTOFPOLE<int>& el_1, const ELEMENTOFPOLE<int>& el_2);
	friend bool operator!=(const ELEMENTOFPOLE<int>& el_1, const ELEMENTOFPOLE<int>& el_2);
	friend bool operator==(const ELEMENTOFPOLE<int>&el, const int&a);
	friend bool operator!=(const ELEMENTOFPOLE<int>&el, const int&a);
	friend ostream & operator<<(ostream&out, const ELEMENTOFPOLE<int>& el);
	friend istream & operator>>(istream&in, ELEMENTOFPOLE<int>& el);
};
vector<ELEMENTOFPOLE<int> > operator+(const vector<ELEMENTOFPOLE<int> >& v_1, const vector<ELEMENTOFPOLE<int> >&v_2);
vector<ELEMENTOFPOLE<int> > operator*(const vector<ELEMENTOFPOLE<int> >& v_1, const ELEMENTOFPOLE<int>&el);
vector<ELEMENTOFPOLE<int> > operator-(const vector<ELEMENTOFPOLE<int> >& v_1, const vector<ELEMENTOFPOLE<int> >&v_2);

inline ELEMENTOFPOLE<int>::ELEMENTOFPOLE(const int & md, const int & gt)
{
	this->_modul = md;
	this->_gia_tri_elem = ((gt%md)+md)%md;
	this->_elem_dxung = md - gt;
	this->_elem_ndao = (((Tim_U_V_int(md, gt)._v_int) % md) + md) % md;
	if (gt == 0) {
		this->_bac_of_elem = -17;
		this->_elem_dxung = -17;
	}
	else
	{
		this->_bac_of_elem = getBacElem(gt, md);
	}

}

inline ELEMENTOFPOLE<int> ELEMENTOFPOLE<int>::operator()(const int &_md, const int &_gt)
{
	ELEMENTOFPOLE<int> newq(_md, _gt);
	*this = newq;
	return *this;
}







inline ELEMENTOFPOLE<int>::ELEMENTOFPOLE() {};
inline ELEMENTOFPOLE<int> ELEMENTOFPOLE<int>::operator[](const int&b) const
{
	if (*this == 0) {
		if (b == 0) return ELEMENTOFPOLE<int>(this->_modul, 0);
		else {
			cout << "ERROR!! vo nghiem!! .\n"; system("pause"); exit(-1);
		}
	}
	if (b == 0) return ELEMENTOFPOLE<int>(this->_modul, 0);
	getU_V get_u_v;
	int gia_tri = this->_gia_tri_elem;
	get_u_v = Tim_U_V_int(gia_tri, this->_modul);
	ELEMENTOFPOLE<int> res(this->_modul, b*get_u_v._u_int);
	return res;
}
inline ELEMENTOFPOLE<int> operator/(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2) {
	if (el_2 == 0) {
		cout << "ERROR!! khong chia duoc cho 0.\n"; system("pause"); exit(-1);
	}
	if (el_1 == 0) return ELEMENTOFPOLE<int>(el_1._modul, 0);
	return el_2[el_1._gia_tri_elem];
}
inline ELEMENTOFPOLE<int> operator+(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2) {
	if (el_1._modul != el_2._modul) {
		cout << "ERROR 2 elem khac modul.\n";
		system("pause"); exit(1);
	}
	int sum = (el_1._gia_tri_elem + el_2._gia_tri_elem) % el_1._modul;
	ELEMENTOFPOLE<int> res(el_1._modul, sum);
	return res;
}
inline ELEMENTOFPOLE<int> operator-(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2) {
	if (el_1._modul != el_2._modul) {
		cout << "ERROR 2 elem khac modul.\n";
		system("pause"); exit(1);
	}
	int sum = (((el_1._gia_tri_elem - el_2._gia_tri_elem) % el_1._modul) + el_1._modul) % el_1._modul;
	ELEMENTOFPOLE<int> res(el_1._modul, sum);
	return res;
}
inline ELEMENTOFPOLE<int> operator*(const ELEMENTOFPOLE<int>&el_1, const ELEMENTOFPOLE<int>&el_2) {
	if (el_1._modul != el_2._modul) {
		cout << "ERROR!! khac modul.\n";
		system("pause"); exit(-1);
	}
	int _tich = (el_1._gia_tri_elem*el_2._gia_tri_elem) % el_1._modul;
	ELEMENTOFPOLE<int> res(el_1._modul, _tich);
	return res;
}
inline bool operator==(const ELEMENTOFPOLE<int>& el_1, const ELEMENTOFPOLE<int>& el_2) {
	if (el_1._modul != el_2._modul) {
		cout << "ERRROR!! khac modul.\n"; exit(-1);
	}
	return el_1._gia_tri_elem == el_2._gia_tri_elem;
}
inline bool operator!=(const ELEMENTOFPOLE<int>& el_1, const ELEMENTOFPOLE<int>& el_2) {
	if (el_1._modul != el_2._modul) {
		cout << "ERRROR!! khac modul.\n"; exit(-1);
	}
	return el_1._gia_tri_elem != el_2._gia_tri_elem;
}
inline bool operator==(const ELEMENTOFPOLE<int>&el, const int&a) {
	ELEMENTOFPOLE<int> ss(el._modul, a);
	return ss == el;
}
inline bool operator!=(const ELEMENTOFPOLE<int>&el, const int&a) {
	ELEMENTOFPOLE<int> ss(el._modul, a);
	return ss != el;
}
inline ostream & operator<<(ostream&out, const ELEMENTOFPOLE<int>& el) {
	out << el._gia_tri_elem;
	return out;
}
inline istream & operator>>(istream&in, ELEMENTOFPOLE<int>& el) {
	cout << "nhap md elem: ";
	int gtri, md;
	in >> md;
	cout << "nhap gia tri elem: ";
	in >> gtri;
	el(md, gtri);
	return in;
}


inline vector<ELEMENTOFPOLE<int> > operator+(const vector<ELEMENTOFPOLE<int> >& v_1, const vector<ELEMENTOFPOLE<int> >&v_2) {
	if (v_1.size() >= v_2.size()) {
		vector<ELEMENTOFPOLE<int> > res = v_1;
		loop(i, 0, (signed)v_2.size()) {
			res[i] = res[i] + v_2[i];
		}
		ELEMENTOFPOLE<int> nul(v_1[0]._modul, 0);
		while (!res.empty() && res.back() == nul)
		{
			res.pop_back();
		}
		return res;
	}
	else {
		vector<ELEMENTOFPOLE<int> > res = v_2;
		loop(i, 0, (signed)v_1.size()) {
			res[i] = res[i] + v_1[i];
		}
		ELEMENTOFPOLE<int> nul(v_1[0]._modul, 0);
		while (!res.empty() && res.back() == nul)
		{
			res.pop_back();
		}
		return res;
	}
}
inline vector<ELEMENTOFPOLE<int> > operator*(const vector<ELEMENTOFPOLE<int> >& v_1, const ELEMENTOFPOLE<int>&el) {
	vector<ELEMENTOFPOLE<int> >res = v_1;
	if (v_1.empty()) return v_1;
	if (v_1[0]._modul != el._modul) {
		cout << "vector va el khac modul!!"; system("pause"); exit(-17);
	}
	loop(i, 0, (signed)v_1.size()) {
		res[i] = res[i] * el;
	}
	ELEMENTOFPOLE<int> nul(v_1[0]._modul, 0);
	while (!res.empty() && res.back() == nul)
	{
		res.pop_back();
	}
	return res;
}
inline vector<ELEMENTOFPOLE<int> > operator-(const vector<ELEMENTOFPOLE<int> >& v_1, const vector<ELEMENTOFPOLE<int> >&v_2) {
	if (v_1.size() >= v_2.size()) {
		vector<ELEMENTOFPOLE<int> > res = v_1;
		loop(i, 0, (signed)v_2.size()) {
			res[i] = res[i] - v_2[i];
		}
		ELEMENTOFPOLE<int> nul(v_1[0]._modul, 0);
		while (!res.empty() && res.back() == nul)
		{
			res.pop_back();
		}
		return res;
	}
	else {
		vector<ELEMENTOFPOLE<int> > res = v_2;
		loop(i, 0, (signed)v_1.size()) {
			res[i] = res[i] - v_1[i];
		}
		ELEMENTOFPOLE<int> nul(v_1[0]._modul, 0);
		while (!res.empty() && res.back() == nul)
		{
			res.pop_back();
		}
		ELEMENTOFPOLE<int> nghich(v_1[0]._modul, v_1[0]._modul - 1);
		res = res * nghich;
		return res;
	}
}