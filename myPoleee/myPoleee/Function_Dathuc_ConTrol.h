#pragma once
#include "Header_pole.h"
//static int ArrayNguyenTo[]{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
struct CapGiaTri
{
	int key;
	int so_luong;
};
vector<CapGiaTri> phanTichSo(int N);
bool kiemtra(vector<int>vec_bc, int bac, int md);
int timBac(vector<int>vec, int md);
int TinhGiaTriHamUU(const int &n);
vector<CapGiaTri> phanTichSo_p2(int N);

void KhoiTaoArrayNgyenTo(int n);
int TinhGiaTriHamUU_2(const int &N);