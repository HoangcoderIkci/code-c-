#include "POLE.h"


ostream& operator<<(ostream &out, const ELEMENT_PLE&el) {
	out << el.elemt;
	return out;
}
istream& operator>>(istream & in, ELEMENT_PLE& el) {
		cout << "nhap modul element(neu khong co nhap 0):  ";
		in >>el.modul_el;
		cout << "nhap gia tri element:  "; in >> el.elemt;
		el.elemt %= el.modul_el;
		el(el.elemt, el.modul_el);
		return in;
}

ELEMENT_PLE::ELEMENT_PLE() {};

ELEMENT_PLE::ELEMENT_PLE(int gtri, int m)
{
	this->elemt = gtri;
	this->modul_el = m;
	this->elemt_phan_dien = m - elemt;
	if (gtri==0) this->oprat = -17;
	else {
		loop(i, 1, m) {
			if ((i*elemt) % m == 1) {
				this->oprat = i; break;
			}
		}
	}
	
}
ELEMENT_PLE ELEMENT_PLE::operator+(const ELEMENT_PLE &el_2)
{
	if (this->modul_el != el_2.modul_el) {
		cout << "ERROR!! khong cong dc khac modul \n"; system("pause"); exit(1);
	}
	if (this->modul_el == -17 || el_2.modul_el == -17) {
		cout << "ERROR!! khong cong dc vi chua khoi tao modul \n"; system("pause"); exit(1);
	}
	int r = this->elemt + el_2.elemt;
		r = r%this->modul_el;
		ELEMENT_PLE res(r,this->modul_el);
		return res;

}
ELEMENT_PLE ELEMENT_PLE::operator*(const ELEMENT_PLE &el_2)
{
	if (this->modul_el != el_2.modul_el || this->modul_el == -17) {
		cout << "ERROR phep nhan khong thuc hien duoc!!!"; 
		system("pause");
		exit(1);
	}
	if (this->elemt == 0 || el_2.elemt == 0) {
		ELEMENT_PLE res(0, this->modul_el);
		return res;
	}
	int r = (this->elemt*el_2.elemt)%this->modul_el;
	ELEMENT_PLE res(r,this->modul_el);
	return res;
}
ELEMENT_PLE ELEMENT_PLE::operator()(const int & a, const int & m)
{
	ELEMENT_PLE res(a, m);
	*this = res;
	return res;
}
ELEMENT_PLE ELEMENT_PLE::operator-(const ELEMENT_PLE &el_2)
{
	if (this->modul_el != el_2.modul_el) {
		cout << "ERROR!! khong cong dc khac modul \n"; system("pause"); exit(1);
	}
	if (this->modul_el == -17 || el_2.modul_el == -17) {
		cout << "ERROR!! khong cong dc vi chua khoi tao modul \n"; system("pause"); exit(1);
	}
	int r = abs(this->elemt - el_2.elemt);
	r = r%this->modul_el;
	ELEMENT_PLE res(r, this->modul_el);
	return res;
}
POLE::POLE(int md)
{
	this->mdul = md;
	this->ds_phan_tu.resize(md);
	loop(i, 0, md) {
		(ds_phan_tu[i])(i, md);
	}
}




// operator cua pole.
// lay ra elment gia tri i cua pole.
ELEMENT_PLE POLE::operator[](const int &id)
{
	int index = id;
	index %=this->mdul;
	return ds_phan_tu[index];
}
// in ra toan bi phan tu cua pole.
ostream& operator<<(ostream& out, const POLE&pl) {
	loop(i, 0, pl.mdul)
		out << pl.ds_phan_tu[i] << ' ';
	return out;
}
