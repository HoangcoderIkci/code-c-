#include "myLibrary.h"

bool operator!=(const Dathuc&dt1, const Dathuc&dt2) {
	if (dt1.bac_dathuc != dt2.bac_dathuc) return false;
	if (dt1.ds_heso != dt2.ds_heso)
		return false;
	return true;
}
bool operator==(const Dathuc&dt1, const Dathuc&dt2) {
	if (dt1.bac_dathuc != dt2.bac_dathuc) return false;
	if (dt1.ds_heso != dt2.ds_heso)
		return false;
	return true;
}
/*
bool operator==(const vector<Dathuc> &v_1, const vector<Dathuc> &v_2) {
	if (v_1.size() == v_2.size() && v_1.empty()) return true;
	if (v_2.size() != v_1.size()) return false;
	loop(i, 0, v_1.size())
		if (v_1[i] != v_2[i]) return false;
	return true;
	
}*/
Dathuc operator+(const Dathuc &dt, const int&a) {
	vector<int>vec = dt.ds_heso;
	vec[0] = vec[0] + a;
	Dathuc res(vec);
	return res;
}
Dathuc operator+(const int&a, const Dathuc &dt) {
	vector<int>vec = dt.ds_heso;
	vec[0] = vec[0] + a;
	Dathuc res(vec);
	return res;
}
Dathuc operator*(const int &a, const Dathuc &dt) {
	vector<int> v_r = dt.ds_heso;
	v_r = v_r * a;
	Dathuc res(v_r);
	return res;
}
Dathuc operator+(const Dathuc &a,const Dathuc &b) {
	Dathuc dathuc_phu=a;
	dathuc_phu.ds_heso = dathuc_phu.ds_heso + b.ds_heso;
	Dathuc res{ dathuc_phu.ds_heso };
	return res;
}
Dathuc operator-(const Dathuc &a, const Dathuc &b) {
	Dathuc dathuc_phu = a;
	dathuc_phu.ds_heso = dathuc_phu.ds_heso - b.ds_heso;
	Dathuc res{ dathuc_phu.ds_heso };
	return res;
}
Dathuc operator*(const Dathuc &a, const Dathuc &b) {
	vector<int> vec_res(1,0);
	vector<int> vec_1(1, 0);
	vector<int> vec_2=a.ds_heso;
	vector<int> vec_3=b.ds_heso;
	loop(i, 0, vec_2.size()) {
		vec_1 = vec_3 * vec_2[i];
		vec_1 = vec_1 >> i;
		vec_res = vec_res + vec_1;
	}
	Dathuc resul(vec_res);
	return resul;
}
vector<int> operator>>(const vector<int>& vec_a, const int &x) {
	vector<int> vec_res(x, 0);
	pushpackvectorTovt(vec_res, vec_a);
	return vec_res;
}
Dathuc operator*(const Dathuc &dt, const int &a) {
	vector<int> v_r = dt.ds_heso;
	v_r = v_r * a;
	Dathuc res(v_r);
	return res;
}
vector<int> operator+(const vector<int>&a, const vector<int>&b) {
	vector<int >res;
	if (a.size() < b.size()) {
		res = b;
		loop(i, 0, a.size())
			res[i] += a[i];
	} 
	else {
		res = a;
		loop(i, 0, b.size())
			res[i] += b[i];
	}
	return res;
}
vector<int> operator-(const vector<int>&a, const vector<int>&b) {
	vector<int >res;
	if (a.size() < b.size()) {
		res = b;
		loop(i, 0, a.size())
			res[i] -= a[i];
		res = res*(-1);
	}
	else {
		res = a;
		loop(i, 0, b.size())
			res[i] -= b[i];
	}
	
	return res;
}
vector<int> operator*(vector<int>a, int x) {
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] *= x;
	}
	return a;
}
bool operator==(const vector<vector<int> >&a, const int x) {
	bool is_true = false;
	loop(i, 0, a.size())
		if (!(a[i] == x)) return false;
	return true;
}
bool operator==(const vector<int>&a, int i) {
	for (auto x : a) if (!x == i) return false;
	return true;
};
vector<int> operator%(vector<int>a,int modul) {
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] %= modul;
	}
	return a;
}
vector<int> operator/(vector<int>a, int x) {
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] /= x;
	}
	return a;
}
vector<vector<int> > operator*(const vector<vector<int> >&a, const vector<vector<int> >&b) {
	vector<vector<int> >v_a = a;
	vector<vector<int> >v_b = b;
	int m = a.size();
	int n = b.size();
	int k = b[0].size();
	vector<vector<int> > res(m, vector<int>(k, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i] = res[i] + (b[j] * a[i][j]);
		}
	}
	return res;
};
vector<vector<int> > operator+(const vector<vector<int> >&a, const vector<vector<int> >&b) {
	vector<vector<int> >v_a = a;
	vector<vector<int> >v_b = b;
	int m = a.size();
	int n = b[0].size();
	vector<vector<int> > res(m, vector<int>(n, 0));
	loop(i, 0, m) res[i] = v_a[i] + v_b[i];
	return res;
};
vector<vector<int> > operator-(const vector<vector<int> >&a, const vector<vector<int> >&b) {
	vector<vector<int> >v_a = a;
	vector<vector<int> >v_b = b;
	int m = a.size();
	int n = b[0].size();
	vector<vector<int> > res(m, vector<int>(n, 0));
	loop(i, 0, m) res[i] = v_a[i] - v_b[i];
	return res;
};
vector<int> operator*(const vector<vector<int> >&a, const vector<int>&b) {
	vector<int> res(a.size(), 0);
	loop(i, 0, a.size()) {
		loop(j, 0, b.size()) {
			res[i] = res[i] + a[i][j] * b[j];
		}
	}
	return res;
}
vector<vector<int> > operator%(const vector<vector<int> >&a, int modul) {
	vector<vector<int> >mtr = a;
	loop(i, 0, mtr.size()) {
		mtr[i] = mtr[i] % modul;
	}
	return mtr;
}
int getMin(size_t a, size_t b) {
	return (a < b) ? a : b;
}




			
void tinhBacCuaHam(int n, int m, bool *a) {
	a[n] = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	for (int i = n; i >= m; i--)
	{
		if (a[i]) {
			a[i] = 0;
			(a[i - 2]) ? a[i - 2] = false : a[i - 2] = true;
			(a[i - 3]) ? a[i - 3] = false : a[i - 3] = true;
			(a[i - 7]) ? a[i - 7] = false : a[i - 7] = true;
			(a[i - 8]) ? a[i - 8] = false : a[i - 8] = true;

		}

	}
	for (int i = 0; i <= m; i++)
	{
		cout << a[i] << '\n';
	}
};
void tinhBacCuaHam(int n, int m, int *a, int modul) {
	a[n] = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	for (int i = n; i >= m; i--)
	{
		if (a[i] == 1) {
			a[i] = 0;
			a[i - 2] = (a[i - 2] + 2) % modul;
			/*a[i - 3] = (a[i - 3] + 2) % modul;
			a[i - 5] = (a[i - 5] + 1) % modul;
			a[i - 6] = (a[i - 6] + 2) % modul;*/
		}
		if (a[i] == 2) {
			a[i] = 0;
			a[i - 2] = (a[i - 2] + 1) % modul;
		}

	}
	for (int i = 0; i <= m; i++)
	{
		cout << a[i] << '\n';
	}
};
int sangSoNguyenTo(int n) {
	int s = 0;
	map<int, bool>m;
	loop(i, 2, n + 1) {
		m.insert({ i, true });
	}
	for (int i = 2; i*i <= n; i++) {
		if (m[i])
			for (int j = i; i*j <= n; j++)
			{
				m.erase(i*j);
			}
	}
	for (auto x = m.begin(); x != m.end(); x++)
	{
		s += x->first;
	}
	return s;
}




