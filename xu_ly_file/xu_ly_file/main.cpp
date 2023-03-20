#include "myHeader.h"
#define  MAXX 20;
int n;
int Bool[20] = { 0 };//?ánh d?u ch?a có ph?n t? nào s? d?ng h?t
int A[20];//L?u hoán v? vào m?ng A

void xuat() {
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		//Ki?m tra n?u ph?n t? ch?a ???c ch?n thì s? ?ánh d?u
		if (!Bool[i]) {
			A[k] = i; // L?u m?t ph?n t? vào hoán v?
			Bool[i] = 1;//?ánh d?u ?ã dùng
			if (k == n)//Ki?m tra n?u ?ã ch?a m?t hoán v? thì xu?t
				xuat();
			else
				Try(k + 1);
			Bool[i] = 0;
		}
	}
}

int main() {
	cout << "Mhap n: ";
	cin >> n;
	Try(1);
}