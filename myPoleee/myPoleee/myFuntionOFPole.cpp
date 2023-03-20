#include "myFuntionOFPole.h"

vector<vector<int> > getPhanDuVaQ(const int& i_first, const int& i_second) {
	vector<vector<int> >res(2);
	if (i_first == 0) {
		res[0].push_back(i_second);
		res[1].push_back(0);
		cout << "ERROR!!! co mot so bang 0 trong phep chia tim u v.\n";
		system("pause");
		return res;
	}
	if (i_second == 0) {
		res[0].push_back(i_first);
		res[1].push_back(0);
		cout << "ERROR!!! co mot so bang 0 trong phep chia tim u v.\n";
		system("pause");
		return res;
	}
	int a, b, thuong, du;
	if (i_first > i_second) {
		a = i_first, b = i_second;
	}else{ b = i_first, a = i_second; }
	do 
	{
		thuong = a / b;
		du = a%b;
		a = b;
		b = du;
		res[0].push_back(du);
		res[1].push_back(thuong);
	} while (du);
	res[0].pop_back();
	res[1].pop_back();
	return res;
}
getU_V Tim_U_V_int(const int& a, const int& b) {
	getU_V res;
	vector<vector<int> >vec;
		if (a == 0 || b == 0) {
			if (a == 0) {
				res._u_int = 0; res._v_int = 1;
			}
			else {
				res._u_int = 1; res._v_int = 0;
			}
			return res;
		}
		if (a%b == 0) {
			res._u_int = 0; res._v_int = 1;
			return res;
		}
		if (b%a == 0) {
			res._u_int = 1; res._v_int = 0;
			return res;
		}
	int i_f = a, i_sc = b;
	vec=getPhanDuVaQ(a, b);
	if (a > b) {
		res._u_int = getU(vec);
		res._v_int = getV(vec);
	}
	else {
		res._u_int = getV(vec);
		res._v_int = getU(vec);
	}
	return res;
}
int getU(const vector<vector<int> >&vec) {
	vector<int> phu(vec[1].begin(), vec[1].end());
	phu.insert(phu.begin(),0);
	vector<int> u(phu.size());
	u[0] = 0;
	u[1] = 1;
	loop(i, 2, (signed)phu.size()) {
		u[i] = u[i-2] - u[i-1] * phu[i];
	}
	return u.back();
}
int getV(const vector<vector<int> >&vec) {
	vector<int> phu(vec[1].begin(), vec[1].end());
	phu.insert(phu.begin(), 0);
	vector<int> u(phu.size());
	u[0] = 1;
	u[1] = -phu[1];
	loop(i, 2, (signed)phu.size()) {
		u[i] = u[i - 2] - u[i - 1] * phu[i];
	}
	return u.back();
}
int getUCLN(const int&a, const int&b) {
	if (a == 0 || b == 0) {
		return (a == 0) ? b : a;
	}
	if (a%b == 0) return b;
	if (b%a == 0) return a;
	vector<vector<int> >vec;
	int i_f = a, i_sc = b;
	vec = getPhanDuVaQ(a, b);
	return vec[0].back();
}
int getBacElem(const int&gt, const int&md) {
	loop(i, 1, md) {
		if ( ((int)pow(gt,i)) % md == 1) {
			return i;
		}
	}
	return -17;
}