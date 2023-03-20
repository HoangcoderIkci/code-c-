#include "grap.h"



grap::grap()
{
}

void grap::getGrap()
{	
	cout << "enter the number of vertices: ";
	cin >> amoun_number_of_peaks;
	int d;
	vector<vector<bool> > vec_a(amoun_number_of_peaks, vector<bool>(amoun_number_of_peaks, false));
	loop(i, 0, amoun_number_of_peaks) {
		cout << "enter row " << i << " : ";
		loop(j, 0, amoun_number_of_peaks) {
			cin >> d;
			if (d) {
				linkList_1[i].insert(j);
				linkList_1[j].insert(i);
			}
		}
	}
	loop(i, 0, amoun_number_of_peaks) linkList_1[i].erase(i);
	//tao list 1
	/*loop(i, 0, amoun_number_of_peaks) {
		cout << "Enter the vertex associated with vertex "<< i <<" end pressing -1: ";
		cin >> d;
		while (d!=-1)
		{
			linkList_1[i].insert(d);
			cin >> d;
		}
	}*/
	// tao list 2.
	vector<vector<bool>> vec(amoun_number_of_peaks, vector<bool>(amoun_number_of_peaks, false));
	linklist_2 = vec;
	loop(i, 0, amoun_number_of_peaks) {
		for (auto itr_1 : linkList_1[i])
			linklist_2[i][itr_1] = true;
	}
	// su ly component
	vector<bool> vec_phu(amoun_number_of_peaks, true);
	numberOfComponents = 0;
	d = 0; int index = 0;
	bool is_true;
	while (d!=amoun_number_of_peaks)
	{	
		is_true = true;
		loop(i, 0, amoun_number_of_peaks) {
			if (vec_phu[i]) {
				listcomponent[index].insert(i);
				vec_phu[i] = false;
				break;
			}
		}
		lamtiep:
		for (auto itr_1 : listcomponent[index])
		{
			vec_phu[itr_1] = false;
			for (auto itr_2 : linkList_1[itr_1])
			{
				listcomponent[index].insert(itr_2);

			}
		}
		for (auto x : listcomponent[index]) {
			if (vec_phu[x]) {
				goto lamtiep;
			}
		}
			d += listcomponent[index].size();
			index++;
			numberOfComponents++;
		
		
	}
	
}

void grap::displayGrap()
{
	system("cls");
	for (auto itr : linkList_1) {
		cout << "vertices connected to vertex " << itr.first << " : ";
		for (auto itr_2 : itr.second) cout << itr_2 << " ";
		cout << '\n';
	}
	cout << "printer list_2:\n";
	loop(i, 0, amoun_number_of_peaks) {
		loop(j, 0, amoun_number_of_peaks)
			cout << linklist_2[i][j] << " ";
		cout << '\n';
	}	
	cout << "so luong component: " << numberOfComponents << '\n';
	cout << "listOfComponent: \n";
	loop(i, 0, numberOfComponents) {
		cout << "component " << i << ": { ";
		for (auto x : listcomponent[i]) cout << x << " ";
		cout << "}\n";
	}

}

int grap::get_Bac_OfDinh()
{	
	int index;
	cout << "enter number of dinh: ";
	cin >> index;
	return linkList_1[index].size();
}

void grap::printf_bac_all_dinh()
{
	system("cls");
	loop(i, 0, amoun_number_of_peaks) {
		cout << "bac cua dinh " << i << " : " << linkList_1[i].size() << '\n';
	}
}

bool grap::is_Euler_grap()
{
	loop(i, 0, amoun_number_of_peaks) {
		if (linkList_1[i].size() % 2 == 1) {
			cout << "not euler!!\n";
			return false;
		}
	}
	cout << "euler grap\n";
	return true;
}

int grap::get_Khoang_Cach()
{   
	grap gr;
	gr.getGrap();
	int a, b;
	cout << "khoang cach tu dinh ? ";
	cin >> a;
	cout << "den dinh ? ";
	cin >> b;
	vector<int> res;
	res = get_arr_kcach(gr,a);
	cout << res[b]<<'\n';
	return res[b];
}

vector<vector<int> > grap::Lap_arr_Kcach()
{	
	vector<int> vec_phu(amoun_number_of_peaks, 0);
	vector<vector<int> > arr_res(amoun_number_of_peaks,vector<int>( amoun_number_of_peaks,0));
	loop(i, 0, amoun_number_of_peaks) {
		vec_phu = get_arr_kcach(*this, i);
		arr_res[i] = vec_phu;
	}
	loop(i, 0, amoun_number_of_peaks) {
		loop(j, 0, amoun_number_of_peaks) {
			cout << arr_res[i][j] << ' ';
		}
		cout << '\n';
	}
	return arr_res;
}

pair<int,int> grap::Tim_Tam_Grap_and_duong_kinh()
{	
	vector<vector<int> >arr_kc(amoun_number_of_peaks,vector<int>(amoun_number_of_peaks,0));
	vector<int> maxx(amoun_number_of_peaks,0);
	pair<int, int> mypair;
	mypair.first = 0;
	mypair.second = 1;
	arr_kc=this->Lap_arr_Kcach();
	//loop(i, 0, amoun_number_of_peaks) arr_kc[i][i] = amoun_number_of_peaks + 1;
	loop(i, 0, amoun_number_of_peaks) {
		loop(j, 0, amoun_number_of_peaks) {
			if (arr_kc[i][j] > maxx[i]) {
				maxx[i] = arr_kc[i][j];
			}
		}
	}

	loop(i, 0, amoun_number_of_peaks) {
		if (maxx[i] > mypair.second) mypair.second = maxx[i];
		
		if (maxx[i] < mypair.second) mypair.first = i;
	}
		
		cout << "tam grap: " << mypair.first;
		cout << "\nduong kinh: " << mypair.second << '\n';
		return mypair;
}

vector<int> get_arr_kcach(grap gr,int a)
{
	vector<bool> is_true(gr.amoun_number_of_peaks, true);
	map<int,set<int> >myArr;
	int dem = 1;
	int index = 0;
	myArr[0].insert(a);
	is_true[a] = false;
	while (dem!=gr.amoun_number_of_peaks)
	{
		for (auto itr_1 : myArr[index]) {
			for (auto itr_2 : gr.linkList_1[itr_1]) {
				if (is_true[itr_2]) {
					myArr[index + 1].insert(itr_2);
					is_true[itr_2] = false;
				}
			}
		}
		++index;
		dem += myArr[index].size();
	}
	index++;
	vector<int> res(gr.amoun_number_of_peaks,0);
	loop(i, 0, gr.amoun_number_of_peaks) {
		loop(j, 0, index) {
			for (auto x : myArr[j]) {
				if (i == x) {
					res[i] = j;
					j = index;
				}
			}
		}
	}
	/*loop(i, 0, gr.amoun_number_of_peaks)
	{
		cout << "khoang cach tu " << a << " den " << i << " la : " << res[i] << '\n';
	}*/
	//vector<int> res;
	return res;
}



