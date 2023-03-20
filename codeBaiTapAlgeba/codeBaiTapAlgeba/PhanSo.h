#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class PhanSo
{
public:
	PhanSo();
	PhanSo(int, int);
	PhanSo(int);
	int _tu_so;
	int _mau_so;
	friend PhanSo operator*(const PhanSo&ps, const int&x) {
		return PhanSo(ps._tu_so*x, ps._mau_so);
	}
	friend PhanSo operator+(const PhanSo& p1, const PhanSo& p2) {
		return PhanSo(p1._tu_so*p2._mau_so + p1._mau_so*p2._tu_so, p1._mau_so*p2._mau_so);
	}
	friend PhanSo operator-(const PhanSo& p1, const PhanSo& p2) {
		return p1 + (p2 * (-1));
	}
	friend PhanSo operator*(const PhanSo&p1, const PhanSo&p2) {
		return PhanSo(p1._tu_so*p2._tu_so, p1._mau_so*p2._mau_so);
	}
	friend PhanSo operator/(const PhanSo&p1, const PhanSo&p2) {
		return PhanSo(p1._tu_so*p2._mau_so, p1._mau_so*p2._tu_so);
	}
	friend ostream& operator<<(ostream&out, const PhanSo &ps) {
		if (ps._tu_so == 0) out << 0;
		else {
			if (ps._mau_so == 1) out << ps._tu_so;
			else out << ps._tu_so << '/' << ps._mau_so;
		}
		return out;
	}
	// nhap phan so theo dnag a b.
	friend istream& operator>>(istream&in, PhanSo &ps) {
		int ts, ms;
		in >> ts >> ms;
		ps = PhanSo(ts, ms);
		return in;
	}
	bool operator==(const PhanSo&ps) const {
		return (_tu_so == ps._tu_so&&_mau_so == ps._mau_so);
	}
	bool operator!=(const PhanSo&ps) const {
		return !(*this == ps);
	}
	bool operator==(const int&stn) const {
		return (_mau_so == 1 && _tu_so == stn);
	}
	bool operator!=(const int&stn) const {
		return !(*this == stn);
	}
	bool operator>(const int&stn) const {
		return (_tu_so > _mau_so*stn);
	}
	bool operator<(const int&stn) const {
		return (_tu_so < _mau_so*stn);
	}
	bool operator>=(const int&stn) const {
		return (*this > stn||*this==stn);
	}
	bool operator<=(const int&stn) const {
		return (*this < stn || *this == stn);
	}
private:

};
static int Ucln(int, int);
static int bcnn(int, int);