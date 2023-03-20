#include "myDaThuc.h"

/*
vector<vector<myDaThuc<int> > > Tim_Ucln_Dathuc(myDaThuc<int> d1, myDaThuc<int> d2, int modul);
vector<myDaThuc<int> > Get_U_and_V(myDaThuc<int> d1, myDaThuc<int> d2, int modul);
vector<myDaThuc<int> > Get_V(myDaThuc<int> d1, myDaThuc<int> d2, int modul);
void swapdt(myDaThuc<int>& d1, myDaThuc<int> &d2);*/
int tong(int a) {
	int b = a;
	int sum = 0;
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	a = b;
	return sum;
}
bool cmp(int a, int b) {
	return (tong(a) < tong(b)) ? true : false;
}
int main()
{
	int fomat_r =6, fomat_cl = 6;
		matrix<int> a(fomat_r, fomat_cl);
	a.getMatrixFromFile("input.txt", 0);
	matrix<int> b(fomat_r, fomat_cl);
	b.getMatrixFromFile("input.txt", 1);
	matrix<int> c(fomat_r, fomat_cl);
	c.getMatrixFromFile("input.txt", 2);
	cout << "thu lai C^-1*A*C : \n"<<(a*b*c) % 5;

	/*matrix<int> mt(fomat_r, fomat_cl);
	mt.getMatrixFromFile("dshs.txt", 0);
	myDaThuc<int> d1;
	fstream f;
	d1.Get_dt(0);
	cout << (d1(mt))%5;*/
	

	//cout << *min_element(vec.begin(), vec.end()) << '\n';
	system("pause");
	return 0;
}
/*
vector<vector<myDaThuc<int> > > Tim_Ucln_Dathuc(myDaThuc<int> d1, myDaThuc<int> d2, int modul) {
	vector <myDaThuc> temp(2);
	temp[0] = d1; temp[1] = d2;
	if (d1.bac_dathuc < d2.bac_dathuc)
	{
		swapdt(d1, d2);
	}
	vector<vector<myDaThuc> >vec_res(2);
	Dathuc phandu;
	Dathuc thuong;
	phandu = ChiaDathucTheoModulGet_phan_du(d1, d2, thuong, modul);
	while (phandu.bac_dathuc > 0) {
		phandu = ChiaDathucTheoModulGet_phan_du(d1, d2, thuong, modul);
		vec_res[0].push_back(phandu);
		vec_res[1].push_back(thuong);
		d1 = d2;
		d2 = phandu;
	}
	vec_res[0].pop_back();
	vec_res[1].pop_back();
	d1 = temp[0]; d2 = temp[1];
	return vec_res;
}
vector<myDaThuc<int> > Get_U_and_V(myDaThuc<int> d1, myDaThuc<int> d2, int modul) {
	vector<vector<Dathuc> >ds = Tim_Ucln_Dathuc(d1, d2, modul);
	Dathuc nul({ 0 });
	ds[1].insert(ds[1].begin(), nul);
	ds.resize(3);
	ds[2].resize(ds[1].size());
	(ds[2][0])({ 0 });
	(ds[2][1])({ 1 });
	loop(i, 2, ds[1].size()) {
		ds[2][i] = ds[2][i - 2] - ds[2][i - 1] * ds[1][i];
	}
	vector<Dathuc> res;
	res.push_back(ds[2].back());
	return res;
}
vector<myDaThuc<int> > Get_V(myDaThuc<int> d1, myDaThuc<int> d2, int modul) {
	vector<vector<Dathuc> >ds = Tim_Ucln_Dathuc(d1, d2, modul);
	Dathuc nul({ 0 });
	ds[1].insert(ds[1].begin(), nul);
	ds.resize(3);
	ds[2].resize(ds[1].size());
	(ds[2][0])({ 1 });
	ds[2][1] = ds[1][1] * (-1);
	loop(i, 2, ds[1].size()) {
		ds[2][i] = ds[2][i - 2] - ds[2][i - 1] * ds[1][i];
	}
	vector<Dathuc> res;
	res.push_back(ds[2].back());
	return res;
}
void swapdt(myDaThuc<int>& d1, myDaThuc<int> &d2) {
	Dathuc temp = d1;
	d1 = d2;
	d2 = temp;
}*/
