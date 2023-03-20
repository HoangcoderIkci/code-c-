#include "Function_Dathuc_ConTrol.h"
#include "FunctionDaThuc.h"
void cap(int *a) {
	delete a;
	a = nullptr;
}

int main() {
	/*vector<int>vec({ 1,1,1 });
	vector<int>vec2(31);
	vec2[0] = 1;
	vec2[15] = 1;
	vec2.back() = 1;
	cout << timBac(vec, 2)<<'\n';*/


	/*DathucInt *dt1;
	DathucInt *dt2;
	DathucInt *res;
	int n,k=1; 
	while (k)
	{	
		cout << "nhap n: ";
		cin >> n;
		vector<int> v1(n); v1.back() = 1;
		while (cin >> n)
		{
			v1[n] = 1;
		}
		vector<int> v2({ 1,1,0,0,0,0,1 });
		
		dt1 = KhoiTaoDathuc(v1, 2);
		dt2 = KhoiTaoDathuc(v2, 2);
		res = ChiaDaThucLayPhanDu(dt1, dt2);

		//cout << ChiaDaThucLayThuong(dt1, dt2,res) << '\n';
		cout << "nhap K:"; cin >> k;
		
	}
	freeDaThucInt(dt1);
	freeDaThucInt(dt2);
	freeDaThucInt(res);*/
	//cout << (3 << 1) << '\n';
	//int *arr = new int[100];
	//cout << sizeof(arr) << '\n';
	
	 
	int a, b; cin >> a >> b;
	cout << ((a - b) >> 36) << '\n';
	//cout << res << '\n';
	
	system("pause");
	return 0;
}