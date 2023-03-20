#pragma once
#include "ELEMENTOFPOLE.h"
template<class T = ELEMENTOFPOLE>
class MYDATHUC
{
public:
	T _modul_dathuc;
	int _bac_da_thuc = -17;
	T _hs_gia;
	T _hs_tre;
	MYDATHUC() {};
	/*vector<T> _ds_hs_of_dt;
	MYDATHUC(const vector<T>&);*/
	/*friend MYDATHUC<T> operator+(const MYDATHUC<T>&dt_1, const MYDATHUC<T& dt_2) {
		int bac_max;
		if (dt_1._bac_da_thuc > dt_2._bac_da_thuc) {
			vector<T> v= dt_1._ds_hs_of_dt;
			loop(i, 0, dt_2._ds_hs_of_dt.size()) {
				v[i] = v[i] + dt_2._ds_hs_of_dt[i];
			}
			MYDATHUC<T, md_of_dt> res(v);
			return res;
		}
		else {
			vector<T> v = dt_2._ds_hs_of_dt;
			loop(i, 0, dt_1._ds_hs_of_dt.size()) {
				v[i] = v[i] + dt_1._ds_hs_of_dt[i];
			}
			MYDATHUC<T, md_of_dt> res(v);
			return res;
		}
	}*/
};


