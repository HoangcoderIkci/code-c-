#define _CRT_SECURE_NO_WARNINGS
#include "FunctionDaThuc.h"
static vector<int> *ArrayHsNgto;
static vector<int> CongVector(vector<int>v1, vector<int>v2)
 {
	 int sz1 = v1.size();
	 int sz2 = v2.size();
	 vector<int> res;
	 if (sz1 <= sz2) {
		 res = v2;
		 int i; for (i = 0; i < sz1; res[i] += v1[i], i++);
	 }
	 else {
		 res = v1;
		 int i; for (i = 0; i < sz1; res[i] += v2[i], i++);
	 }
	 return res;
};
static vector<int> NhanVector(vector<int>v1, int x) {
	int sz = v1.size();
	int i; for (i = 0; i < sz; v1[i] *= x, i++);
	return v1;
}
static void KhoiTaoMap() {
	FILE *flie; vector<int> vec_hs; int bac;
	flie = fopen("danhsachheso.txt","r");
	if (!flie) {
		cout << "Doc file Khong thanh cong!!!\n"; system("pause"); exit(-1);
	}
	int i,j,hs,n = 23;
	for (i = 0; i < n; i++) {
		fscanf(flie, "%d", &bac);
		vector<int> vec_hs(bac + 1);
		for (j = 0; j < bac + 1; j++) {
			fscanf(flie, "%d", &hs);
			vec_hs[bac-j] = hs;
		}
		ArrayHsNgto[i] = vec_hs;
	}
	fclose(flie);
}
bool CheckChiaHet(vector<int> vec1,vector<int> vec2,int md) {
	//if (dt1->_modul_da_thuc != dt2->_modul_da_thuc) exit(-1);
	int do_lech_bac = vec1.size() - vec2.size();
	vector<int> vec_bc = vec2;
	vector<int> v_res;
	int i, j, k, hs, back_vec_bc = vec_bc.back(), back_vec_chia; int sz = vec_bc.size();
	int m;
	//int ktra = -1;
	vector<int> vec_chia = vec1;
	int bac = vec_chia.size() - 1;
	k = bac + 1 - sz;
	while (k >= 0)
	{
		back_vec_chia = vec_chia.back();
		//tim hs
		for (j = 1; j < md; j++) {
			if (((back_vec_bc*j) - back_vec_chia) % md == 0) {
				hs = j;
				break;
			}
		}
		for (i = 0; i < sz; i++) {
			m = vec_chia[i + k] - vec_bc[i] * hs;
			m = ((m%md) + md) % md;
			vec_chia[i + k] = m;
		}
		while (!vec_chia.empty()&&vec_chia.back()==0)
		{
			vec_chia.pop_back();
		}
		if (vec_chia.empty()) bac = 0;
		else bac = vec_chia.size() - 1;
		k = bac + 1 - sz;
	}
	while (!vec_chia.empty() && vec_chia.back() % md == 0)
		vec_chia.pop_back();
	if (vec_chia.empty()) {
		return true;
	}
	return false;
}
bool checkDaTHucDonG(vector<int> Dt,const int &md) {
	int i, bac; bac = (Dt.size()-1)/2;
	ArrayHsNgto = new vector<int>[23];
	KhoiTaoMap();
	for (i = 0; i < 23; i++) {
		if (ArrayHsNgto[i].size() - 1>bac) return true;
		if (CheckChiaHet(Dt, ArrayHsNgto[i], md)) {
			return false;
		}
	}
	return true;
}
vector<int> * checkMang() {
	ArrayHsNgto = new vector<int> [23];
	KhoiTaoMap();
	return ArrayHsNgto;
}
 DathucInt * KhoiTaoDathucDefault()
{
	int md, k,bac;
	DathucInt *Dt = new DathucInt;
	if (Dt == nullptr) {
		cout << "ERROR!! het bo nho.\n"; system("pause"); exit(-1);
	}
	do
	{
		cout << "nhap modul da thuc: "; cin >> md;
	} while (md <= 0); Dt->_modul_da_thuc = md;
	do
	{
		cout << "nhap bac da thuc: "; cin >> bac;
	} while (bac < 0);
	Dt->_ds_hs.resize(bac + 1);
	int i; for (i = 0; i <= bac; i++) {
		printf("a[%d] =  ", i); cin >> k;
		k = ((k % md) + md) % md;; Dt->_ds_hs[i] = k;
	}
	while (!Dt->_ds_hs.empty() && Dt->_ds_hs.back() == 0)
	{
		Dt->_ds_hs.pop_back();
	}
	if (Dt->_ds_hs.empty()) Dt->_ds_hs.push_back(0);
	return Dt;
}

 DathucInt * KhoiTaoDathuc(const vector<int> &vec_input,const int &md)
{
	if (md <= 0) exit(-1);
	DathucInt *res = new DathucInt; res->_modul_da_thuc = md;
	if (vec_input.empty()) res->_ds_hs.push_back(0);
	else {
		vector<int> vec = vec_input;
		int i; int n = vec.size();
		for  (i = 0;i < n; i++)
		{
			vec[i] = ((vec[i]%md)+md)%md;
		}
		while (!vec.empty() && vec.back() == 0)vec.pop_back();
		if (vec.empty()) res->_ds_hs.push_back(0);
		else res->_ds_hs = vec;
	}
	return res;
}

 DathucInt * powDaThucInt(DathucInt *& dt, int bac)
{
	return nullptr;
}

 void freeDaThucInt(DathucInt *& Dt)
{
	if (Dt) {
		free(Dt);
	}
}

