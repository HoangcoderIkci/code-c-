#pragma once
#include "MYDATHUC.h"


class POLEOfDathuc
{
public:
	int _bac_of_elem;;
	MYDATHUC<ELEMENTOFPOLE<int> > _gia_tri_elem;
	MYDATHUC<ELEMENTOFPOLE<int> > _elem_ndao;
	MYDATHUC<ELEMENTOFPOLE<int> > _elem_dxung;
	MYDATHUC<ELEMENTOFPOLE<int> > _modul;
	POLEOfDathuc() {};
	POLEOfDathuc(const MYDATHUC<ELEMENTOFPOLE<int> >&gt_vao, const MYDATHUC<ELEMENTOFPOLE<int> >&md) {
		if (md._modul_da_thuc != gt_vao._modul_da_thuc) {
			cout << "ERROR!! gt va dt_md khac modul\n";
			system("pause"); exit(-17);
		}
		MYDATHUC<ELEMENTOFPOLE<int> > gt = gt_vao;
		if (gt._bac_da_thuc != -17) gt = gt%md;
		MYDATHUC<ELEMENTOFPOLE<int> >nul(0, gt._modul_da_thuc);
		if (gt._bac_da_thuc == -17&&gt==0) {
			this->_gia_tri_elem = gt;
			this->_elem_ndao = gt;
			this->_elem_dxung = gt;
			this->_modul = md;
			this->_bac_of_elem = -17;
		}
		else {
			this->_modul = md;
			this->_gia_tri_elem = gt;
			this->_elem_dxung = nul - gt;
			MYDATHUC<ELEMENTOFPOLE<int> >edi(1, md._modul_da_thuc);
			this->_elem_ndao = soSanhDaThucTheoModul(gt, edi, md);
			for (int i = 1;; i++) {
				if (pow_dt(gt, i) % md == edi) {
					this->_bac_of_elem = i; break;
				}
			}
		}
		
	}
	POLEOfDathuc(const int&gt_1, const MYDATHUC<ELEMENTOFPOLE<int> >&md) {
		MYDATHUC<ELEMENTOFPOLE<int> >gt(gt_1, md._modul_da_thuc);
		*this = POLEOfDathuc(gt, md);
	}
	POLEOfDathuc(const ELEMENTOFPOLE<int>&gt_1, const MYDATHUC<ELEMENTOFPOLE<int> >&md) {
		MYDATHUC<ELEMENTOFPOLE<int> >gt({gt_1}, md._modul_da_thuc);
		*this = POLEOfDathuc(gt, md);
	}
	//POLEOfDathuc operator()(const int&, const int&)
	//ELEMENTOFPOLE<int> operator[](const int&b) const;
	POLEOfDathuc ThayDoiGiaTri(const MYDATHUC<ELEMENTOFPOLE<int> >&gt, const MYDATHUC<ELEMENTOFPOLE<int> >&md) {
		POLEOfDathuc neww(gt, md);
		*this = neww;
		return neww;
	}
	friend vector<POLEOfDathuc> KhoiTaoPole(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_md);
	friend POLEOfDathuc operator/(const POLEOfDathuc& el_1, const POLEOfDathuc&el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "!!!ERROR #2 elem da thuc khac modul\n"; system("pause"); exit(-17);
		}
		MYDATHUC<ELEMENTOFPOLE<int> >res_dt=soSanhDaThucTheoModul(el_2._gia_tri_elem, el_1._gia_tri_elem, el_1._modul);
		POLEOfDathuc res(res_dt, el_1._modul);
		return res;
	}
	friend ostream & operator<<(ostream&out, const POLEOfDathuc& el) {
		out << el._gia_tri_elem;
		return out;
	}
	friend bool operator==(const POLEOfDathuc& el_1, const POLEOfDathuc& el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "!!!ERROR2 el_of_pole khac modul"; system("pause"); exit(-17);
		}
		return el_1._gia_tri_elem == el_2._gia_tri_elem;
	}
	friend bool operator!=(const POLEOfDathuc& el_1, const POLEOfDathuc& el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "!!!ERROR2 el_of_pole khac modul"; system("pause"); exit(-17);
		}
		return el_1._gia_tri_elem != el_2._gia_tri_elem;
	}
	friend bool operator==(const POLEOfDathuc&el, const int&a) {
		return el._gia_tri_elem == a;
	}
	friend bool operator!=(const POLEOfDathuc&el, const int&a) {
		return el._gia_tri_elem != a;
	}
	friend POLEOfDathuc operator+(const POLEOfDathuc&el_1, const POLEOfDathuc&el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "ERROR!! khong cong duoc ele pole khac modul\n"; system("pause"); exit(-17);
		}
		MYDATHUC<ELEMENTOFPOLE<int> >dt = el_1._gia_tri_elem + el_2._gia_tri_elem;
		return POLEOfDathuc(dt, el_1._modul);
	}
	friend POLEOfDathuc operator-(const POLEOfDathuc&el_1, const POLEOfDathuc&el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "ERROR!! khong cong duoc ele pole khac modul\n"; system("pause"); exit(-17);
		}
		MYDATHUC<ELEMENTOFPOLE<int> >dt = el_1._gia_tri_elem - el_2._gia_tri_elem;
		return POLEOfDathuc(dt, el_1._modul);
	}
	friend POLEOfDathuc operator*(const POLEOfDathuc&el_1, const POLEOfDathuc&el_2) {
		if (el_1._modul != el_2._modul) {
			cout << "EEROR 2 elem khac modul khong nhan dc!!\n"; system("pause"); exit(-17);
		}
		MYDATHUC<ELEMENTOFPOLE<int> > dt_res = el_1._gia_tri_elem*el_2._gia_tri_elem;
		return POLEOfDathuc(dt_res, el_1._modul);
	}
	friend void FOR(int k, int md, int bac, vector <ELEMENTOFPOLE<int> >&vec_phu, const vector <ELEMENTOFPOLE<int> >&vec, vector<MYDATHUC<ELEMENTOFPOLE<int> > >&res);
	friend ostream& operator<<(ostream& out, const vector<POLEOfDathuc>&);
	/*
	friend istream & operator>>(istream&in, ELEMENTOFPOLE<int>& el);*/
};
inline void FOR(int k,int md, int bac, vector <ELEMENTOFPOLE<int> >&vec_phu,const vector <ELEMENTOFPOLE<int> >&vec, vector<MYDATHUC<ELEMENTOFPOLE<int> > >&res) {
	loop(i, 0, md) {
		vec_phu[k-1]=vec[i];
		if (k == bac) {
			res.push_back(MYDATHUC<ELEMENTOFPOLE<int> >(vec_phu, md));
			
		}
		else {
			FOR(k + 1, md, bac, vec_phu, vec, res);
		}
	}
}
inline vector<POLEOfDathuc> KhoiTaoPole(const MYDATHUC<ELEMENTOFPOLE<int> >&dt_md) {
	vector<MYDATHUC<ELEMENTOFPOLE<int> > > res;
	vector<ELEMENTOFPOLE<int> >vec_hs(dt_md._modul_da_thuc);
	loop(i, 0, dt_md._modul_da_thuc) {
		vec_hs[i] = ELEMENTOFPOLE<int>(dt_md._modul_da_thuc, i);
	}
	int bac = dt_md._bac_da_thuc;
	vector<ELEMENTOFPOLE<int> >vec_phu(bac);
	FOR(1, dt_md._modul_da_thuc, bac, vec_phu, vec_hs, res);
	vector<POLEOfDathuc> KetQua;
	loop(i, 0, (signed)res.size()) {
		KetQua.push_back(POLEOfDathuc(res[i], dt_md));
	}
	return KetQua;
}



 inline  ostream & operator<<(ostream& out, const vector<POLEOfDathuc>&mpl) {
	 int fmat = 17;
	loop(i, 0, (signed)mpl.size()) {
		out << "bac cua elem:  " << setw(fmat) << left << mpl[i]._bac_of_elem;
		out << mpl[i]._gia_tri_elem << '\n';
	}
	return out;
}