void writeToFile(FILE *f) {
	char *ch = new char[255];
	cout << "enter data to from to file: ";
	fgets(ch, 255, stdin);
	fputs(ch, f);
	delete[]ch;
};
string readFromfile(FILE *f,int size) {
	char *ch = new char[size];
	string str="";
	while (fgets(ch,255,f)!=NULL)
	{
		str = str+ch;
	}
	delete[]ch;
	return str;
}












bool checkColumn(vector<vector<char> >grid) {
	for (size_t i = 0; i < 9; i++)
	{
		vector<bool> b(10, false);
		for (size_t j = 0; j < 9; j++)
		{
			if (grid[i][j] != '.')
				if (b[grid[i][j]])
					return false;
				else
					b[grid[i][j]] = true;
		}
	}
	return true;
}
bool checkRow(vector<vector<char> >grid) {
	for (size_t j = 0; j < 9; j++)
	{
		vector<bool> b(10, false);
		for (size_t i = 0; i < 9; i++)
		{
			if (grid[i][j] != '.')
				if (b[grid[i][j]])
					return false;
				else
					b[grid[i][j]] = true;
		}
	}
	return true;
}
bool checkMatrix(vector<vector<char> >grid) {
	for (size_t k = 0; k < 9; k += 3)
	{
		for (size_t l = 0; l < 9; l += 3)
		{
			for (size_t i = k; i < k + 3; i++)
			{
				vector<bool> b(10, false);
				for (size_t j = l; j < l + 3; j++)
				{
					if (grid[i][j] != '.')
						if (b[grid[i][j]])
							return false;
						else
							b[grid[i][j]] = true;
				}
			}
		}
	}
	return true;
}

vector<vector<int> > swapprow(vector<vector<int> >&vec_a, int i, int j) {
	vector<int> x = vec_a[i];
	vec_a[i] = vec_a[j];
	vec_a[j] = x;
	return vec_a;
}
// tim phan tu dau tien khac 0 va swap.
vector<vector<int> > step_1(vector<vector<int> >&vec_a, int rang, int column) {
	for (size_t j = rang + 1; j < vec_a.size(); j++)
	{
		if (vec_a[j][column] != 0) {
			swapprow(vec_a, rang, j);
			cout << "\n";
			display(vec_a);
			
			break;
		}

	}
	return vec_a;
}
// ap null.
vector<vector<int> > step_2(vector<vector<int> >&vec_a, int i,int rang) {
	int k;
	for (size_t j = rang; j < vec_a.size(); j++)
	{
		k = 0;
		if (vec_a[j][i]) {
			for (size_t m = 1; m < 5; m++)
			{
				if ((m*vec_a[rang-1][i] + vec_a[j][i]) % 5 == 0) {
					k = m; break;
				}
			}
			vec_a[j] = (vec_a[j] + vec_a[rang-1]*k)%5;
			cout << "\n";
			display(vec_a);
		}
		
	}
	return vec_a;
}

