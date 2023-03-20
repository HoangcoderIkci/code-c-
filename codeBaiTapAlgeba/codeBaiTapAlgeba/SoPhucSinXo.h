#pragma once
#include"Header.h"
#include"PhanSo.h"
#define  Complex soPhucSinXo
class soPhucSinXo
{
public:
	soPhucSinXo();
	soPhucSinXo(PhanSo, PhanSo);
	PhanSo PhanTHuc;
	PhanSo PhanAo;
	soPhucSinXo operator+(const soPhucSinXo&clex) const {
		return soPhucSinXo(PhanTHuc + clex.PhanTHuc, PhanAo + clex.PhanAo);
	}
	soPhucSinXo operator-(const soPhucSinXo&clex) const {
		return soPhucSinXo(PhanTHuc - clex.PhanTHuc, PhanAo - clex.PhanAo);
	}
	soPhucSinXo operator*(const soPhucSinXo&other) const {
		soPhucSinXo result;
		result.PhanTHuc = PhanTHuc * other.PhanTHuc - PhanAo * other.PhanAo;
		result.PhanAo = PhanTHuc * other.PhanAo + PhanAo * other.PhanTHuc;
		return result;
	}
	soPhucSinXo operator/(const soPhucSinXo&other) const {
		soPhucSinXo result;
		PhanSo denominator = other.PhanTHuc * other.PhanTHuc + other.PhanAo * other.PhanAo;
		result.PhanTHuc = (PhanTHuc * other.PhanTHuc + PhanAo * other.PhanAo) / denominator;
		result.PhanAo = (PhanAo * other.PhanTHuc - PhanTHuc * other.PhanAo) / denominator;
		return result;
	}
	bool operator==(const soPhucSinXo&other) const {
		return PhanTHuc == other.PhanTHuc && PhanAo == other.PhanAo;
	}

	bool operator!=(const soPhucSinXo&other) const {
		return !(*this == other);
	}
	friend ostream& operator<<(ostream &out, const soPhucSinXo &s)
	{
		out << s.PhanTHuc << (s.PhanAo >= 0 ? "+" : "") << s.PhanAo << "i";
		return out;
	}
	friend istream& operator>>(istream &in, soPhucSinXo &s) {
		cout << "nhap phan thuc: "; in >> s.PhanTHuc;
		cout << "nhap phan ao: "; in >> s.PhanAo;
		return in;
	}
	//friend ostream& operator<<(ostream &out, const soPhucSinXo &);
	//friend istream& operator>>(istream &in, soPhucSinXo &);
};
soPhucSinXo operator*(const vector<soPhucSinXo> &, const vector<soPhucSinXo> &);
vector<soPhucSinXo> operator*(const vector<soPhucSinXo> &, const soPhucSinXo &);
vector<vector<soPhucSinXo>> KhoiOrt(const vector<vector<soPhucSinXo>> &);
vector<soPhucSinXo> operator-(const vector<soPhucSinXo> &, const vector<soPhucSinXo>&);
vector<soPhucSinXo> operator+(const vector<soPhucSinXo> &, const vector<soPhucSinXo>&);
vector<vector<Complex> > TimMaTranC(vector<vector<Complex>> vec, vector<vector<Complex>> vec_u);
vector<Complex> TimToaDoVector_trongORT(vector<vector<Complex> >v_basic, vector<Complex> vec);