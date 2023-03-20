#pragma one
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cstdlib>
#define loop(i,a,n) for (int i = (unsigned)a; i < (unsigned)n; i++)
#define loopp(x,op) for(auto x : op)
		

using namespace std;

struct VITRIOFDATHUCMIN
{
	int r_min, cl_min;
	bool is_min;
};
struct VITRIOFDATHUCKChiaHet
{
	int r_dathuc_kch, cl_dathuc_kch;
	bool is_delitell;
};
struct DIEUKIEN
{
	bool is_bac_min=false, is_delitel=false;
};
class Matrixx;
class Dathuc;
class Dathuc {
private:
public:
	vector<int> ds_heso;
	int bac_dathuc;
	int he_so_gia;
	int he_so_tre_trau;
	int so_he_so_null;
	Dathuc();
	Dathuc(vector<int> vec);
	Dathuc getDaThuc(); 
	Dathuc getDaThuc_2_from_File(const char[],int &vitri);
	Dathuc getDaThuc_3_from_File_new(const char[], int &vitri);
	void displaydt();
	void write_Dathuc_to_file();
	void displaydt_2();
	void displayfullinformationdt();
	Dathuc Xu_ly_da_thuc_theo_modul(const int);
	Dathuc operator()(const vector<int>&);
	friend bool operator==(const Dathuc&, const Dathuc&);
	friend bool operator!=(const Dathuc&, const Dathuc&);
	friend Matrixx;
};
class Matrixx {
public:
	int rang;
	int row;
	int column;
	vector<vector<Dathuc> > arr_dt;
	Matrixx();
	Matrixx Khoi_Tao_Matrix();
	// khoi tao da thuc bang cach doc tu file:
	// theo cong thuc: . (bac da thuc) (a[0] a[1] ....).
	Matrixx Khoi_Tao_Matrix_2();
	void display_Matrix();
	void ghi_file_matrix();
	void hoan_vi_cot(int cl_1=0,int cl_2=0,bool is_true=true);
	void hoan_Vi_hang(int r_1=0,int r_2=0,bool is_true = true);
	void cong_hang(Dathuc dt_hs = Dathuc({ 0 }), int rw_1 = 0, int rw_2 = 0, bool is_true = true);
	void cong_cot(Dathuc dt_hs = Dathuc({ 0 }), int cl_1 = 0, int cl_2 = 0, bool is_true = true);
	void Nhan_hang(int r=0,int hs=0,bool is_auto=true);
	void Nhan_cot(int r = 0, int hs = 0, bool is_auto = true);
	void dich_chuyen_theo_duong_cheo(int a=0, int b=0, int c=0,int d=0, bool oK = true);
	// toan bo dong nam duoi vi tri duoc chon.
	void rut_Gon_row(const int, int rst = 0, int lst = 0, bool okk = true);
	// toan bo column nam ben phai vi tri duoc chon.
	void rut_Gon_column(const int,int rst=0,int lst=0,bool okk=true);
	void rut_gon_column_da_thuc(int r_1=0,int cl_1 = 0,int r_2=0, int cl_2 = 0,int mod=0, bool is_true = true);
	void rut_gon_row_da_thuc(int r_1 = 0, int cl_1 = 0, int r_2 = 0, int cl_2 = 0, int mod = 0, bool is_true = true);
	void Sua_MaTrix();
	void get_R_1(const Matrixx&);
	void get_matran_con(const Matrixx&);
	void get_R1_R2_nghichdao(const Matrixx&, const Matrixx&);
	void step_3_boc_hs(const Matrixx&);
	VITRIOFDATHUCMIN getViTriBacMin(int r_bg=0, int cl_bg=0, int r_end=0, int cl_end=0, bool is_ok = true);
	int cheDoSoLo1vs1(const int md,int r_b=0,int l_b = 0,int r_e = 0,int l_e = 0, bool ok = true);
    bool is_delitel(const int &md,int r_bd, int l_bd);
	int CheDoHuyDiet(const int& md=5);
	int CheDoHuy_Diet_2 (int md = 5,int r=0,int l =0,bool autoo=true);
	void DaoNguocVector();
	
