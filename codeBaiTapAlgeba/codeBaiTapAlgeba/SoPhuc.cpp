#include "SoPhuc.h"
#include "SoPhucSinXo.h"


double operator*(const vector<double> &v1, const vector<double> &v2)
{
	int sz = v1.size();
	double res;
	if (v2.size() != sz)
		return -999;
	res = 0;
	for (size_t i = 0; i < sz; i++)
	{
		res += v1[i] * v2[i];
	}
	return res;
}
vector<double> operator*(const vector<double> &v1, const double &x)
{
	int sz = v1.size();
	vector<double> res(sz);
	for (size_t i = 0; i < sz; i++)
	{
		res[i] = v1[i] * x;
	}
	return res;
}
vector<vector<double>> KhoiOrt(const vector<vector<double>> &array1)
{
	double mauChung=1;
	double temp;
	int sz = array1.size();
	vector<vector<double>> array2(sz);
	for (size_t i = 0; i < sz; i++)
	{
		array2[i] = array1[i];
		mauChung = 1;
		for (size_t j = 0; j < i; j++)
		{
			temp = array2[j] * array2[j];
			mauChung = bcnn(mauChung, temp);
			array2[i] = array2[i] - array2[j] * ((array1[i] * array2[j]) / temp);
			array2[i] = array2[i] * mauChung;
		}
	}
	return array2;
}
vector<double> operator-(const vector<double> &v1, const vector<double> &v2) {
	int sz = v1.size();
	if (sz != v2.size())
		exit(-1);
	vector<double> rs(sz);
	for (size_t i = 0; i < sz; i++)
	{
		rs[i] = v1[i] - v2[i];
	}
	return rs;
}
vector<double> operator+(const vector<double> &v1, const vector<double> &v2)
{
	int sz = v1.size();
	if (sz != v2.size())
		exit(-1);
	vector<double> rs(sz);
	for (size_t i = 0; i < sz; i++)
	{
		rs[i] = v1[i] + v2[i];
	}
	return rs;
}


soPhuc::soPhuc()
{
	PhanTHuc = 0;
	PhanAo = 0;
}



soPhuc::soPhuc(double thuc, double ao)
{
	PhanTHuc = thuc;
	PhanAo = ao;
}

soPhuc soPhuc::operator+(const soPhuc& other) const {
	soPhuc result;
	result.PhanTHuc = PhanTHuc + other.PhanTHuc;
	result.PhanAo = PhanAo + other.PhanAo;
	return result;
}

soPhuc soPhuc::operator-(const soPhuc& other) const {
	soPhuc result;
	result.PhanTHuc = PhanTHuc - other.PhanTHuc;
	result.PhanAo = PhanAo - other.PhanAo;
	return result;
}

soPhuc soPhuc::operator*(const soPhuc& other) const {
	soPhuc result;
	result.PhanTHuc = PhanTHuc * other.PhanTHuc - PhanAo * other.PhanAo;
	result.PhanAo = PhanTHuc * other.PhanAo + PhanAo * other.PhanTHuc;
	return result;
}

soPhuc soPhuc::operator/(const soPhuc& other) const {
	soPhuc result;
	double denominator = other.PhanTHuc * other.PhanTHuc + other.PhanAo * other.PhanAo;
	result.PhanTHuc = (PhanTHuc * other.PhanTHuc + PhanAo * other.PhanAo) / denominator;
	result.PhanAo = (PhanAo * other.PhanTHuc - PhanTHuc * other.PhanAo) / denominator;
	return result;
}

bool soPhuc::operator==(const soPhuc& other) const {
	return PhanTHuc == other.PhanTHuc && PhanAo == other.PhanAo;
}

bool soPhuc::operator!=(const soPhuc& other) const {
	return !(*this == other);
}

ostream& operator<<(ostream &out, const soPhuc &s)
{
	out << s.PhanTHuc << (s.PhanAo >= 0 ? "+" : "") << s.PhanAo << "i";
	return out;
}
istream& operator>>(istream &in, soPhuc &s) {
	cout << "nhap phan thuc: "; in >> s.PhanTHuc;
	cout << "nhap phan ao: "; in >> s.PhanAo;
	return in;
}



// overload cho so phuc:
// Phép nhân hai vector s? ph?c
soPhuc operator*(const vector<soPhuc>& v1, const vector<soPhuc>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	soPhuc sum(0, 0);
	soPhuc temp(0, 0);
	for (size_t i = 0; i < v1.size(); i++) {
		temp.PhanTHuc = v2[i].PhanTHuc;
		temp.PhanAo = -v2[i].PhanAo;
		sum = sum + v1[i] * temp;
	}
	return sum;
}

// Phép nhân m?t vector s? ph?c v?i m?t s? ph?c
vector<soPhuc> operator*(const vector<soPhuc>& v, const soPhuc& s) {
	vector<soPhuc> result;
	for (const auto& elem : v) {
		result.push_back(elem * s);
	}
	return result;
}

