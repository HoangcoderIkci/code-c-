#pragma once
#include "funtion.h"
class Bieu_Thuc
{
public:
	Bieu_Thuc();
	Bieu_Thuc(vector<int> ds);
	friend Bieu_Thuc operator+(const Bieu_Thuc &d1, const Bieu_Thuc &d2);
	void display();
	~Bieu_Thuc();
private:
	int he_so_gia;
	int He_so_tre;
	int bac_cua_ham;
	vector<int> ds_he_so;
};
