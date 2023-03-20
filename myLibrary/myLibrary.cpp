#include "myLibrary.h"

bool checkStrongPassword(string s) {
	string p = "!@#$%^&*()-+";
	if (s.size() < 6) return false;
	bool check_1 = false;
	bool check_2 = false;
	bool check_3 = false;
	bool check_4 = false;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'S') check_1 = true;

		if (s[i] >= 'a'&&s[i] <= 's') check_2 = true;

		if (s[i] >= 48 && s[i] <= 57) check_3 = true;

		if (p.find(s[i] != -1)) check_4 = true;

	}
	return check_1&&check_2&&check_3&&check_4;
}
string amendTheSentence(string s)
{
	string res = "";
	if (s[0] >= 'A'&&s[0] <= 'Z') s[0] += 32;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			res = res + ' ' + char(s[i] + 32);
		}
		else
		{
			res += s[i];
		}
	}
	return res;
}
bool checkPalindrome(string s)
{
	int length = s.length() - 1;
	for (int i = 0; i < length / 2; i++)
	{
		if (s[i] != s[length - i]) return false;
	}
	return true;
}
// xóa kho?ng tr?ng ? ??u, ? cu?i và không có 2 kho?ng tr?ng li?n nhau
string xoaKhoangTrang(string s) {
	while (s[0] == ' ')
	{
		s.erase(0, 1);
	}
	while (s[s.length() - 1] == ' ')
	{
		s.erase(s.length() - 1, 1);
	}
	while (s.find("  ") != -1)
	{
		s.erase(s.find("  "), 1);
	}
	return s;
}             
void tinhBacCuaHam(int n, int m, bool *a) {
	a[n] = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	for (int i = n; i >= m; i--)
	{
		if (a[i]) {
			a[i] = 0;
			(a[i - 2]) ? a[i - 2] = false : a[i - 2] = true;
			(a[i - 3]) ? a[i - 3] = false : a[i - 3] = true;
			(a[i - 7]) ? a[i - 7] = false : a[i - 7] = true;
			(a[i - 8]) ? a[i - 8] = false : a[i - 8] = true;

		}

	}
	for (int i = 0; i <= m; i++)
	{
		cout << a[i] << '\n';
	}
};
void tinhBacCuaHam(int n, int m, int *a, int modul) {
	a[n] = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	for (int i = n; i >= m; i--)
	{
		if (a[i] == 1) {
			a[i] = 0;
			a[i - 2] = (a[i - 2] + 2) % modul;
			/*a[i - 3] = (a[i - 3] + 2) % modul;
			a[i - 5] = (a[i - 5] + 1) % modul;
			a[i - 6] = (a[i - 6] + 2) % modul;*/
		}
		if (a[i] == 2) {
			a[i] = 0;
			a[i - 2] = (a[i - 2] + 1) % modul;
		}

	}
	for (int i = 0; i <= m; i++)
	{
		cout << a[i] << '\n';
	}
};
int sangSoNguyenTo(int n) {
	int s = 0;
	map<int, bool>m;
	loop(i, 2, n + 1) {
		m.insert({ i, true });
	}
	for (int i = 2; i*i <= n; i++) {
		if (m[i])
			for (int j = i; i*j <= n; j++)
			{
				m.erase(i*j);
			}
	}
	for (auto x = m.begin(); x != m.end(); x++)
	{
		s += x->first;
	}
	return s;
}
int tinhTongCacSoNGuyenTo();
long long numberZeroDigits(long long n)
{
	long long d = 0, k = 5;
	while (k <= n)
	{
		d += n / k;
		k *= 5;
	}
	return d;
}
int soLanXuatHienKtu(string str,char ch) {
	int counT = 0;
	while (str.find(ch)!=-1)
	{
		counT++;
		str.erase(str.find(ch), 1);
	}
	return counT;
};
bool tongso(string str) {
	loop(i, 0, str.size()) {
		if ((i + 1) % 2 != (str[i] - '0') % 2)return false;
	}return true;
}