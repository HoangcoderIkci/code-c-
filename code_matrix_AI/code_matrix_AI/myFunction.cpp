#include "myFunction.h"

int poww_of_int(const int&t1, const int& t2) {
	if (t1 == 0) return 0;
	if (t2 == 0) return 1;
	int res = 1;
	loop(i, 0, t2) {
		res = res*t1;
	}
	return res;
}
vector<vector<int> > get_UCLN_int(const int& a, const int& b) {
	int ptu_l, ptu_n;
	if (a > b) {
		ptu_l = a, ptu_n = b;
	}
	else {
		ptu_l = b; ptu_n = a;
	}
	int du, thuong;
	du = ptu_l%ptu_n; thuong = ptu_l / ptu_n;
	vector<vector<int> >res(3);
	res[1].push_back(du);
	res[2].push_back(thuong);
	while (du)
	{
		ptu_l = ptu_n;
		ptu_n = du;
		thuong = du = ptu_l%ptu_n; thuong = ptu_l / ptu_n;
		res[1].push_back(du);
		res[2].push_back(thuong);
	}
	res[1].pop_back();
	res[2].pop_back();
	res[0].push_back(res[1].back());
	return res;
}
int get_v(const int& a, const int& b) {
	if (a == 0 || b == 0) {
		cout << "a hoac b=0 ERROR!!\n";
		system("pause"); exit(1);
	}
	int sl, sn;
	if (a > b){ sl = a, sn = b;}
	else {sl = b, sn = a;}
	vector<vector<int> >vec = get_UCLN_int(sl, sn);
	vec[2].insert(vec[2].begin(), 0);
	vector<int> res(vec[2].size()); res[0]=1;
	res[1]=vec[2][1] * (-1);
	loop(i, 2, res.size()) {
		res[i] = res[i - 2] - res[i - 1] * vec[2][i];
	}
	return res.back();
}
int get_u(const int& a, const int& b) {
	if (a == 0 || b == 0) {
		cout << "a hoac b=0 ERROR!!\n";
		system("pause"); exit(1);
	}
	int sl, sn;
	if (a > b) { sl = a, sn = b; }
	else { sl = b, sn = a; }
	vector<vector<int> >vec = get_UCLN_int(sl, sn);
	vec[2].insert(vec[2].begin(), 0);
	vector<int> res(vec[2].size()); res[0] = 0;
	res[1] = 1;
	loop(i, 2, res.size()) {
		res[i] = res[i - 2] - res[i - 1] * vec[2][i];
	}
	return res.back();
}
int TimBacElTrongZn(const int& i_v, const int&md) {
	if (i_v == 0) return -17;
	int x;
	for (int i = 1;; i++)
	{
	x = poww_of_int(i_v, i) % (md);
	if(x==1) return i;
	}
	return -17;
}
