#include "Function_Dathuc_ConTrol.h"
//#define MAXNN 1000005
static vector<int> ArrayNguyenTo;

static void unset(unsigned int &num, int bit) {
	num &= ~(1 << bit);
}
/*
static bool is_set(unsigned int x, int pos) {
	return (x & (1 << pos)) != 0;
}*/
//Hàm tìm t?t c? các s? nguyên t? trong kho?ng [0, n]
void KhoiTaoArrayNgyenTo(int n) {
	unsigned int *is_prime2 = new unsigned int[(n >> 5) + 1];
	//Tính s? byte c?n ?? l?u tr?ng thái c?a các s? (prime/not prime)
	int size = (n >> 5) + 1;
	//Kh?i t?o t?t c? các s? ??u là s? nguyên t?
	memset(is_prime2, 0xff, size * sizeof(unsigned int));
	//Không có s? 0 và 1 là s? nguyên t?
	unset(is_prime2[0], 0);
	unset(is_prime2[1], 1);
	//Duy?t qua t?t c? các s? trong kho?ng [2, n]
	for (int i = 2; i <= n; i++) {
		//N?u s? i là s? nguyên t?
		if (is_prime2[i >> 5] & ( 1 << (i & 31))) {
			//Thêm i vào danh sách các s? nguyên t?
			ArrayNguyenTo.push_back(i);
			//Tìm các b?i c?a i trong kho?ng [2*i, n] và ?ánh d?u chúng không ph?i là s? nguyên t?
			for (int j = 2 * i; j <= n; j += i)
				unset(is_prime2[j >> 5], j & 31);
		}
	}
	for (int t = 0; t < ArrayNguyenTo.size(); t++)
		cout << ArrayNguyenTo[t] << '\t';
	delete[]is_prime2;
}


vector<CapGiaTri> phanTichSo(int N) {
	KhoiTaoArrayNgyenTo(N);
	vector<CapGiaTri> vec_res;
	//CapGiaTri cap_gt;
	int n = N; int i = 0, k = 0;
	while (n > 1)
	{
		while (n % ArrayNguyenTo[i] == 0) {
				n /= ArrayNguyenTo[i]; k++;
			}
		if(k) vec_res.push_back({ ArrayNguyenTo[i],k});
		++i; k = 0;
	}
	return vec_res;
}

bool kiemtra(vector<int>vec_bc, int bac, int md) {
	int i, j, k, hs, back_vec_bc = vec_bc.back(), back_vec_chia; int sz = vec_bc.size();
	int m;
	int ktra = -1;
	vector<int> vec_chia(bac + 1, 0);
	vec_chia[bac] = 1;
	k = bac + 1 - sz;
	while (k >= 0)
	{
		back_vec_chia = vec_chia.back();
		//tim hs
		for (j = 1; j < md; j++) {
			if (((back_vec_bc*j) - back_vec_chia) % md == 0) {
				hs = j;
				break;
			}
		}

		for (i = 0; i < sz; i++) {
			m = vec_chia[i + k] - vec_bc[i] * hs;
			m = ((m%md) + md) % md;
			vec_chia[i + k] = m;
			if (m != 0) ktra = i + 1;
		}
		k -= sz - ktra;
		for (i = 0; i < sz - ktra; i++)
			vec_chia.pop_back();
	}
	if (vec_chia.empty() || vec_chia.size() != 1) return false;
	if (vec_chia[0] == 1) return true;
	return false;
}
int timBac(vector<int>vec, int md) {
	int i, sz, bac, j = 0, res = 1;
	int n;
	while (!vec.empty() && vec.back() % md == 0) {
		vec.pop_back();
	}
	if (vec.empty()) return 0;
	sz = vec.size(); 
	n = (int)pow(md, sz - 1) - 1;
	vector<CapGiaTri> vec_res;
	vec_res = phanTichSo(n);
	int size_vr = vec_res.size();
	for (i = 0, j = 1; i < size_vr; i++) {
		bac = n / pow(vec_res[i].key, j);
		while (kiemtra(vec, bac, md)) {
			j++;
			bac = n / pow(vec_res[i].key, j);
		}
		vec_res[i].so_luong -= j - 1;
		j = 1;
	}
	for (i = 0; i < size_vr; i++)
		res *= pow(vec_res[i].key, vec_res[i].so_luong);
	return res;
}


int TinhGiaTriHamUU_2(const int &N) {
	KhoiTaoArrayNgyenTo(N);
	int n = N;
	if (n <= 0) return -17;
	if (n == 1) return 1;
	int result = -1;
	int i = 0;
	while (n > 1 && i < ArrayNguyenTo.size() && ArrayNguyenTo[i] <= n) {
		int k = 0;
		while (n % ArrayNguyenTo[i] == 0) {
			k++;
			if (k == 2) return 0;
			n /= ArrayNguyenTo[i];
		}
		if (k % 2 != 0) result = -result;
		i++;
	}
	if (n > 1) return 0;
	return result;
}