	friend bool operator==(const Matrixx&, const Matrixx&);
	friend bool operator!=(const Matrixx&, const Matrixx&);
	bool check_giong_nhau(const Matrixx&);
	int timCAC();
	friend Dathuc;
};
struct maTran {
	int rang;
	vector<int> index_basic;
}; 
struct reslchiadathuc {
	Dathuc res;
	Dathuc phanDu;
};
Matrixx operator%(Matrixx&, const int &);
//Matrixx operator*(const Matrixx&, const Dathuc&);
Dathuc operator%(Dathuc &, const int &modul);
vector<Dathuc> operator%(vector<Dathuc>&,const int &);
vector<Dathuc> operator+(const vector<Dathuc>&, const vector<Dathuc>&);
vector<Dathuc> operator*(const vector<Dathuc>&, const Dathuc&);
vector<Dathuc> operator*(const vector<Dathuc>&, const int&);
Dathuc operator*(const Dathuc &, const Dathuc &);
Dathuc operator+(const Dathuc &,const Dathuc &);
Dathuc operator+(const Dathuc &, const int&);
Dathuc operator+(const int&,const Dathuc &);
Dathuc operator-(const Dathuc &, const Dathuc &);
Dathuc operator*(const Dathuc &,const int &);
Dathuc operator*(const int &, const Dathuc & );
// dung de kiem tra matrix 0
bool operator==(const vector<vector<int> >&a, const int x);
// dung de ktra vector null
bool operator==(const vector<int>&a, int i);
// chen them x so 0 vao dau vector.
vector<int> operator>>(const vector<int>&, const int &x);
vector<vector<int> > operator+(const vector<vector<int> >&a, const vector<vector<int> >&b);
vector<vector<int> > operator-(const vector<vector<int> >&a, const vector<vector<int> >&b);
vector<int> operator+(const vector<int>&, const vector<int>&);
vector<int> operator-(const vector<int>&, const vector<int>&);
vector<int> operator*(vector<int>a, int x);
vector<int> operator%(vector<int>a, int modul);
vector<int> operator/(vector<int>a, int x);
vector<vector<int> > operator*(const vector<vector<int> >&a, const vector<vector<int> >&b);
vector<int> operator*(const vector<vector<int> >&a, const vector<int>&b);
vector<vector<int> > operator%(const vector<vector<int> >&a,int modul);
int getMin(size_t a, size_t b);
//bool operator==(const vector<Dathuc> &, const vector<Dathuc> &);

void tinhBacCuaHam(int n, int m, bool *a);
void tinhBacCuaHam(int n, int m, int *a, int modul);

;

void writeToFile(FILE *f);
string readFromfile(FILE *f, int size);
bool checkColumn(vector<vector<char> >grid);
bool checkRow(vector<vector<char> >grid);
bool checkMatrix(vector<vector<char> >grid);
vector<vector<int> > swapprow(vector<vector<int> >&vec_a, int i, int j);
vector<vector<int> > step_1(vector<vector<int> >&vec_a, int rang, int column);
vector<vector<int> > step_2(vector<vector<int> >&vec_a, int i);
vector<vector<int> > step_3(vector<vector<int> >&vec_a, int rang, vector<int> &idbasic);
maTran xuLyMatrix(vector<vector<int> >&vec_a);
vector<vector<int> >getMatrix(int,int);
void display(vector<vector<int> >&vec_a);
void display(const vector<vector<int> >&vec_a);
vector<vector<int> >pushcolumn(vector<vector<int> >&matrix,const vector<int> &a);
void GetDaThuc_0VecTor(const vector<vector<int> >&vec_a);
vector<vector<int> > ChuyenVimtrix(const vector<vector<int> >&mtran);
void TimkopenLp(const vector<vector<int> >&maTran);
void pushpackvectorTovt(vector<int> &v_first, const vector<int> &v_last);
vector<vector<int> >TimMtrixNghichNgom(const vector<vector<int> >&maTrix);
int TimRankMatrix(const vector<vector<int> >&maTrix);
vector<int> TimIndexbasicMatrix(const vector<vector<int> >&maTrix);
Dathuc ChiaDathucTheoModulGet_phan_du(const Dathuc&d_1, const Dathuc&d,Dathuc &, const int& modul);
Dathuc ChiaDathucTheoModul(const Dathuc&d_1, const Dathuc&d, const int& modul);
/*reslchiadathuc ChiaDathucTheoModul(const Dathuc&d_1, const Dathuc&d, const int& modul);*/
int Matrix_AI();
vector<vector<int> > read_matrix();
void write_matrix(const vector<vector<vector<int> > >&);

