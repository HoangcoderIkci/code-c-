#include "myHeader.h"

int main() {
	char **mych = new char*[5];
	loop(i, 0, 5)
		mych[i] = new char[255];
	myArr<my_string> res(5);
	mych =_get_data_from_file_2("mytext_2.txt", "r+");
	loop(i, 0, 5)
		res.bang_gia_tri[i] = mych[i];
	
	res._xu_Ly();
	
	/*myArr<float> myar(9);
	myar.bang_gia_tri = _get_data_from_file(2.1f, "mytext.txt", "r+");
	cout << myar._get_sum();

	myar._xu_Ly();*/
	system("pause");
	return 0;
}