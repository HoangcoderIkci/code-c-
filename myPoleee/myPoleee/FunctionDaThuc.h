#pragma once
#include "Header_pole.h"

struct DathucInt {
	vector<int> _ds_hs;
	int _modul_da_thuc;
};
struct key_HeSoDaThuc
{
	int soluong;
	vector<int> HeSoDaThuc;
};
vector<key_HeSoDaThuc> PhanTichDaThuc(vector<int> vec_hs, int md);
 vector<int> * checkMang();
 vector<int> CongVector(vector<int>v1, vector<int>v2);
 vector<int> NhanVector(vector<int>v1, int x);
 DathucInt *KhoiTaoDathucDefault();
 DathucInt *KhoiTaoDathuc(const vector<int> &vec, const int &md);
 DathucInt *powDaThucInt(DathucInt *&dt, int bac);
 void freeDaThucInt(DathucInt *&Dt);
 DathucInt * CongDaThucTheoModul(DathucInt *dt1,DathucInt *dt2);
 DathucInt * TruDaThucTheoModul(DathucInt *dt1, DathucInt *dt2);
 DathucInt * NhanDaThucTheoModul(DathucInt *dt1, DathucInt *dt2);
 DathucInt *NhanDaThucTheoModul_X(DathucInt *&dt1, int x);
 DathucInt *ChiaDaThucLayPhanDu(DathucInt *dt1, DathucInt *dt2);
 bool CheckChiaHet(vector<int> vec1, vector<int> vec2, int md);
 bool ChiaDaThucLayThuong(DathucInt *dt1, DathucInt *dt2, DathucInt *&dt_res);
 bool checkDaTHucDonG(vector<int> Dt, const int &md);