vector<vector<int> > step_3(vector<vector<int> >&vec_a, int rang, vector<int> &idbasic) {
	int k;
	rang--;
	sort(idbasic.begin(), idbasic.end(), greater<int>());
	for (auto x : idbasic)
	{
		for (int i = rang - 1; i >= 0; i--)
		{
			if (vec_a[i][x] != 0)
			{
				for (size_t m = 1; m < 5; m++)
				{
					if ((vec_a[rang][x] * m + vec_a[i][x]) % 5 == 0) {
						k = m; break;
					}
				}
				vec_a[i] = (vec_a[i] + vec_a[rang] * k) % 5;
				cout << '\n';
				display(vec_a);

				/*for (size_t j = x; j < vec_a.size(); j++)
				{
					vec_a[i][j] = (vec_a[i][j] + k*vec_a[rang][j]) % 5;
				}*/
			}

		}
		// dua he so ve 1.
		if (vec_a[rang][x] != 1) {
			for (size_t in = 1; in < 5; in++)
			{
				if ((vec_a[rang][x] * in) % 5 == 1) k = in;
			}
			vec_a[rang] = (vec_a[rang] * k) % 5;
			cout << '\n';
			display(vec_a);
			/*for (size_t j = x; j < vec_a.size(); j++)
			{
				vec_a[rang][j] = (vec_a[rang][j] * k) % 5;
			}*/
		}
		rang--;
	}
	return vec_a;
}
maTran xuLyMatrix(vector<vector<int> >&vec_a) {
	vec_a = vec_a % 5;
	int minOfRowAndColumn = getMin(vec_a.size(),vec_a[0].size());
	maTran list_res;
	vector<int> index_basic;
	int rangMt = 0;
	for (size_t i = 0; i < minOfRowAndColumn; i++)
	{
		cout << "luc nay i la: " << i << '\n';
		if (vec_a[rangMt][i] == 0) {
			step_1(vec_a, rangMt, i);
		}
		if (vec_a[rangMt][i]) {
			rangMt++;
			cout << "bien cot "<<i<<" bang 0\n";
			cout << rangMt << '\n';
			// bien cot i = 0
			index_basic.push_back(i);
			step_2(vec_a, i, rangMt);
		}
	}
	cout << "index of basic: ";
	for (auto x : index_basic) { cout << x << ' '; }
	rangMt = index_basic.size();
	list_res.rang = rangMt;
	list_res.index_basic = index_basic;
	cout << "rang mtrix: " << rangMt << '\n';
	// dua ve dang speci.
	step_3(vec_a, rangMt, index_basic);
	return list_res;
}
vector<vector<int> >getMatrix(int row,int column) {
	vector<vector<int> > vec_a(row, vector<int>(column, 0));
	row = 1;
	for (auto &x : vec_a) {
		cout << "enter row " << row << ": \n";
		row++;
		for (auto &y : x) {
			cin >> y;
		}
	}
	return vec_a;
}
// print arr.
void display(vector<vector<int> >&vec_a) {
	size_t row = vec_a.size();
	size_t column = vec_a[0].size();
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
			cout << vec_a[i][j] << '\t';
		cout << '\n';
	}
}
void display(const vector<vector<int> >&vec_a) {
	size_t row = vec_a.size();
	size_t column = vec_a[0].size();
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
			cout << vec_a[i][j] << '\t';
		cout << '\n';
	}
}
vector<vector<int> >pushcolumn(vector<vector<int> >&matrix,const vector<int> &a) {
	size_t s = a.size();
	loop(i, 0, s) {
			matrix[i].push_back(a[i]);
	}
	return matrix;
}
void GetDaThuc_0VecTor(const vector<vector<int> >&vec_a) {
	maTran mt;
	int i_size;
	cout << "enter size of vector: ";
	cin >> i_size;
	cout << "enter vector: ";
	vector<int> bas(i_size, 0);
	loop(i, 0, i_size) cin >> bas[i];
	mt.rang = 1; int dem = 1;
	vector<vector<int> >mangKtra(bas.size(), vector<int>(1, 0));
	vector<vector<int> >arr;
	loop(i, 0, bas.size()) mangKtra[i][0] = bas[i];
	vector<int> x_1 = bas;
	while (dem == mt.rang)
	{
		x_1 = (vec_a*x_1) % 5;
		pushcolumn(mangKtra, x_1);
		arr = mangKtra;
		mt = xuLyMatrix(arr);
		dem++;
	}
	cout << "he so can tim: \n";
	loop(i, 0, mt.rang) {
		cout << "a[" << i << "]= " << (5 - arr[i].back()) % 5 << '\n';
	}
	cout << "a[" << mt.rang << "]= " << 1 << '\n';
}
vector<vector<int> > ChuyenVimtrix(const vector<vector<int> >&mtran) {
	vector<vector<int> >mtr = mtran;
	vector<vector<int> >kqua(mtr[0].size(), (vector<int>(mtr.size(), 0)));
	loop(i, 0, mtr.size())
		loop(j, 0, mtr[0].size())
		kqua[j][i] = mtr[i][j];
	return kqua;
};
void TimkopenLp(const vector<vector<int> >&maTrann) {
	maTran dsOfmt;
	int bacOfmatrix, nghiem_x;
	cout << "enter bacOfmatrix:"; cin >> bacOfmatrix;
	cout << "enter nghiem_x:"; cin >> nghiem_x;
	vector<vector<int> >maTr = maTrann;
	for (size_t i = 0; i < maTr.size(); i++)
	{
		maTr[i][i] = maTr[i][i] - nghiem_x + 5;
	}
	if (bacOfmatrix) {
		vector<vector<int> >mtr = maTr;
		loop(i, 0, bacOfmatrix - 1) maTr = maTr*mtr;
	}
	display(maTr);
	system("pause");
	system("cls");
	dsOfmt=xuLyMatrix(maTr);
	
	vector<vector<int> >mtrRes;
	display(maTr);
};
void pushpackvectorTovt(vector<int> &v_first, const vector<int> &v_last) {
	loop(i, 0, v_last.size())
		v_first.push_back(v_last[i]);
}
vector<vector<int> >TimMtrixNghichNgom(const vector<vector<int> >&maTrix) {
	maTran dsofmt;
	int i_size = maTrix.size();
	vector<vector<int> >matrix_phu = maTrix;
	vector<vector<int> >matrix_NghichDao(i_size,vector<int>(i_size,0));
	if (i_size != maTrix[0].size()) {
		cout << "khong vuong tim bang???!!!\n";
		return matrix_NghichDao;
	}
	vector<int> nul(i_size, 0);
	loop(i, 0, i_size) {
		pushpackvectorTovt(matrix_phu[i], nul);
		matrix_phu[i][i_size + i] = 1;
	}
	dsofmt=xuLyMatrix(matrix_phu);
	if (dsofmt.rang != i_size) {
		cout << "matrix khong nghich ngom:))\n";
		return matrix_NghichDao;
	}
	loop(i, 0, i_size) {
		loop(j,i_size, (2 * i_size)) {
			matrix_NghichDao[i][j - i_size] = matrix_phu[i][j];
		}
	}
	return matrix_NghichDao;
}
int TimRankMatrix(const vector<vector<int> >&maTrix) {
	vector<vector<int> >maTrix_phu = maTrix;
	maTran dsofmt = xuLyMatrix(maTrix_phu);
	return dsofmt.rang;
}
vector<int> TimIndexbasicMatrix(const vector<vector<int> >&maTrix) {
	vector<vector<int> >maTrix_phu = maTrix;
	maTran dsofmt = xuLyMatrix(maTrix_phu);
	return dsofmt.index_basic;
}
Dathuc ChiaDathucTheoModulGet_phan_du(const Dathuc&d_1, const Dathuc&d,Dathuc &thuong, const int& modul) {

	Dathuc dt_bi_chia = d;
	Dathuc dt_chia = d_1;
	if (dt_chia.bac_dathuc < dt_bi_chia.bac_dathuc) {
		cout << "dathuc chia bac nho hon\n";
		return dt_chia;
	}
	vector<int> resul;
	vector<int> v_c = (dt_chia.ds_heso) % modul;
	vector<int> v_bc = (dt_bi_chia.ds_heso) % modul;
	int hs, nghichdao;
	vector<int>v_phu;
	loop(i, 1, modul) {
		if ((i*v_bc.back()) % modul == 1) {
			nghichdao = i;
			break;
		}
	}
	v_bc = (v_bc*nghichdao) % modul;
	int hieu = v_c.size() - v_bc.size();
	while (v_c.size() >= v_bc.size())
	{
		hs = v_c.back();
		resul.push_back(hs);
		v_phu = v_bc >> hieu;
		v_c = v_c - v_phu*hs;
		loop(i, 0, v_c.size()) v_c[i] = v_c[i] + 5 * modul;
		v_c = v_c % modul;
		while ((!v_c.empty())&&v_c.back() == 0) v_c.pop_back();
		hieu = v_c.size() - v_bc.size();
	}
	resul = resul*nghichdao;
	resul = resul % modul;
	vector <int>resss(resul.size(), 0); hs = 0;
	for (int i = resul.size() - 1; i >= 0; i--) {
		resss[hs] = resul[i];
		hs++;
	}
	// neu du 0
	if (v_c.empty()) v_c = { 0 };
	Dathuc kqua(resss);
	thuong = kqua;
	Dathuc phanduu(v_c);
	return phanduu;
}
Dathuc ChiaDathucTheoModul(const Dathuc&d_1, const Dathuc&d, const int& modul) {

	Dathuc dt_bi_chia = d;
	Dathuc dt_chia = d_1;
	if (dt_chia.bac_dathuc < dt_bi_chia.bac_dathuc) {
		cout << "dathuc chia bac nho hon\n";
		return dt_chia;
	}
	vector<int> resul(1,0);
	vector<int> v_c = (dt_chia.ds_heso) % modul;
	vector<int> v_bc = (dt_bi_chia.ds_heso) % modul;
	int hs, nghichdao;
	vector<int>v_phu;
	loop(i, 1, modul) {
		if ((i*v_bc.back()) % modul == 1) {
			nghichdao = i;
			break;
		}
	}
	v_bc = (v_bc*nghichdao) % modul;
	int hieu = v_c.size() - v_bc.size();
	resul = resul >> hieu;
	while (v_c.size() >= v_bc.size())
	{
		hs = v_c.back();
		resul[hieu]=hs;
		v_phu = v_bc >> hieu;
		v_c = v_c - v_phu*hs;
		loop(i, 0, v_c.size()) v_c[i] = v_c[i] + 10 * modul;
		v_c = v_c % modul;
		while ((!v_c.empty())&&v_c.back() == 0) v_c.pop_back();
		hieu = v_c.size() - v_bc.size();
	}
	resul = resul*nghichdao;
	resul = resul % modul;
	/*vector <int>resss(resul.size(), 0); hs = 0;
	for (int i = resul.size() - 1; i >= 0; i--) {
		resss[hs] = resul[i];
		hs++;
	}*/
	if (v_c.empty()) v_c = { 0 };
	Dathuc kqua(resul);
	Dathuc phanduu(v_c);
	return kqua;
}

Dathuc::Dathuc()
{
	bac_dathuc = -1;
	he_so_gia = 0;
	he_so_tre_trau = 0;
	ds_heso = { 0 };
	so_he_so_null = 0;
}



Dathuc::Dathuc(vector<int> vec) {
	while (vec.back() == 0&&vec.size()!=1)
	{
		vec.pop_back();
	}
	if (vec.back() ==0) { 
		Dathuc dtt; *this = dtt;
	}
	else {
		this->ds_heso = vec; this->bac_dathuc = vec.size() - 1;
		this->he_so_gia = vec.back();
		this->he_so_tre_trau = vec[0];
		loop(i, 0, ds_heso.size()) {
			if (ds_heso[i] == 0) so_he_so_null++;
		}
	}
	
}
Dathuc Dathuc::getDaThuc()
{
	so_he_so_null = 0;
	ds_heso.clear();
	int x,y;
	cout << "Nhap bac cua da thuc: ";
	cin >> y;
	system("cls");
	cout << "nhap he so da thuc: \n";
	loop(i, 0, y+1) {
		system("cls");
		cout << "a[" << i << "] = ";
		cin >> x;
		ds_heso.push_back(x);
	}
	Dathuc dt(ds_heso);
	loop(i, 0, dt.ds_heso.size()) {
		if (dt.ds_heso[i] == 0) so_he_so_null++;
	}
	*this = dt;
	return dt;
}

