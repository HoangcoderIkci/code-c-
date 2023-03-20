#pragma once
#include "Header_pole.h"
struct getU_V
{
	int _u_int;
	int _v_int;
};
vector<vector<int> > getPhanDuVaQ(const int&,const int&);
getU_V Tim_U_V_int(const int&, const int&);
int getU(const vector<vector<int> >&);
int getV(const vector<vector<int> >&);
int getUCLN(const int&a, const int&b);
int getBacElem(const int&a, const int&b);
