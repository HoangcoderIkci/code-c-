#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define  loop(i,a,n) for(size_t i=a;i<n;i++)
using namespace std;
class grap
{
public:
	grap();
	int amoun_number_of_peaks;
	int numberOfComponents;
	bool is_link;
	map<int,set<int> >linkList_1;
	vector<vector<bool> > linklist_2;
	map<int, set<int> > listcomponent;
	void getGrap();
	void displayGrap();
	int get_Bac_OfDinh();
	void printf_bac_all_dinh();
	bool is_Euler_grap();
	int get_Khoang_Cach();
	friend vector<int> get_arr_kcach(grap,int a);
	vector<vector<int> > Lap_arr_Kcach();
	pair<int, int> Tim_Tam_Grap_and_duong_kinh();
};