Dathuc Dathuc::getDaThuc_2_from_File(const char name[],int &vitri)
{
	int x, y,d=0;
	so_he_so_null = 0;
	ds_heso.clear();
	FILE *f=fopen(name, "r+");
	while (d!=vitri)
	{
		if (fgetc(f)=='.')
		{
			d++;
		}
	}
	fscanf(f, "%d", &y);
	vitri++;
	//cout << "Nhap bac cua da thuc: ";
	//cin >> y;
	//system("cls");
	//cout << "nhap he so da thuc: \n";
	loop(i, 0, y + 1) {
		fscanf(f, "%d", &x);
		ds_heso.push_back(x);
	}
	fclose(f);
	Dathuc dt(ds_heso);
	loop(i, 0, dt.ds_heso.size()) {
		if (dt.ds_heso[i] == 0) so_he_so_null++;
	}
	*this = dt;
	return dt;
}

Dathuc Dathuc::getDaThuc_3_from_File_new(const char name[], int & vitri)

	{
		int x, y, d = 0;
		so_he_so_null = 0;
		ds_heso.clear();
		FILE *f = fopen(name, "r+");
		while (d != vitri)
		{
			if (fgetc(f) == '.')
			{
				d++;
			}
		}
		fscanf(f, "%d", &y);
		vitri++;
		//cout << "Nhap bac cua da thuc: ";
		//cin >> y;
		//system("cls");
		//cout << "nhap he so da thuc: \n";
		fscanf(f, "%d", &x);
		ds_heso.push_back(x);
		loop(i, 1, y + 1) {
			for (int z = 0;; z++) {
				if(fgetc(f)=='+')
					break;
			}
			fscanf(f, "%d", &x);
			ds_heso.push_back(x);
		}
		fclose(f);
		reverse(ds_heso.begin(), ds_heso.end());
		Dathuc dt(ds_heso);
		loop(i, 0, dt.ds_heso.size()) {
			if (dt.ds_heso[i] == 0) so_he_so_null++;
		}
		*this = dt;
		return dt;
	}

void Dathuc::displaydt()
{	
	if (bac_dathuc == -1) cout << 0;
	else
	{
		int k = 0;
		while (ds_heso[k] == 0 && k != bac_dathuc + 1)
		{
			k++;
		}
		if (k == bac_dathuc+1) cout << 0;
		else
			{
				cout << ds_heso[k]<<"x^"<<k;
				loop(i, k+1, bac_dathuc + 1) {
					if (ds_heso[i])
						cout << " + " << ds_heso[i] << "x^" << i;
				}
			}
	}
}

void Dathuc::write_Dathuc_to_file()
{
	fstream f;                      // (2)
	f.open("output.txt", ios::app); // (2)
	if (bac_dathuc == -1) f << 0;
	else if (bac_dathuc == 0) f << he_so_tre_trau;
	else {
		f << he_so_gia << "x^" << bac_dathuc;
		for (int i = bac_dathuc - 1; i > 0; i--) {
			if (ds_heso[i])
				f << "+" << ds_heso[i] << "x^" << i;
		}
		if (he_so_tre_trau) {
			f << "+" << he_so_tre_trau;
		}
	}
	f.close();
}

void Dathuc::displaydt_2()
{
	
		if (bac_dathuc == -1) cout << 0;
		else if (bac_dathuc == 0) cout << he_so_tre_trau;
		else {
			cout << he_so_gia << "x^" << bac_dathuc;
			for (int i = bac_dathuc - 1; i > 0; i--) {
				if (ds_heso[i])
					cout << "+" << ds_heso[i] << "x^" << i;
			}
			if (he_so_tre_trau) {
				cout << "+" << he_so_tre_trau;
			}
		}
	
	
	
}

void Dathuc::displayfullinformationdt()
{	
	if (bac_dathuc == -1) {
		cout << "da thuc = 0";
	}
	else {
		cout << "he_so: ";
		loop(i, 0, this->bac_dathuc + 1) cout << "a[" << i << "] = " << this->ds_heso[i] << "  ";
	}
	cout << "\nbac da thuc: " << this->bac_dathuc;
	cout << "\nhe_so_gia: " << this->he_so_gia;
	cout << "\nhe_so_tre_trau: " << this->he_so_tre_trau;
	cout << '\n';
}

Dathuc Dathuc::Xu_ly_da_thuc_theo_modul(const int mdll)
{
	loop(i, 0, ds_heso.size())
		ds_heso[i] += mdll * 17;
	ds_heso = ds_heso % mdll;
	Dathuc dt_res(ds_heso);
	*this = dt_res;
	return dt_res;
}

Dathuc Dathuc::operator()(const vector<int>&vec)
{
	Dathuc phu(vec);
	*this = phu;
	return phu;
}




Matrixx::Matrixx()
{}

Matrixx Matrixx::Khoi_Tao_Matrix()
{
	cout << "nhap so dong: "; cin >> row;
	cout << "nhap so cot: "; cin >> column;
	vector<vector<Dathuc> > vec(row, vector<Dathuc>(column, (Dathuc({0}) )));
	loop(i, 0, row) {
		loop(j, 0, column) {
			system("cls");
			cout << "nhap a[" << i << "][" << j << "]: \n";
			vec[i][j].getDaThuc();
		}
	}
	arr_dt = vec;
	return *this;
}

Matrixx Matrixx::Khoi_Tao_Matrix_2()
{
	getchar();
	cout << "nhap ten file:  ";
	char name[15];
	fgets(name, 14, stdin);
	name[strlen(name) - 1] = '\0';
	int vitri = 1;
	cout << "nhap so dong: "; cin >> row;
	cout << "nhap so cot: "; cin >> column;
	
	vector<vector<Dathuc> > vec(row, vector<Dathuc>(column, (Dathuc({ 0 }))));
	loop(i, 0, row) {

		loop(j, 0, column) {
			system("cls");
			vec[i][j].getDaThuc_3_from_File_new(name,vitri);
		}
	}
	arr_dt = vec;
	return *this;
}

void Matrixx::display_Matrix()
{
	system("cls");
	int fomat = 35, phan_bu;
	int fomat_bac_6=6;
	loop(i, 0, row) {
		loop(j, 0, column) {
			phan_bu = 4;
			
			arr_dt[i][j].displaydt_2();
			if (arr_dt[i][j].he_so_tre_trau == 0) phan_bu=phan_bu-3;
			phan_bu +=(fomat_bac_6 - arr_dt[i][j].bac_dathuc + arr_dt[i][j].so_he_so_null)*5;
			if (arr_dt[i][j].bac_dathuc == -1) phan_bu = 34;
			if (phan_bu < 0) phan_bu = 1;
			loop(k, 0,phan_bu) cout << ' ';
		}
		cout << '\n';
	}
		
}