DathucInt *CongDaThucTheoModul(DathucInt *dt1,DathucInt *dt2)
{
	vector<int> vec;
	if (dt1->_modul_da_thuc != dt2->_modul_da_thuc) return nullptr;
	int bac_dt1 = dt1->_ds_hs.size()-1;
	int bac_dt2 = dt2->_ds_hs.size()-1;
	int md = dt2->_modul_da_thuc;
	if (bac_dt1 > bac_dt2) {
		vec = dt1->_ds_hs;
		int i; for (i = 0; i < bac_dt2 + 1; i++)
			vec[i] += dt2->_ds_hs[i];
	}
	else {
		vec = dt2->_ds_hs;
		int i; for (i = 0; i < bac_dt1 + 1; i++)
			vec[i] += dt1->_ds_hs[i];
	}
	DathucInt *res = KhoiTaoDathuc(vec, md);
	return res;
}
DathucInt * TruDaThucTheoModul(DathucInt *dt1, DathucInt *dt2)
{
	vector<int> vec;
	if (dt1->_modul_da_thuc != dt2->_modul_da_thuc) return nullptr;
	int bac_dt1 = dt1->_ds_hs.size() - 1;
	int bac_dt2 = dt2->_ds_hs.size() - 1;
	//int bac_max = max(bac_dt1, bac_dt2);
	int md = dt2->_modul_da_thuc;
	if (bac_dt1 >= bac_dt2) {
		vec = dt1->_ds_hs;
		int i; for (i = 0; i < bac_dt2 + 1; i++)
			vec[i] -= dt2->_ds_hs[i];
	}
	else {
		vec = dt1->_ds_hs;
		int i; for (i = 0; i < bac_dt1 + 1; i++)
			vec[i] = dt1->_ds_hs[i] - vec[i];
		for (i = bac_dt1 + 1; i < bac_dt2 + 1; i++)
			vec[i] *= -1;
	}
	DathucInt *res = KhoiTaoDathuc(vec, md);
	return res;
}
DathucInt *NhanDaThucTheoModul_X(DathucInt *&dt1, int x) {
		vector<int> vec = dt1->_ds_hs;
		int sz = vec.size();
		int i; for (i = 0; i < sz; vec[i] *= x, i++);
		dt1 = KhoiTaoDathuc(vec, dt1->_modul_da_thuc);
		return dt1;
}
DathucInt *NhanDaThucTheoModul(DathucInt *dt1, DathucInt *dt2) {
	int md = dt1->_modul_da_thuc; if (md != dt2->_modul_da_thuc) exit(-1);
	vector<int> vec1 = dt1->_ds_hs;
	vector<int> vec2 = dt2->_ds_hs;
	vector<int> res(0);
	vector<int> vec_phu;
	int sz1 = vec1.size();
	int sz2 = vec2.size();
	int j,k;
	//vector<int>::iterator itr;
		for (j = 0; j < sz2; j++)
		{
			vec_phu = NhanVector(vec1,vec2[j]);
			for (k = 0; k < j; k++) {
				vec_phu.insert(vec_phu.begin(), 0);
			}
			res = CongVector(res, vec_phu);
		}
	dt1 = KhoiTaoDathuc(res, dt1->_modul_da_thuc);
	return dt1;
}
DathucInt *ChiaDaThucLayPhanDu(DathucInt *dt1, DathucInt *dt2) {
	if (dt1->_modul_da_thuc != dt2->_modul_da_thuc) exit(-1);
	vector<int> vec_bc = dt2->_ds_hs;
	int i, j, k, hs, back_vec_bc = vec_bc.back(), back_vec_chia; int sz = vec_bc.size();
	int m, md = dt1->_modul_da_thuc;
	//int ktra = -1;
	vector<int> vec_chia = dt1->_ds_hs;
	int bac = dt1->_ds_hs.size() - 1;
	k = bac + 1 - sz;
	while (k >= 0)
	{
		back_vec_chia = vec_chia.back();
		//tim hs
		for (j = 1; j < md; j++) {
			if (((back_vec_bc*j) - back_vec_chia) % md == 0) {
				hs = j;
				break;
			}
		}

		for (i = 0; i < sz; i++) {
			m = vec_chia[i + k] - vec_bc[i] * hs;
			m = ((m%md) + md) % md;
			vec_chia[i + k] = m;
		}
		while (!vec_chia.empty() && vec_chia.back() == 0)
		{
			vec_chia.pop_back();
		}
		if (vec_chia.empty()) bac = 0;
		else bac = vec_chia.size() - 1;
		k = bac + 1 - sz;
	}
	while (!vec_chia.empty() && vec_chia.back() % md == 0)
		vec_chia.pop_back();
	if (vec_chia.empty()) {
		vec_chia.push_back(0);
		DathucInt *dt_res = KhoiTaoDathuc(vec_chia, md);
		return dt_res;
	}
	else {
		DathucInt *dt_res = KhoiTaoDathuc(vec_chia, md);
		return dt_res;
	}
	
}
bool ChiaDaThucLayThuong(DathucInt *dt1, DathucInt *dt2, DathucInt *&dt_res){
	if (dt1->_modul_da_thuc != dt2->_modul_da_thuc) exit(-1);
	if (dt1->_ds_hs.size() < dt2->_ds_hs.size()) {
		*dt_res = *dt1;
		return false;
	}
	int do_lech_bac = dt1->_ds_hs.size() - dt2->_ds_hs.size();
	vector<int> vec_bc = dt2->_ds_hs;
	vector<int> v_res(do_lech_bac+1);
	int i, j, k, hs, back_vec_bc = vec_bc.back(), back_vec_chia; int sz = vec_bc.size();
	int m, md = dt1->_modul_da_thuc;
	//int ktra = -1;
	vector<int> vec_chia = dt1->_ds_hs;
	int bac = dt1->_ds_hs.size() - 1;
	k = bac + 1 - sz;
	while (k >= 0)
	{
		back_vec_chia = vec_chia.back();
		//tim hs
		for (j = 1; j < md; j++) {
			if (((back_vec_bc*j) - back_vec_chia) % md == 0) {
				hs = j;
				break;
			}
		}
		v_res[do_lech_bac] = hs;
		for (i = 0; i < sz; i++) {
			m = vec_chia[i + k] - vec_bc[i] * hs;
			m = ((m%md) + md) % md;
			vec_chia[i + k] = m;
		}
		while (!vec_chia.empty() && vec_chia.back() == 0)
		{
			vec_chia.pop_back();
		}
		if (vec_chia.empty()) bac = 0;
		else bac = vec_chia.size() - 1;
		k = bac + 1 - sz;
		do_lech_bac = vec_chia.size() - vec_bc.size();
	}
	/*do_lech_bac -= (v_res.size()-1);
	for (i=0; i < do_lech_bac; i++)
		v_res.push_back(0);
	reverse(v_res.begin(), v_res.end());*/
	while (!vec_chia.empty() && vec_chia.back() % md == 0)
		vec_chia.pop_back();
	dt_res = KhoiTaoDathuc(v_res,md);
	if (vec_chia.empty()) {
		//dt_res = KhoiTaoDathuc(vec_chia, md);
		return true;
	}
	return false;
}

vector<key_HeSoDaThuc> PhanTichDaThuc(vector<int> vec_hs, int md) {
	ArrayHsNgto = new vector<int>[23];
	KhoiTaoMap();
	vector<key_HeSoDaThuc> resul;
	key_HeSoDaThuc key;
	int bac = vec_hs.size() - 1;
	int i=0, sl=0,ktra=0;
	DathucInt *dt1=nullptr; DathucInt *dt2=nullptr; DathucInt *dt_res=nullptr;
	dt1 = KhoiTaoDathuc(vec_hs, md);
	//dt2 = KhoiTaoDathuc(ArrayHsNgto[i], md);
	//ktra = ArrayHsNgto[i].size()-1;
	while (bac) {
		sl = 0;
		dt2 = KhoiTaoDathuc(ArrayHsNgto[i], md);
		while(ChiaDaThucLayThuong(dt1, dt2, dt_res)) {
			*dt1 = *dt_res;
			sl++;
		}
		if (sl) {
			bac = dt1->_ds_hs.size() - 1;
			key.soluong = sl;
			key.HeSoDaThuc = ArrayHsNgto[i];
			resul.push_back(key);
		}
		i++; //ktra = ArrayHsNgto[i].size() - 1;
	}
	return resul;
}