template<>
class MYDATHUC<ELEMENTOFPOLE<int> > {
public:
	int _modul_da_thuc;
	int _bac_da_thuc = -17;
	ELEMENTOFPOLE<int> _hs_gia;
	ELEMENTOFPOLE<int> _hs_tre;
	vector<ELEMENTOFPOLE<int> > _ds_hs_of_dt;
	MYDATHUC();
	MYDATHUC(const vector<ELEMENTOFPOLE<int> >  &vec, const int&md);
	MYDATHUC(const int&gt, const int&md);
	
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator+(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator-(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator*(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const ELEMENTOFPOLE<int> & el);
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator*(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > pow_dt(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&n);
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator/(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > operator%(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend bool operator==(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >&dt_2);
	friend bool operator!=(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >&dt_2);
	friend bool operator==(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&);
	friend bool operator!=(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&);
	friend vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > ChiaDaThucLayQ(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > getVofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > getUofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > getUCLNofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2);
	friend MYDATHUC<ELEMENTOFPOLE<int> > soSanhDaThucTheoModul(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_md);
	//friend MYDATHUC<ELEMENTOFPOLE<int> > getUCLNofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2)
	friend ostream& operator<<(ostream& out, const MYDATHUC<ELEMENTOFPOLE<int> >&dt);
	friend istream& operator>>(istream& in, MYDATHUC<ELEMENTOFPOLE<int> >&dt);
		// nhap da thuc.
	//friend class POLEOfDathuc;
};

inline MYDATHUC<ELEMENTOFPOLE<int> >::MYDATHUC() {};
inline MYDATHUC<ELEMENTOFPOLE<int> >::MYDATHUC(const vector<ELEMENTOFPOLE<int> >  &vec, const int&md) {
	this->_modul_da_thuc = md;
	vector<ELEMENTOFPOLE<int> > v = vec;
	while (!v.empty() && v.back() == 0)
	{
		v.pop_back();
	}
	if (v.empty()) {
		this->_ds_hs_of_dt.push_back(ELEMENTOFPOLE<int>(this->_modul_da_thuc, 0));
		this->_hs_gia = this->_ds_hs_of_dt.back();
		this->_hs_tre = this->_ds_hs_of_dt.front();
		this->_bac_da_thuc = -17;
	}
	else {
		this->_ds_hs_of_dt = v;
		this->_hs_gia = v.back();
		this->_hs_tre = v.front();
		this->_bac_da_thuc = v.size() - 1;
	}
}
inline MYDATHUC<ELEMENTOFPOLE<int> >::MYDATHUC(const int&gt, const int&md) {
	*this = MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(md,gt) }, md);
}
inline bool operator==(const MYDATHUC<ELEMENTOFPOLE<int>>& dt_1, const MYDATHUC<ELEMENTOFPOLE<int>>& dt_2)
{
	if (dt_2._modul_da_thuc != dt_1._modul_da_thuc) {
		cout << "#200ERROR!! 2 da thuc khac modul khong ss dc.\n"; system("pause"); exit(-17);
	}
	return dt_2._ds_hs_of_dt == dt_1._ds_hs_of_dt;
};
inline bool operator!=(const MYDATHUC<ELEMENTOFPOLE<int>>& dt_1, const MYDATHUC<ELEMENTOFPOLE<int>>& dt_2)
{
	if (dt_2._modul_da_thuc != dt_1._modul_da_thuc) {
		cout << "#200ERROR!! 2 da thuc khac modul khong ss dc.\n"; system("pause"); exit(-17);
	}
	return dt_2._ds_hs_of_dt != dt_1._ds_hs_of_dt;
};
inline bool operator==(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&a) {
	if (dt_1._bac_da_thuc == -17 && a == 0) return true;
	if (dt_1._bac_da_thuc == 0) return dt_1._hs_gia._gia_tri_elem == a;
	cout << "ERROR!! khong so sanh dc\n"; system("pause"); exit(-17);
};
inline bool operator!=(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&a) {
	if (dt_1._bac_da_thuc == -17 && a != 0) return true;
	if (dt_1._bac_da_thuc == 0) return dt_1._hs_gia._gia_tri_elem != a;
	cout << "ERROR!! khong so sanh dc\n"; system("pause"); exit(-17);
}

inline MYDATHUC<ELEMENTOFPOLE<int> > operator+(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "ERROR!! 2 da thuc khac modul;.\n";
		system("pause"); exit(-1);
	}
	//int bac_max;
	if (dt_1._bac_da_thuc > dt_2._bac_da_thuc) {
		vector<ELEMENTOFPOLE<int> > v = dt_1._ds_hs_of_dt;
		loop(i, 0, (signed)dt_2._ds_hs_of_dt.size()) {
			v[i] = v[i] + dt_2._ds_hs_of_dt[i];
		}
		MYDATHUC<ELEMENTOFPOLE<int> > res(v, dt_1._modul_da_thuc);
		return res;
	}
	else {
		vector<ELEMENTOFPOLE<int> > v = dt_2._ds_hs_of_dt;
		loop(i, 0, (signed)dt_1._ds_hs_of_dt.size()) {
			v[i] = v[i] + dt_1._ds_hs_of_dt[i];
		}
		MYDATHUC<ELEMENTOFPOLE<int> > res(v, dt_2._modul_da_thuc);
		return res;
	}
}   // + da thuc
inline MYDATHUC<ELEMENTOFPOLE<int> > operator-(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "ERROR!! 2 da thuc khac modul;.\n";
		system("pause"); exit(-1);
	}
	//int bac_max;
	if (dt_1._bac_da_thuc > dt_2._bac_da_thuc) {
		vector<ELEMENTOFPOLE<int> > v = dt_1._ds_hs_of_dt;
		loop(i, 0, (signed)dt_2._ds_hs_of_dt.size()) {
			v[i] = v[i] - dt_2._ds_hs_of_dt[i];
		}
		MYDATHUC<ELEMENTOFPOLE<int> > res(v, dt_1._modul_da_thuc);
		return res;
	}
	else {
		vector<ELEMENTOFPOLE<int> > v = dt_2._ds_hs_of_dt;
		ELEMENTOFPOLE<int> el(dt_1._modul_da_thuc, dt_1._modul_da_thuc - 1);
		loop(i, 0, (signed)dt_1._ds_hs_of_dt.size()) {
			v[i] = (v[i] - dt_1._ds_hs_of_dt[i])*el;
		}
		loop(i, dt_1._ds_hs_of_dt.size(), (signed)v.size()) {
			v[i] = v[i] * el;
		}
		MYDATHUC<ELEMENTOFPOLE<int> > res(v, dt_2._modul_da_thuc);
		return res;
	}
}
inline MYDATHUC<ELEMENTOFPOLE<int> > operator*(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const ELEMENTOFPOLE<int> & el) {
	if (dt_1._modul_da_thuc != el._modul) {
		cout << "da thuc khac modul elem !!! EEORR"; system("pause"); exit(-17);
	}
	vector<ELEMENTOFPOLE<int> > vec = dt_1._ds_hs_of_dt;
	vec = vec*el;
	MYDATHUC<ELEMENTOFPOLE<int> >res(vec, dt_1._modul_da_thuc);
	return res;
}
inline MYDATHUC<ELEMENTOFPOLE<int> > operator*(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "2 da thuc khac modul!!! EEORR"; system("pause"); exit(-17);
	}
	ELEMENTOFPOLE<int> nul(dt_1._modul_da_thuc, 0);
	vector<ELEMENTOFPOLE<int> >res(2, nul);
	loop(i, 0, (signed)dt_2._ds_hs_of_dt.size()) {
		if (dt_2._ds_hs_of_dt[i] == nul) continue;
		vector<ELEMENTOFPOLE<int> >phu = dt_1._ds_hs_of_dt;
		loop(j, 0, i) {
			phu.insert(phu.begin(), nul);
		}
		res = res + phu * dt_2._ds_hs_of_dt[i];
	}
	MYDATHUC<ELEMENTOFPOLE<int> > dt_res(res, dt_2._modul_da_thuc);
	return dt_res;
}
inline MYDATHUC<ELEMENTOFPOLE<int> > pow_dt(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const int&n) {
	if (n == 0) {
		return MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,1) }, dt_1._modul_da_thuc);
	}
	MYDATHUC<ELEMENTOFPOLE<int> >res = dt_1;
	loop(i, 1, n) {
		res = res * dt_1;
	}
	return res;
}
inline MYDATHUC<ELEMENTOFPOLE<int> > operator/(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "!!ERROR 2 da thuc khac modul#152"; system("pause"); exit(-17);
	}
	ELEMENTOFPOLE<int> nul(dt_1._modul_da_thuc, 0);
	if (dt_2._hs_gia == nul) {
		cout << "!!ERROR khong chia dc cho nul#152"; system("pause"); exit(-17);
	}
	if (dt_1._bac_da_thuc < dt_2._bac_da_thuc) return MYDATHUC<ELEMENTOFPOLE<int> >({ nul }, dt_1._modul_da_thuc);
	ELEMENTOFPOLE<int> hs;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_c = dt_1;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_bc = dt_2;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_x = MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,0),ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,1) }, dt_1._modul_da_thuc);
	MYDATHUC<ELEMENTOFPOLE<int> >res = MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,0) }, dt_1._modul_da_thuc);
	while (dt_c._bac_da_thuc >= dt_bc._bac_da_thuc)
	{
		hs = dt_c._hs_gia / dt_bc._hs_gia;
		res = res + (pow_dt(dt_x, dt_c._bac_da_thuc - dt_bc._bac_da_thuc) * hs);
		dt_c = dt_c - dt_bc * (pow_dt(dt_x, dt_c._bac_da_thuc - dt_bc._bac_da_thuc) * hs);
	}
	return res;
};
inline MYDATHUC<ELEMENTOFPOLE<int> > operator%(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "!!ERROR 2 da thuc khac modul#152"; system("pause"); exit(-17);
	}
	ELEMENTOFPOLE<int> nul(dt_1._modul_da_thuc, 0);
	if (dt_2._hs_gia == nul) {
		cout << "!!ERROR khong chia dc cho nul#152"; system("pause"); exit(-17);
	}
	if (dt_1._bac_da_thuc == -17) return dt_2;
	if (dt_1._bac_da_thuc < dt_2._bac_da_thuc) return dt_1;
	ELEMENTOFPOLE<int> hs;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_c = dt_1;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_bc = dt_2;
	MYDATHUC<ELEMENTOFPOLE<int> >dt_x = MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,0),ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,1) }, dt_1._modul_da_thuc);
	MYDATHUC<ELEMENTOFPOLE<int> >res = MYDATHUC<ELEMENTOFPOLE<int> >({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,0) }, dt_1._modul_da_thuc);
	while (dt_c._bac_da_thuc >= dt_bc._bac_da_thuc)
	{
		hs = dt_c._hs_gia / dt_bc._hs_gia;
		res = res + (pow_dt(dt_x, dt_c._bac_da_thuc - dt_bc._bac_da_thuc) * hs);
		dt_c = dt_c - dt_bc * (pow_dt(dt_x, dt_c._bac_da_thuc - dt_bc._bac_da_thuc) * hs);
	}
	return dt_c;
};