void Matrixx::ghi_file_matrix()
{
	int fomat = 35, phan_bu;
	int fomat_bac_6 = 6;
	/*loop(i, 0, row) {
		loop(j, 0, column) {
			phan_bu = 4;
			arr_dt[i][j].displaydt_2();
			if (arr_dt[i][j].he_so_tre_trau == 0) phan_bu = phan_bu - 3;
			phan_bu += (fomat_bac_6 - arr_dt[i][j].bac_dathuc + arr_dt[i][j].so_he_so_null) * 5;
			if (arr_dt[i][j].bac_dathuc == -1) phan_bu = 34;
			loop(k, 0, phan_bu) cout << ' ';
		}
		cout << '\n';
	}*/
	fstream f;                      // (2)
	 // (2)
	loop(i, 0, row) {
		loop(j, 0, column) {
			phan_bu = 4;
			if (arr_dt[i][j].bac_dathuc > 6) {
				cout << "da thuc bac cao: " << arr_dt[i][j].bac_dathuc << ' ';
			}
			else {
				arr_dt[i][j].write_Dathuc_to_file();
				if (arr_dt[i][j].he_so_tre_trau == 0) phan_bu = phan_bu - 3;
				phan_bu += (fomat_bac_6 - arr_dt[i][j].bac_dathuc + arr_dt[i][j].so_he_so_null) * 5;
				if (arr_dt[i][j].bac_dathuc == -1) phan_bu = 34;
				f.open("output.txt", ios::app);
				if (phan_bu < 0) phan_bu = 1;
				loop(k, 0, phan_bu) f << ' ';
			}
			f.close();
		}
		f.open("output.txt", ios::app);
		f << '\n';
		f.close();
	}
	f.open("output.txt", ios::app);
	f << '\n';
	f.close();
	 // (3)
	//f << data;                            // (3)

	

}

void Matrixx::hoan_vi_cot(int cl_1,int cl_2,bool is_true)
{
	if (is_true)
	{
		cout << "nhap so cot can hoan vi: ";
		cin >> cl_1 >> cl_2;
	}
	Dathuc dt;
	loop(i, 0, row) {
		dt = arr_dt[i][cl_1];
		arr_dt[i][cl_1]=arr_dt[i][cl_2];
		arr_dt[i][cl_2] = dt;
	}
}

void Matrixx::hoan_Vi_hang(int r_1, int r_2, bool is_true)
{
	if (is_true) {
		cout << "nhap so hang can hoan vi: ";
		cin >> r_1 >> r_2;
	}
	vector<Dathuc> rowOfMatrix;
	rowOfMatrix = arr_dt[r_1];
	arr_dt[r_1] = arr_dt[r_2];
	arr_dt[r_2] = rowOfMatrix;
	cout << "hoan vi xong " << r_1 << " va " << r_2 << '\n';
}

void Matrixx::cong_hang(Dathuc hs, int rw_1, int rw_2, bool is_true)
{
	if (is_true) {
		cout << "cong hang ";	cin >> rw_1;
		cout << "vao hang nao ?";	cin >> rw_2;
		cout << "nhap da thuc he so: \n";
		hs.getDaThuc();
	}
	vector<Dathuc> vec_phu = arr_dt[rw_1];
	vec_phu = vec_phu * hs;
	arr_dt[rw_2] = arr_dt[rw_2] + vec_phu;
}
void Matrixx::cong_cot(Dathuc hs, int cl_1, int cl_2, bool is_true)
{
	if (is_true) {
		cout << "cong cot ?"; cin >> cl_1;
		cout << "vao cot?"; cin >> cl_2;
		cout << "nhap da thuc he so: \n";
		hs.getDaThuc();
	}
	Dathuc dt_phu;
	loop(i, 0, row) {
		dt_phu = arr_dt[i][cl_1];
		dt_phu = dt_phu * hs;
		arr_dt[i][cl_2] = arr_dt[i][cl_2] + dt_phu;
	}
}
void Matrixx::Nhan_hang(int rw,int hs,bool is_auto)
{
	if (is_auto) {
		cout << "nhap so hang: "; cin >> rw;
		Dathuc dt_hs; dt_hs.getDaThuc();
		arr_dt[rw] = arr_dt[rw] * dt_hs;
	}
	else {
		arr_dt[rw] = arr_dt[rw] * hs;
	}
	
}
void Matrixx::Nhan_cot(int col, int hs, bool is_auto)
{
	if (is_auto) {
		cout << "nhap so cot: "; cin >> col;
		Dathuc dt_hs; dt_hs.getDaThuc();
		loop(i, 0, row) arr_dt[i][col] = arr_dt[i][col] * dt_hs;
	}
	else {
		loop(i, 0, row) arr_dt[i][col] = arr_dt[i][col] * hs;
	}
	
}
void Matrixx::dich_chuyen_theo_duong_cheo(int r_1, int cl_1, int r_2, int cl_2,bool oK)
{
	if (oK)
	{
		cout << "nhap vi tri hang cua phan tu thu nhat: "; cin >> r_1;
		cout << "nhap vi tri cot cua phan tu thu nhat: "; cin >> cl_1;
		cout << "nhap vi tri hang cua phan tu thu hai: "; cin >> r_2;
		cout << "nhap vi tri cot cua phan tu thu hai: "; cin >> cl_2;
	}
		this->hoan_Vi_hang(r_1, r_2, false);
		this->hoan_vi_cot(cl_1, cl_2, false);
}
void Matrixx::rut_Gon_row(const int mdl, int r_star, int cl_star, bool okk)
{
	int hs_nghich;
	if (okk) {
		cout << "vi tri bat dau tai hang: "; cin >> r_star;
		cout << "vi tri bat dau tai cot: "; cin >> cl_star;
	}
	
	loop(i, 1, mdl) {
		if ((i*arr_dt[r_star][cl_star].he_so_gia) % mdl == 1) {
			hs_nghich = i;
			break;
		} 
	}
	Dathuc dt_hs;
	//vector<Dathuc> dt_ml(column, Dathuc({mdl*5}));
	loop(i, r_star + 1, row) {
		dt_hs = arr_dt[i][cl_star];
		dt_hs = dt_hs * hs_nghich;
		dt_hs = dt_hs * (-1);
		cong_hang(dt_hs, r_star, i, false);
		//arr_dt[i] = arr_dt[i] + dt_ml;
		loop(j, 0, column) {
			arr_dt[i][j] = arr_dt[i][j].Xu_ly_da_thuc_theo_modul(mdl);
		}
	}
}
void Matrixx::rut_Gon_column(const int mdl,int r_star, int cl_star,bool okk)
{
	int hs_nghich;
	if (okk) {
		cout << "vi tri bat dau tai hang: "; cin >> r_star;
		cout << "vi tri bat dau tai cot: "; cin >> cl_star;
	}
	loop(i, 1, mdl) {
		if ((i*arr_dt[r_star][cl_star].he_so_gia) % mdl == 1) {
			hs_nghich = i;
			break;
		} 
	}
	Dathuc dt_hs;
	loop(i, cl_star + 1, column) {
		dt_hs = arr_dt[r_star][i];
		dt_hs = dt_hs * hs_nghich;
		dt_hs = dt_hs * (-1);
		cong_cot(dt_hs, cl_star, i, false);
		loop(j, 0, row) {
			arr_dt[j][i] = arr_dt[j][i].Xu_ly_da_thuc_theo_modul(mdl);
		}
	}

}
void Matrixx::rut_gon_column_da_thuc(int r_1,int cl_1, int r_2,int cl_2, int mod, bool is_true)
{
	if (is_true) {
		cout << "nhap vi tri hang de rut gon: "; cin >> r_1;
		cout << "nhap cot dung de rut gon: "; cin >> cl_1;
		cout << "nhap vi tri hang bi rut gon: "; cin >> r_2;
		cout << "nhap cot bi rut gon: "; cin >> cl_2;
		cout << "theo modul nao?"; cin >> mod;
	}
	Dathuc dt_hs = ChiaDathucTheoModul(arr_dt[r_2][cl_2], arr_dt[r_1][cl_1], mod);
	dt_hs = dt_hs*(-1);
	cong_cot(dt_hs, cl_1, cl_2,false);
	loop(i, 0, row) {
		arr_dt[i][cl_2] = arr_dt[i][cl_2].Xu_ly_da_thuc_theo_modul(mod);
	}
}
void Matrixx::rut_gon_row_da_thuc(int r_1, int cl_1, int r_2, int cl_2, int mod, bool is_true)
{
	if (is_true) {
		cout << "nhap vi tri hang de rut gon: "; cin >> r_1;
		cout << "nhap cot dung de rut gon: "; cin >> cl_1;
		cout << "nhap vi tri hang bi rut gon: "; cin >> r_2;
		cout << "nhap cot bi rut gon: "; cin >> cl_2;
		cout << "theo modul nao?"; cin >> mod;
	}
	Dathuc dt_hs = ChiaDathucTheoModul(arr_dt[r_2][cl_2], arr_dt[r_1][cl_1], mod);
	dt_hs = dt_hs*(-1);
	cong_hang(dt_hs, r_1, r_2, false);
	loop(j, 0, column) {
		arr_dt[r_2][j] = arr_dt[r_2][j].Xu_ly_da_thuc_theo_modul(mod);
	}
}
void Matrixx::Sua_MaTrix()
{
	int r_1, l_1;
	cout << "nhap vi tri hang can sua: ";
	cin >> r_1;
	cout << "nhap vi tri cot can sua: ";
	cin >> l_1;
	arr_dt[r_1][l_1].getDaThuc();
}
void Matrixx::get_R_1(const Matrixx& m)
{
	cout << "nhap so dong: "; cin >> row;
	cout << "nhap so cot: "; cin >> column;
	vector<vector<Dathuc> > vec(row, vector<Dathuc>(column, (Dathuc({ 0 }))));
	loop(i, 0, row) {
		loop(j, 0, column) {
			vec[i][j] = m.arr_dt[i][j];
		}
	}
	this->arr_dt = vec;
}
void Matrixx::get_matran_con(const Matrixx &m) {
	int r_bg, cl_bg, r_end, cl_end;
	cout << "nhap vi tri dong bat dau lay: "; cin >> r_bg;
	cout << "nhap vi tri cot bat dau lay: "; cin >> cl_bg;
	cout << "nhap vi tri dong ket thuc: "; cin >> r_end;
	cout << "nhap vi tri cot ket thuc: "; cin >> cl_end;
	this->row = r_end - r_bg + 1;
	this->column = cl_end - cl_bg + 1;
	vector<vector<Dathuc> > vec(row, vector<Dathuc>(column, (Dathuc({ 0 }))));
	loop(i, r_bg, r_end+1) {
		loop(j, cl_bg, cl_end+1) {
			vec[i-r_bg][j-cl_bg] = m.arr_dt[i][j];
		}
	}
	this->arr_dt = vec;
	this->display_Matrix();
	system("pause");
}

