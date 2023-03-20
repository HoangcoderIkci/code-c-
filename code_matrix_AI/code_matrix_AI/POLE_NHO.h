#pragma once
#include "Header.h"
#include "myFunction.h"
#include "myDaThuc.h"
template<class T>
class ELEM_POLE_NHO
{
public:
	T gia_tri_ptu;
	T phan_tu_nghich_dao;
	T Phan_tu_trai_nguoc;
	int bac_of_phan_tu_trong_sum;
	int bac_of_phan_tu_trong_tich;
	ELEM_POLE_NHO();
	ELEM_POLE_NHO(const int& gtri);
	ELEM_POLE_NHO KhoiTaoElem_1(const int&,const int&);

};


template<class T>
inline ELEM_POLE_NHO<T>::ELEM_POLE_NHO()
{
}

template<class T>
inline ELEM_POLE_NHO ELEM_POLE_NHO<T>::KhoiTaoElem_1(const int & gtr, const int & md)
{
	this->gia_tri_ptu = gtr;
	this->bac_of_phan_tu_trong_sum
}

template<class T>
inline ELEM_POLE_NHO<T>::ELEM_POLE_NHO(const T & gtri)
{
	this->gia_tri_ptu = gtri;
}

template<class T>
class POLE_NHO
{
public:
	POLE_NHO(const int&);
	POLE_NHO(const int&, const myDaThuc<ELEM_POLE_NHO>&);
	vector<T> ds_ptu_pole;
	int so_luong_ptu_pole;
	int exp_multi_gp;
	T edinhit;
	T null_pole;
	T elem_dang_cuu_the;
};

template<class T>

template<class T>
inline POLE_NHO<T>::POLE_NHO(const int &gia_tri)
{
	this->so_luong_ptu_pole = gia_tri;
	this->edinhit = 1;
	this->null_pole = 0;
	this->exp_multi_gp = gia_tri - 1;
	this->ds_ptu_pole.resize(gia_tri);
	loop(i, 0, gia_tri) {
		this->ds_ptu_pole[i] = i;
		this->
	}
		
}

template<class T>
inline POLE_NHO<T>::POLE_NHO(const int &, const myDaThuc<ELEM_POLE_NHO>&)
{
}