// Thu?t toán Gram-Schmidt ?? tính ma tr?n kh?i Ortogonal
vector<vector<soPhuc> > KhoiOrt(const vector<vector<soPhuc> >& array1) {
	int sz = array1.size();
	vector<vector<soPhuc>> array2(sz);
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
vector<soPhuc> operator-(const vector<soPhuc>& v1, const vector<soPhuc>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	vector<soPhuc> result;
	for (size_t i = 0; i < v1.size(); i++) {
		result.push_back(v1[i] - v2[i]);
	}
	return result;
}

// Phép c?ng hai vector s? ph?c
vector<soPhuc> operator+(const vector<soPhuc>& v1, const vector<soPhuc>& v2) {
	if (v1.size() != v2.size()) {
		// x? lý tr??ng h?p ?? dài khác nhau
		// ? ?ây, tôi s? ném ra ngo?i l?
		throw std::invalid_argument("Two vectors must have the same size.");
	}
	vector<soPhuc> result;
	for (size_t i = 0; i < v1.size(); i++) {
		result.push_back(v1[i] + v2[i]);
	}
	return result;
}
vector<vector<soPhuc> > KhoiTao(){
	int n,sz; soPhuc temp;
	cout << "nhap so luong vector: "; cin >> n;
	vector<vector<soPhuc> > res(n);
	
	cout << "nhap kich thuoc kich thuoc moi vector: "; cin >> sz;
	for (size_t i = 0; i < n; i++)
	{
		cout << "khoi tao vector[" << (i + 1) << "] \n";
		for (size_t j = 0; j < sz; j++)
		{
			printf("vector[%i] :", i); cin >> temp;
			res[i].push_back(temp);
		}
	}
	return res;
}
static int Ucln(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0) return abs(b);
	else if (b == 0) return abs(a);
	else {
		int temp;
		while (b)
		{
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}

}
static int bcnn(int a, int b) {
	if (a == 0 || b == 0) return 0;
	a = abs(a); b = abs(b);
	return (a*b) / Ucln(a, b);
}


// phanso
PhanSo operator*(const vector<PhanSo> &v1, const vector<PhanSo> &v2)
{
	int sz = v1.size();
	PhanSo res;
	if (v2.size() != sz)
		return -999;
	res = 0;
	for (size_t i = 0; i < sz; i++)
	{
		res = res + v1[i] * v2[i];
	}
	return res;
}
vector<PhanSo> operator*(const vector<PhanSo> &v1, const PhanSo &x)
{
	int sz = v1.size();
	vector<PhanSo> res(sz);
	for (size_t i = 0; i < sz; i++)
	{
		res[i] = v1[i] * x;
	}
	return res;
}
vector<vector<PhanSo>> KhoiOrt(const vector<vector<PhanSo>> &array1)
{
	int sz = array1.size();
	vector<vector<PhanSo>> array2(sz);
	for (size_t i = 0; i < sz; i++)
	{
		array2[i] = array1[i];
		for (size_t j = 0; j < i; j++)
		{
			array2[i] = array2[i] - array2[j] * ((array1[i] * array2[j]) / (array2[j] * array2[j]));
		}
	}
	return array2;
}
vector<PhanSo> operator-(const vector<PhanSo> &v1, const vector<PhanSo> &v2) {
	int sz = v1.size();
	if (sz != v2.size())
		exit(-1);
	vector<PhanSo> rs(sz);
	for (size_t i = 0; i < sz; i++)
	{
		rs[i] = v1[i] - v2[i];
	}
	return rs;
}
vector<PhanSo> operator+(const vector<PhanSo> &v1, const vector<PhanSo> &v2)
{
	int sz = v1.size();
	if (sz != v2.size())
		exit(-1);
	vector<PhanSo> rs(sz);
	for (size_t i = 0; i < sz; i++)
	{
		rs[i] = v1[i] + v2[i];
	}
	return rs;
}

//timhc

pair<vector<PhanSo>, vector<PhanSo>> TimHinhChieu(const vector<vector<PhanSo> >&vec, const vector<PhanSo>&vec_x) {
	int dimK; cout << "nhap dim K: "; cin >> dimK;
	int sz = vec.size();
	int szVec = vec_x.size();
	vector<PhanSo> v1(szVec);
	//vector<PhanSo> v2(szVec);
	PhanSo temp;
	int i;
	for (i = 0; i < dimK; i++)
	{
		temp = vec[i] * vec[i];
		v1 = v1 + vec[i] * ((vec_x*vec[i]) / (temp));
	}
	/*for (i; i < sz; i++)
	{
	temp = vec[i] * vec[i];
	v2 = v2 + vec[i] * ((vec_x*vec[i]) / (temp));
	}*/
	return pair<vector<PhanSo>, vector<PhanSo>>(v1, (vec_x - v1));
}