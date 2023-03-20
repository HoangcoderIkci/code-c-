#include "myHeader.h"
void doc_file(DsPhan_so& ds, ifstream &infile) {
	infile >> ds.n;
	char ch;
	for (int i = 0; i < ds.n; i++)
	{
		infile >> ds.ds_ps[i].Tu_so;
		infile >> ch;
		infile >> ds.ds_ps[i].Mau_so;
	}
}
void ghi_file(DsPhan_so&, ofstream &);