inline vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > ChiaDaThucLayQ(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	//if (dt_1._bac_da_thuc < dt_2._bac_da_thuc)return ChiaDaThucLayQ(dt_2, dt_1);
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc) {
		cout << "ERROR 2 da thuc khac modul#173\n"; system("pause"); exit(-17);
	}
	if (dt_1._bac_da_thuc == -17 && dt_2._bac_da_thuc == -17) {
		MYDATHUC<ELEMENTOFPOLE<int> >nul(0, dt_1._modul_da_thuc);
		return vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > >(2, vector<MYDATHUC<ELEMENTOFPOLE<int> > >(1, nul));
	}
	if (dt_2._bac_da_thuc == -17) {
		cout << "ERROR da thuc 2 = 0 #173\n"; system("pause"); exit(-17);
	}
	vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > res(2);
	if (dt_1._bac_da_thuc < dt_2._bac_da_thuc) {
		MYDATHUC<ELEMENTOFPOLE<int> >nul({ ELEMENTOFPOLE<int>(dt_1._modul_da_thuc,0) }, dt_1._modul_da_thuc);
		res[0].push_back(dt_2);
		res[1].push_back(nul);
		return  res;
	}
	MYDATHUC<ELEMENTOFPOLE<int> > thuong;
	MYDATHUC<ELEMENTOFPOLE<int> > du;
	MYDATHUC<ELEMENTOFPOLE<int> > a = dt_1;
	MYDATHUC<ELEMENTOFPOLE<int> > b = dt_2;
	do
	{
		thuong = a / b;
		du = a%b;
		a = b;
		b = du;
		res[0].push_back(du);
		res[1].push_back(thuong);
	} while (du._bac_da_thuc != -17);
	res[0].pop_back();
	res[1].pop_back();
	return res;
}
inline MYDATHUC<ELEMENTOFPOLE<int> > getVofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	
	if (dt_1._bac_da_thuc < dt_2._bac_da_thuc) return getUofDathuc(dt_2, dt_1);
	MYDATHUC<ELEMENTOFPOLE<int> >nul(0, dt_1._modul_da_thuc);
	if (dt_1%dt_2 == nul) return dt_2*(ELEMENTOFPOLE<int>(dt_1._modul_da_thuc, dt_2._hs_gia._elem_ndao))*(ELEMENTOFPOLE<int>(dt_1._modul_da_thuc, dt_2._hs_gia._elem_ndao));
	if (dt_1._bac_da_thuc == -17 && dt_2._bac_da_thuc == -17) return MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc);
	vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > vec_dt_q = ChiaDaThucLayQ(dt_1, dt_2);
	if (dt_1._bac_da_thuc == -17) return MYDATHUC<ELEMENTOFPOLE<int> >(1, dt_1._modul_da_thuc);
	vector<MYDATHUC<ELEMENTOFPOLE<int> > > phu(vec_dt_q[1].begin(), vec_dt_q[1].end());
	phu.insert(phu.begin(), MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc));
	vector<MYDATHUC<ELEMENTOFPOLE<int> > > u(phu.size());
	u[0] = MYDATHUC<ELEMENTOFPOLE<int> >(1, dt_1._modul_da_thuc);
	u[1] = phu[1] * (ELEMENTOFPOLE<int>(dt_1._modul_da_thuc, -1));
	loop(i, 2, (signed)phu.size()) {
		u[i] = u[i - 2] - (u[i - 1] * phu[i]);
	}
	return (u.back() * MYDATHUC<ELEMENTOFPOLE<int> >(vec_dt_q[0].back()._hs_gia._elem_ndao, dt_1._modul_da_thuc));
}
inline MYDATHUC<ELEMENTOFPOLE<int> > getUofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	
	if (dt_1._bac_da_thuc < dt_2._bac_da_thuc) return getVofDathuc(dt_2, dt_1);
	MYDATHUC<ELEMENTOFPOLE<int> >nul(0, dt_1._modul_da_thuc);
	if (dt_1%dt_2 == nul) return nul;
	if (dt_1._bac_da_thuc == -17 && dt_2._bac_da_thuc == -17) return MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc);
	vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > vec_dt_q = ChiaDaThucLayQ(dt_1, dt_2);
	if (dt_1._bac_da_thuc == -17) return vec_dt_q[1][0];
	vector<MYDATHUC<ELEMENTOFPOLE<int> > > phu(vec_dt_q[1].begin(), vec_dt_q[1].end());
	phu.insert(phu.begin(), MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc));
	vector<MYDATHUC<ELEMENTOFPOLE<int> > > u(phu.size());
	u[0] = MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc);
	u[1] = MYDATHUC<ELEMENTOFPOLE<int> >(1, dt_1._modul_da_thuc);
	loop(i, 2, (signed)phu.size()) {
		u[i] = u[i - 2] - (u[i - 1] * phu[i]);
	}
	return (u.back() * MYDATHUC<ELEMENTOFPOLE<int> >(vec_dt_q[0].back()._hs_gia._elem_ndao, dt_1._modul_da_thuc));
}
inline MYDATHUC<ELEMENTOFPOLE<int> > getUCLNofDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2) {
	MYDATHUC<ELEMENTOFPOLE<int> >nul(0, dt_1._modul_da_thuc);
	if (dt_1%dt_2 == nul) return dt_2 * (ELEMENTOFPOLE<int>(dt_2._modul_da_thuc, dt_2._hs_gia._elem_ndao));
	if (dt_2%dt_1 == nul) return dt_1 * (ELEMENTOFPOLE<int>(dt_1._modul_da_thuc, dt_1._hs_gia._elem_ndao));
	if (dt_1._bac_da_thuc == -17 && dt_2._bac_da_thuc == -17) return MYDATHUC<ELEMENTOFPOLE<int> >(0, dt_1._modul_da_thuc);
	vector<vector<MYDATHUC<ELEMENTOFPOLE<int> > > > vec_dt_q;
	if (dt_1._bac_da_thuc >= dt_2._bac_da_thuc) {
		vec_dt_q = ChiaDaThucLayQ(dt_1, dt_2);
	}
	else  vec_dt_q = ChiaDaThucLayQ(dt_2, dt_1);

	if (dt_1._bac_da_thuc == -17) return dt_2;
	if (dt_2._bac_da_thuc == -17) return dt_1;
	return vec_dt_q[0].back()* (MYDATHUC<ELEMENTOFPOLE<int> >(vec_dt_q[0].back()._hs_gia._elem_ndao, dt_1._modul_da_thuc));
}
inline MYDATHUC<ELEMENTOFPOLE<int> > soSanhDaThucTheoModul(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_1, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_2, const MYDATHUC<ELEMENTOFPOLE<int> >& dt_md) {
	if (dt_1._modul_da_thuc != dt_2._modul_da_thuc || dt_1._modul_da_thuc != dt_md._modul_da_thuc || dt_2._modul_da_thuc != dt_md._modul_da_thuc) {
		cout << "da thuc khac Modul!!!1ERROR#276\n"; system("pause"); exit(-17);
	}
	MYDATHUC<ELEMENTOFPOLE<int> >d_dt = getUCLNofDathuc(dt_1, dt_md);
	/*ELEMENTOFPOLE<int> hs = ELEMENTOFPOLE<int>(d_dt._modul_da_thuc, d_dt._hs_gia._elem_ndao);
	d_dt = d_dt*hs;*/
	MYDATHUC<ELEMENTOFPOLE<int> >nul(0, d_dt._modul_da_thuc);
	if ((dt_2%d_dt) != nul) {
		cout << "so sanh vo nghiem!!!\n"; system("pause"); exit(-17);
	}
	if (d_dt._bac_da_thuc == 0) {
		return(getUofDathuc(dt_1, dt_md) * dt_2) % dt_md;
	}
	else
	{
		MYDATHUC<ELEMENTOFPOLE<int> >dt__1 = dt_1 / d_dt;
		MYDATHUC<ELEMENTOFPOLE<int> >dt__2 = dt_2 / d_dt;
		MYDATHUC<ELEMENTOFPOLE<int> >dt__md = dt_md / d_dt;
		MYDATHUC<ELEMENTOFPOLE<int> >res = soSanhDaThucTheoModul(dt__1, dt__2, dt__md);
		return res;
	}
}
inline ostream& operator<<(ostream& out, const MYDATHUC<ELEMENTOFPOLE<int> >&dt) {
	if (dt._ds_hs_of_dt.empty()) {
		out << 0; return out;
	}
	if (dt._bac_da_thuc == -17 || dt._bac_da_thuc == 0) {
		out << dt._ds_hs_of_dt.back(); return out;
	}
	else {
		out << dt._ds_hs_of_dt.back() << "x^" << dt._bac_da_thuc;
		for (int i = dt._ds_hs_of_dt.size() - 2; i >= 0; i--)
		{
			out << "+" << dt._ds_hs_of_dt[i] << "x^" << i;
		}
		return out;
	}
}
inline istream& operator>>(istream& in, MYDATHUC<ELEMENTOFPOLE<int> >&dt) {
	cout << "enter modul da thuc:  "; in >> dt._modul_da_thuc;
	cout << "enter bac da thuc:  "; in >> dt._bac_da_thuc;
	int md = dt._modul_da_thuc, bac = dt._bac_da_thuc;
	ELEMENTOFPOLE<int> nul(md, 0);
	vector<ELEMENTOFPOLE<int> >vec;
	vec.resize(bac + 1);
	//memset(vec, nul, (bac + 1)*sizeof(nul));
	int i_value = 0;
	loop(i, 0, bac + 1) {
		i_value = 0;
		cout << "nhap he so: \n"; cout << "a[" << i << "]:  ";
		in >> i_value; vec[i] = ELEMENTOFPOLE<int>(md, i_value);
	}
	MYDATHUC<ELEMENTOFPOLE<int> >dt_1(vec, md);
	dt = dt_1;
	return in;
}