void Matrixx::get_R1_R2_nghichdao(const Matrixx & r1, const Matrixx & r2)
{
	loop(i, 0, r1.row) {
		loop(j, 0, this->column) {
			this->arr_dt[i][j] = r1.arr_dt[i][j];
		}
	}
	loop(i, r1.row, this->row) {
		loop(j, 0, this->column) {
			this->arr_dt[i][j] = r2.arr_dt[i- r1.row][j];
		}
	}
	//system("cls");
	this->display_Matrix();
	cout << "okiii\n";
	system("pause");
}
void Matrixx::step_3_boc_hs(const Matrixx& r3)
{
	int bac_max = 0;
	loop(i, 0, r3.row) {
		loop(j, 0, r3.column) {
			if (r3.arr_dt[i][j].bac_dathuc > bac_max) bac_max = r3.arr_dt[i][j].bac_dathuc;
		}
	}
	bac_max++;
	vector<vector<vector<int> > > vec(bac_max, vector<vector<int> >(r3.column,vector<int>(r3.column)));
	loop(k, 0, bac_max) {
		loop(i, 0, r3.row) {
			loop(j, 0, r3.column) {
				if (r3.arr_dt[i][j].bac_dathuc < k) vec[k][i][j] = 0;
				else {
					vec[k][i][j] = r3.arr_dt[i][j].ds_heso[k];
				}
			}
		}
	}
	write_matrix(vec);
	cout << "thanh cong tot dep!!\n";
	system("pause");
}
VITRIOFDATHUCMIN Matrixx::getViTriBacMin(int r_bg, int cl_bg, int r_end, int cl_end, bool is_ok)
{
	if (is_ok) {
		cout << "nhap vi tri row bat dau tim kiem:  "; cin >> r_bg;
		cout << "nhap vi tri column bat dau tim kiem:  "; cin >> cl_bg;
		cout << "nhap vi tri row ket thuc tim kiem:  "; cin >> r_end;
		cout << "nhap vi tri column ket thuc tim kiem:  "; cin >> cl_end;
	}
	VITRIOFDATHUCMIN vt_min;
	int bac_min;
	if (this->arr_dt[r_bg][cl_bg].bac_dathuc == -1)bac_min = 100; else {   // doi voi thang bac -1 phai gan bac 0 moi ss dc.
		bac_min = this->arr_dt[r_bg][cl_bg].bac_dathuc;
	}
	vt_min.cl_min = cl_bg; vt_min.r_min = r_bg;
	loop(j, cl_bg, cl_end ) {
		loop(i, r_bg, r_end ) {
			if (this->arr_dt[i][j].bac_dathuc == 0) {
				vt_min.r_min = i, vt_min.cl_min = j; 
				vt_min.is_min = false;
				return vt_min;
			}
			if (bac_min > this->arr_dt[i][j].bac_dathuc&&this->arr_dt[i][j].bac_dathuc != -1) {
				bac_min = this->arr_dt[i][j].bac_dathuc;
				vt_min.r_min = i; vt_min.cl_min = j;
			}
		}
	}
	if (vt_min.r_min == r_bg&&vt_min.cl_min == cl_bg) {    // neu vi tri bat dau tim kiem la nho nhat thi tra ve true.
		vt_min.is_min = true;
	}
	else vt_min.is_min = false;
	return vt_min;
}
int Matrixx::cheDoSoLo1vs1(const int md,int r_b,int l_b,int r_e,int l_e,bool ok)
{
	int x_0, y_0,x_1,y_1;
	int temp;
	if (ok) {
		cout << "nhap vi tri bat dau row and column  "; cin >> r_b >> l_b;
		cout << "nhap vi tri ket thuc row and column  "; cin >> r_e >> l_e;
	}
	x_0 = r_b, y_0 = l_b, x_1 = r_e, y_1 = l_e;
	if ((r_e == r_b&&l_e == l_b)||(l_e!=l_b&&r_e!=r_b)) return -1;
	if (l_b == l_e) {
		while (this->arr_dt[r_b][l_b].bac_dathuc >= 0 && this->arr_dt[r_e][l_e].bac_dathuc >= 0)   // xu ly theo hang.
		{
			this->rut_gon_row_da_thuc(r_b, l_b, r_e, l_e,md,false);
			temp = r_b; r_b = r_e; r_e = temp;
		}
		if (this->arr_dt[x_0][y_0].bac_dathuc == -1) {    // neu tai vi tri ban dau bi bang 0 thi swap
			this->hoan_Vi_hang(x_0, x_1,false);
		}
	}
	else {
		while (this->arr_dt[r_b][l_b].bac_dathuc >=0 && this->arr_dt[r_e][l_e].bac_dathuc >=0)   // xu ly theo cot.
		{
			this->rut_gon_column_da_thuc(r_b, l_b, r_e, l_e, md, false);
			temp = l_b; l_b = l_e; l_e = temp;
		}
		if (this->arr_dt[x_0][y_0].bac_dathuc == -1) {   // neu tai vi tri ban dau bi bang 0 thi swap
			this->hoan_vi_cot(y_0, y_1, false);
		}
	}
	return 0;
}

