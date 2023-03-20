//#include "SoPhuc.h"
#include "SoPhucSinXo.h"
// nhap phan so theo dang a b
// nhap complex : phan thuc, phan ao


int main() 
{
	
	/*soPhuc s1(1, 1);
	soPhuc s2(2, 3);
	vector<soPhuc> v1{ s1,s2 };
	vector<soPhuc> v2{s2};
	v1= v1 - v2;*/


	/*vector<vector<soPhuc> >vec;
	vector<vector<soPhuc> >res;
	vec=KhoiTao();
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << ' ';
		}
		cout << '\n';
	}
	res=KhoiOrt(vec);
	for (size_t i = 0; i < res.size(); i++)
	{
		for (size_t j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}*/
	
	/*int n =4; int x;
	vector<PhanSo> vec(n);
	vector<vector<PhanSo> >temp(n);
	vector<vector<PhanSo> >res;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> x;
			vec[j] = PhanSo(x);
		}
		temp[i] = vec;
	}
	res = KhoiOrt(temp);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	pair<vector<PhanSo>, vector<PhanSo>> p_res;
	vector<PhanSo> vec_X(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		vec_X[i] = PhanSo(x);
	}
	p_res = TimHinhChieu(res, vec_X);
	cout << "hinh chieu: \n";
	for (size_t i = 0; i < n; i++)
	{
		cout << p_res.first[i] << ' ';
	}
	cout << "hinh coctab: \n";
	for (size_t i = 0; i < n; i++)
	{
		cout << p_res.second[i] << ' ';
	}*/
	// sophucsinxio
	int n = 2, m = 2;
	vector<vector<Complex> >vec(n);
	vector<vector<Complex> >res;
	vector<Complex >temp(m);
	Complex x;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> x;
			temp[j] = Complex(x);
			cout << x << '\n';
		}
		vec[i] = temp;
	}
	res = KhoiOrt(vec);
	for (size_t i = 0; i < n; i++)
	{
		
		for (size_t j = 0; j < n; j++)
		{
			cout << res[i][j] << ' ';


		}
		cout << '\n';
	}
	res = TimMaTranC(res, vec);
	for (size_t i = 0; i < n; i++)
	{

		for (size_t j = 0; j < n; j++)
		{
			cout << res[i][j] << ' ';


		}
		cout << '\n';
	}
	system("pause");
	return 0;
}

