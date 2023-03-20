#pragma once
#include "Header.h"
#include "myFunction.h"
class ELEMENT_PLE
{
public:
	int modul_el=-17; // pole default -17.
	int elemt=-17;
	int elemt_phan_dien=-17;
	int oprat=-17;      // oprat cua 0 la 0.
	ELEMENT_PLE();
	// khoi tao co modul, nghich dao, phan dien.
	ELEMENT_PLE(int, int);
	// khoi tao co modul, nghich dao, phan dien. chu y!!! sau khi da khai bao.
	ELEMENT_PLE ELEMENT_PLE::operator()(const int &a,const int&m);
	// cong theo modul va nhan
	ELEMENT_PLE operator+(const ELEMENT_PLE&); 
	ELEMENT_PLE operator-(const ELEMENT_PLE&);
	ELEMENT_PLE operator*(const ELEMENT_PLE&);
	friend ostream& operator<<(ostream &, const ELEMENT_PLE&); // in ra element.
	friend istream& operator>>(istream &, ELEMENT_PLE&); // nhap element.
};

class POLE : public ELEMENT_PLE
{
protected:

public:
	POLE(int);
	int mdul;
	vector<ELEMENT_PLE> ds_phan_tu;
	ELEMENT_PLE operator[](const int&);
	friend ostream& operator<<(ostream &out, const POLE&);
	//friend istream& operator>>(istream &in,POLE&);
};
