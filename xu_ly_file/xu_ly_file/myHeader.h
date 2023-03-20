#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct PhanSo
{
	int Tu_so;
	int Mau_so;
};
struct DsPhan_so {
	int n;
	PhanSo ds_ps[15];
};
void doc_file(DsPhan_so&, ifstream &);
void ghi_file(DsPhan_so&, ofstream &);