#pragma once
#include "PhanSo.h"


static int Ucln(int, int);
static int bcnn(int, int);
class soPhuc
{
public:
	soPhuc();
	soPhuc(double, double);
	double PhanTHuc;
	double PhanAo;
	soPhuc operator+(const soPhuc&) const;
	soPhuc operator-(const soPhuc&) const;
	soPhuc operator*(const soPhuc&) const;
	soPhuc operator/(const soPhuc&) const;
	bool operator==(const soPhuc&) const;
	bool operator!=(const soPhuc&) const;
	friend ostream& operator<<(ostream &out, const soPhuc &);
	friend istream& operator>>(istream &in, soPhuc &);
};
vector<vector<soPhuc> > KhoiTao();
//double
double operator*(const vector<double> &, const vector<double> &);
vector<double> operator*(const vector<double> &, const double &);
vector<vector<double>> KhoiOrt(const vector<vector<double>> &);
vector<double> operator-(const vector<double> &, const vector<double>&);
vector<double> operator+(const vector<double> &, const vector<double>&);
// phanso

PhanSo operator*(const vector<PhanSo> &, const vector<PhanSo> &);
vector<PhanSo> operator*(const vector<PhanSo> &, const PhanSo &);
vector<vector<PhanSo>> KhoiOrt(const vector<vector<PhanSo>> &);
vector<PhanSo> operator-(const vector<PhanSo> &, const vector<PhanSo>&);
vector<PhanSo> operator+(const vector<PhanSo> &, const vector<PhanSo>&);

//so phuc
soPhuc operator*(const vector<soPhuc> &, const vector<soPhuc> &);
vector<soPhuc> operator*(const vector<soPhuc> &, const soPhuc &);
vector<vector<soPhuc>> KhoiOrt(const vector<vector<soPhuc>> &);
vector<soPhuc> operator-(const vector<soPhuc> &, const vector<soPhuc>&);
vector<soPhuc> operator+(const vector<soPhuc> &, const vector<soPhuc>&);



pair<vector<PhanSo>, vector<PhanSo>> TimHinhChieu(const vector<vector<PhanSo> >&vec, const vector<PhanSo>&vec_x);