bool Matrixx::is_delitel(const int & md,int r_bd,int l_bd)
{
	bool ktra = true;
	Dathuc d, nu({1});
	loop(i, r_bd, this->row-1) {
		for (int j = 1; i+j< this->row; j++)
		 {
			if (ChiaDathucTheoModulGet_phan_du(this->arr_dt[i+j][i+j-r_bd], this->arr_dt[i][i - r_bd], d, md).bac_dathuc != -1) {
				this->cong_cot(nu, i + j - r_bd, i - r_bd, false);
				return false;
			}
		}
		
	}
	return ktra;
}


int Matrixx::CheDoHuyDiet(const int& md)
{
	bool is_solo, g_han=0;
	VITRIOFDATHUCMIN vtri_dt_min;
	DIEUKIEN dieu_kien;
	int bgin_hd_r, bgin_hd_cl,z=0;
	cout << "nhap vi tri bat dau huy diet r-cl:  "; cin >> bgin_hd_r >> bgin_hd_cl;
	NHAY_TIEP:
		loop(i, bgin_hd_r, this->row - 1) {
			vtri_dt_min.is_min = true;
			/*this->display_Matrix();
			system("pause");*/
			is_solo = false;
			NHAY:
			if (this->arr_dt[i][z].bac_dathuc == 0) {
				this->rut_Gon_column(md, i, z, false);
				this->rut_Gon_row(md, i, z, false);
			}
			else {
				vtri_dt_min = this->getViTriBacMin(i, z, this->row, this->column, false);
				if (vtri_dt_min.is_min == false) {
					dich_chuyen_theo_duong_cheo(i, z, vtri_dt_min.r_min, vtri_dt_min.cl_min, false);
					if (this->arr_dt[i][z].bac_dathuc == 0) {
						goto NHAY;
					}
				}
				loop(j, i + 1, this->row) {
					/*cout << "khu hang\n";
					this->display_Matrix();
					system("pause");*/
					if (this->arr_dt[j][z].bac_dathuc != -1) {
						this->cheDoSoLo1vs1(md,i, z, j, z, false);   // khu cot.
						is_solo = true;
					}
				}
				loop(j, z + 1, this->column) {
					//cout << "khu cot\n";
					if (this->arr_dt[i][j].bac_dathuc != -1) {
						this->cheDoSoLo1vs1(md,i, z, i, j, false);   // khu hang.
						is_solo = true;
					}
				}
				
			}
			
			if (is_solo) {
				i = bgin_hd_r-1;
				z = 0;
			}
			else {
				z++;
			}

		}
		if (!this->is_delitel(md, bgin_hd_r, bgin_hd_cl)) {
			z = 0;
			g_han++;
			if (g_han < 3) {
				goto NHAY_TIEP;
			}
		}
		//this->display_Matrix();
		int hs_nghich_dao;
		loop(i, bgin_hd_r, this->row) {
			loop(j, 1, md) {
				if ((j * this->arr_dt[i][i - bgin_hd_r].he_so_gia) % md == 1) {
					hs_nghich_dao = j; break;
				}
			}
			this->Nhan_hang(i,hs_nghich_dao,false);
		}
	return 17;
}
int Matrixx::CheDoHuy_Diet_2(int md, int r_bg, int l_bg, bool is_auto)
{
	int hs;
	if (is_auto) {
		cout << "vi tri bat dau huy diet r-c:  "; cin >> r_bg >> l_bg;

	}
	loop(i, r_bg, this->row) {
		loop(j, 0, this->column - i+r_bg) {
			/*this->display_Matrix();
			system("pause");*/
			if (this->arr_dt[i][j].bac_dathuc == 0) {
				this->hoan_vi_cot(0, j, false);
				loop(t, 1, md) {
					if ((((this->arr_dt[i][0].he_so_gia*t) % md)+md)%md == 1) {
						hs = t;
						break;
					}
				}
				this->Nhan_cot(0, hs, false);
				this->rut_Gon_column(md, i, 0, false);
				this->hoan_vi_cot(0, this->column - i + r_bg - 1, false);
				break;
			}
		}
	}
	this->DaoNguocVector();
	return 17;
}
void Matrixx::DaoNguocVector()
{
	loop(i, 0, this->row) {
		reverse(this->arr_dt[i].begin(), this->arr_dt[i].end());
	}
}
bool Matrixx::check_giong_nhau(const Matrixx &m2)
{
	if (m2 == *(this)) {
		cout << "2 ma tran co cung kanonhi\n";
		system("pause");
		return true;
	}
	else {
		cout << "2 ma tran khong cung kanonhi\n";
		system("pause");
		return false;
	}
}
int Matrixx::timCAC() {
	bool nhay=true;
	int modul=5;
	cout << "nhap modul: "; cin >> modul;
	Matrixx r_1, r_2, r_3, k_1, k_2;
	VITRIOFDATHUCMIN vtri_dthuc_min;
STEP2:
	fstream f;                      // (2)
	f.open("output.txt", ios::out); // (2)
	f << "\n\n\t\t================================== welcome to the endless era by Hoang HK ==================================!!\n\n";
	f.close();
	Matrixx mt_1;
	mt_1.Khoi_Tao_Matrix_2();
	mt_1 = mt_1 % modul;
	mt_1.CheDoHuyDiet(modul);
	mt_1 = mt_1 % modul;
	r_1.get_R_1(mt_1);
	// them dong nay
	k_1.get_matran_con(mt_1);
	//

	this->Khoi_Tao_Matrix_2();
	*this = *this % modul;
	this->CheDoHuyDiet(modul);
	*this = *this % modul;
	r_2.get_R_1(*this);
	// them
	k_2.get_matran_con(*this);
	if (!k_1.check_giong_nhau(k_2)) {
		exit(-17);
	};
	
	//
	this->get_R1_R2_nghichdao(r_1, r_2);
	this->CheDoHuy_Diet_2(modul);
	*this = *this % modul;
	r_3.get_R_1(*this);
	/*r_3.display_Matrix();
	system("pause");*/
	this->step_3_boc_hs(r_3);
	f.open("output.txt", ios::app); // (2)
	f << "\n\n\t\t================================== Code by Hoang HK ==================================!!\n\n";
	f.close();
	return 17;
}
bool operator==(const Matrixx &m1,const Matrixx &m2)
{
	return m1.arr_dt == m2.arr_dt;
}
bool operator!=(const Matrixx &m1, const Matrixx &m2)
{
	return m1.arr_dt != m2.arr_dt;
}
vector<Dathuc> operator+(const vector<Dathuc>& dt_a, const vector<Dathuc>&dt_b) {
	//max_Size_of_vector
	vector<Dathuc> dt_res;
	if (dt_a.size() > dt_b.size()) {
		dt_res = dt_a;
		loop(i, 0, dt_b.size()) dt_res[i] = dt_res[i] + dt_b[i];
	}
	else {
		dt_res = dt_b;
		loop(i, 0, dt_a.size()) dt_res[i] = dt_res[i] + dt_a[i];
	}
	return dt_res;
}
vector<Dathuc> operator*(const vector<Dathuc>& dt_1, const int&he_so) {
	vector<Dathuc> vec_1 = dt_1;
	loop(i, 0, vec_1.size()) vec_1[i] = vec_1[i] * he_so;
	return vec_1;
}
Dathuc operator%(Dathuc &dt_1, const int &modul) {
	dt_1.ds_heso = dt_1.ds_heso%modul;
	Dathuc dt_res(dt_1.ds_heso);
	dt_1 = dt_res;
	return dt_1;
}
vector<Dathuc> operator%(vector<Dathuc>&dt_1, const int &modul) {
	loop(i, 0, dt_1.size()) dt_1[i] = dt_1[i] % modul;
	return dt_1;
}
Matrixx operator%(Matrixx&mt_1, const int &modul) {
	loop(i, 0, mt_1.row) mt_1.arr_dt[i] = mt_1.arr_dt[i] % modul;
	return mt_1;
}
vector<Dathuc> operator*(const vector<Dathuc>& vec_dt, const Dathuc&hs) {
	vector<Dathuc> vec_res = vec_dt;
	loop(i, 0, vec_dt.size())
		vec_res[i] = vec_dt[i] * hs;
	return vec_res;
}
int Matrix_AI() {
	int modul;
	cout << "nhap modul: "; cin >> modul;
	Matrixx r_1,r_2,r_3,k_1,k_2;
	VITRIOFDATHUCMIN vtri_dthuc_min;
STEP2:
	fstream f;                      // (2)
	f.open("output.txt", ios::out); // (2)
	f << "\n\n\t\t================================== welcome to the endless era by Hoang HK ==================================!!\n\n";
	f.close();
	Matrixx mt_1;
	mt_1.Khoi_Tao_Matrix_2();
	mt_1 = mt_1 % modul;
	int a; 
	do
	{
		cout << "\n\n\n\n\n\n\n\n";
		mt_1.display_Matrix();
		mt_1.ghi_file_matrix();
		cout << "\n\n\n\t\t\t=================================  Menu  =================================\n\n\n";
		cout << "0.de ket thuc.\n";
		cout << "1.hoan vi hang.\n";
		cout << "2.hoan vi cot.\n";
		cout << "3.cong hang vao hang.\n";
		cout << "4.cong cot vao cot.\n";
		cout << "5.nhan hang.\n";
		cout << "6.nhan cot.\n";
		cout << "7.rut gon row.\n";
		cout << "8.rut gon column.\n";
		cout << "9.dac biet cl.\n";
		cout << "10.dac biet rw.\n";
		cout << "11.sua matrix.\n";
		cout << "12.Dich_chuyen_cheo.\n";
		cout << "13.Get R_1.\n";
		cout << "14.Get R_2.\n";
		cout << "15.step2 matran B.\n";
		cout << "16.step3 tim r1*r2^-1.\n";
		cout << "17.Get r1*r2^-1.\n";
		cout << "18.step4 boc tach he so.\n";
		cout << "19.tim da thuc co he so nho nhat hoac bac 0 dau tien trong arr.\n";
		cout << "20.che do solo 1vs1.\n";
		cout << "21.che do huy diet!!.\n";
		cout << "22.che do huy diet 2!!.\n";
		cout << "23.get_k1.\n";
		cout << "24.get_k2.\n";
		cout << "25.check kanonhi 2 matrixx.\n";
		cout << "\n\n\n\t\t\t============================  Made by P.M.H  ============================\n";
		cin >> a;
		switch (a)
		{
		case 1:
			mt_1.hoan_Vi_hang();
			mt_1 = mt_1 % modul;
			break;
		case 2:
			mt_1.hoan_vi_cot();
			mt_1 = mt_1 % modul;
			break;
		case 3:
			mt_1.cong_hang();
			mt_1 = mt_1 % modul;
			break;
		case 4:
			mt_1.cong_cot();
			mt_1 = mt_1 % modul;
			break;
		case 5: 
			mt_1.Nhan_hang();
			mt_1 = mt_1 % modul;
			break;
		case 6:
			mt_1.Nhan_cot();
			mt_1 = mt_1%modul;
			break;
		case 7:
			mt_1.rut_Gon_row(modul);
			mt_1 = mt_1%modul;
			break;
		case 8:
			mt_1.rut_Gon_column(modul);
			mt_1 = mt_1%modul;
			break;
		case 9:
			mt_1.rut_gon_column_da_thuc();
			mt_1 = mt_1%modul;
			break;
		case 10:
			mt_1.rut_gon_row_da_thuc();
			mt_1 = mt_1%modul;
			break;
		case 11:
			mt_1.Sua_MaTrix();
			mt_1 = mt_1%modul;
			break;
		case 12:
			mt_1.dich_chuyen_theo_duong_cheo();
			mt_1 = mt_1%modul;
			break;
		case 13:
			r_1.get_R_1(mt_1);
			r_1.display_Matrix();
			system("pause");
			break;
		case 14:
			r_2.get_R_1(mt_1);
			r_2.display_Matrix();
			system("pause");
			break;
		case 15:
			system("cls");
			cout << "1 2 3... nhay nhay nhay...\n";
			system("pause");
			goto STEP2;
			break;
		case 16:
			mt_1.get_R1_R2_nghichdao(r_1, r_2);
			mt_1 = mt_1 % modul;
			break;
		case 17:
			r_3.get_R_1(mt_1);
			r_3.display_Matrix();
			system("pause");
			break;
		case 18:
			mt_1.step_3_boc_hs(r_3);
			break;
		case 19:
			vtri_dthuc_min=mt_1.getViTriBacMin();
			int cd;
			do 
			{
				
				cout << "\n\n.0 dich chuyen.";
				cout << "\n.1 khong dich chuyen.";
				cin >> cd;
			} while (cd !=0&&cd!=1);
			if (cd == 0) {
				int r_cd,l_cd;
				cout << "vi tri can dich chuyen voi phan tu bac min Of ARR:  "; cin >> r_cd >> l_cd;
				mt_1.dich_chuyen_theo_duong_cheo(r_cd, l_cd, vtri_dthuc_min.r_min, vtri_dthuc_min.cl_min, false);
			}
			break;
		case 20:
			mt_1.cheDoSoLo1vs1(modul);
			system("pause");
			mt_1 = mt_1 % modul;
			break;
		case 21:
			mt_1.CheDoHuyDiet(modul);
			mt_1 = mt_1 % modul;
			break;
		case 22:
			mt_1.CheDoHuy_Diet_2(modul);
			mt_1 = mt_1 % modul;
			break;
		case 23:
			k_1.get_matran_con(mt_1);
			break;
		case 24:
			k_2.get_matran_con(mt_1);
			break;
		case 25:
			k_1.check_giong_nhau(k_2);
			break;
		default:
			cout << "co biet doc kko? nhap tu 0->4";
			break;
		}
	} while (a);
	f.open("output.txt", ios::app); // (2)
	f << "\n\n\t\t================================== Code by Hoang HK ==================================!!\n\n";
	f.close();
	return 0;
}
vector<vector<int> > read_matrix() {
	int r, cl;
	cout << "so row: "; cin >> r;
	cout << "so column: "; cin >> cl;
	vector<vector<int> >vec(r, vector<int>(cl));
	fstream f;
	f.open("myinput.txt", ios_base::in);
	loop(i, 0, r)
		loop(j, 0, cl) {
		f >> vec[i][j];
	}
	f.close();
	return vec;
}
void write_matrix(const vector<vector<vector<int> > >&vec) {
	fstream f;
	f.open("C:\\Users\\ThangVu\\Documents\\pmhoang\\luu chuong trinh\\code_matrix_AI\\code_matrix_AI\\dshs.txt", ios_base::app);
	if (f.fail())
	{
		system("cls");
		cout << "fail!!/n";
		exit(1);
	}
	else {
		f << "bac da thuc:  ";
		f << vec.size() - 1;
		f << '\n';
		loop(i, 0, vec.size()) {
			f << '.';
			loop(j, 0, vec[0].size()) {
				loop(k, 0, vec[0][0].size()) {
					f << vec[i][j][k] << ' ';
				}
				f << '\n';
			}
			f << "\n\n";
		}
	}
	f.close();
}