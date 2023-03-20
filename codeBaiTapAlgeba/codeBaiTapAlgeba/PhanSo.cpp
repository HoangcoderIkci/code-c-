#include "PhanSo.h"


PhanSo::PhanSo()
	:_tu_so(0), _mau_so(1) {}
PhanSo::PhanSo(int ts, int ms) {
	if (ms == 0) exit(-1);
	else {
		if (ms < 0) {
			ms = ms * (-1);
			ts = ts * (-1);
		}
		int uc;
		uc = Ucln(ts, ms);
		_tu_so = ts / uc;
		_mau_so = ms / uc;
	}
}

PhanSo::PhanSo(int ts)
{
	_tu_so = ts;
	_mau_so = 1;
}
static int Ucln(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0) return abs(b);
	else if (b == 0) return abs(a);
	else {
		int temp;
		while (b)
		{
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}

}
static int bcnn(int a, int b) {
	if (a == 0 || b == 0) return 0;
	a = abs(a); b = abs(b);
	return (a*b) / Ucln(a, b);
}