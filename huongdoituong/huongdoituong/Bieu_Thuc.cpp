#include "Bieu_Thuc.h"

Bieu_Thuc::Bieu_Thuc()
{
}


Bieu_Thuc::~Bieu_Thuc()
{
	cout << "huy bo\n";
	cout << "huy bo\n";
}
Bieu_Thuc::Bieu_Thuc(vector<int> ds)
{
	while (ds.back() == 0)
		ds.pop_back();
	if (ds.empty()) {
		ds_he_so = { 0 };
		he_so_gia = 0;
		He_so_tre = 0;
		bac_cua_ham = -1;
	}
	else {
		ds_he_so = ds;
		he_so_gia = ds.back();
		He_so_tre = ds.front();
		bac_cua_ham = ds.size() - 1;
	}

}
void Bieu_Thuc::display()
{
	printf("\nbac cua ham: %i", this->bac_cua_ham);
	printf("\nhe_so_gia: %i", this->he_so_gia);
	printf("\nHe_so_tre: %i\n", this->He_so_tre);
	loop(i, 0, ds_he_so.size())
		printf("a[%d]: %d  ", i, ds_he_so[i]);

}
Bieu_Thuc operator+(const Bieu_Thuc &d1, const Bieu_Thuc &d2) {
	vector<int> res = d1.ds_he_so;
	res = res + d2.ds_he_so;
	Bieu_Thuc ressul(res);
	return ressul;
}