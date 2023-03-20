#include "SoPhucSinXo.h"


soPhucSinXo::soPhucSinXo()
{
	PhanAo = PhanTHuc = PhanSo(0);
}

soPhucSinXo::soPhucSinXo(PhanSo pt, PhanSo pa) 
	:PhanTHuc(pt),PhanAo(pa){}
// overload cho so phuc:
// Phép nhân hai vector s? ph?c
soPhucSinXo operator*(const vector<soPhucSinXo>& v1, const vector<soPhucSinXo>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	soPhucSinXo sum(0, 0);
	soPhucSinXo temp(0, 0);
	for (size_t i = 0; i < v1.size(); i++) {
		temp.PhanTHuc = v2[i].PhanTHuc;
		temp.PhanAo = v2[i].PhanAo * (-1);
		sum = sum + v1[i] * temp;
	}
	return sum;
}

// Phép nhân m?t vector s? ph?c v?i m?t s? ph?c
vector<soPhucSinXo> operator*(const vector<soPhucSinXo>& v, const soPhucSinXo& s) {
	vector<soPhucSinXo> result;
	for (const auto& elem : v) {
		result.push_back(elem * s);
	}
	return result;
}

// Thu?t toán Gram-Schmidt ?? tính ma tr?n kh?i Ortogonal
vector<vector<soPhucSinXo> > KhoiOrt(const vector<vector<soPhucSinXo> >& array1) {
	int sz = array1.size();
	vector<vector<soPhucSinXo>> array2(sz);
	for (size_t i = 0; i < sz; i++)
	{
		array2[i] = array1[i];
		for (size_t j = 0; j < i; j++)
		{
			//cout << array2[j] * array2[j] << '\n' << array1[i] * array2[j] << '\n';
			array2[i] = array2[i] - array2[j] * ((array1[i] * array2[j]) / (array2[j] * array2[j]));
		}
	}
	return array2;
}

// Phép tr? hai vector s? ph?c
vector<soPhucSinXo> operator-(const vector<soPhucSinXo>& v1, const vector<soPhucSinXo>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	vector<soPhucSinXo> result;
	for (size_t i = 0; i < v1.size(); i++) {
		result.push_back(v1[i] - v2[i]);
	}
	return result;
}

// Phép c?ng hai vector s? ph?c
vector<soPhucSinXo> operator+(const vector<soPhucSinXo>& v1, const vector<soPhucSinXo>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	vector<soPhucSinXo> result;
	for (size_t i = 0; i < v1.size(); i++) {
		result.push_back(v1[i] + v2[i]);
	}
	return result;
}
vector<vector<Complex> > TimMaTranC(vector<vector<Complex>> vec, vector<vector<Complex>> vec_u)  // matran tu he vector b->a
{
	int sz = vec.size();
	int dim = vec[0].size();
	vector<vector<Complex> >res(dim, vector<Complex>(dim));
	vector<Complex>temp(dim);
	Complex edinhi = Complex(PhanSo(1), PhanSo(0));
	for (size_t i = 0; i < dim; i++)
	{
		res[i][i] = edinhi;
	}
	Complex sp;
	vector<Complex> vec_a;
	for (size_t i = 1; i < sz; i++)
	{
		vec_a = vec_u[i];
		for (size_t j = 0; j < i; j++)
		{
			sp = (vec_a * vec[j]) / (vec[j] * vec[j]);
			res[j][i] = sp;
		}
	}
	return res;
}
vector<Complex> TimToaDoVector_trongORT(vector<vector<Complex> >v_basic, vector<Complex> vec) {
	int sz = v_basic.size();
	int dim = vec.size();
	if (v_basic[0].size() != dim) {
		cout << "error!! \n";
		system("pause"); exit(-1);
	}
	vector<Complex>res;
	Complex temp;
	vector<Complex> sp;
	for (size_t i = 0; i < sz; i++)
	{
		sp = v_basic[i];
		temp = (vec*sp) / (sp * sp);
		res.push_back(temp);
	}
	return res;
}