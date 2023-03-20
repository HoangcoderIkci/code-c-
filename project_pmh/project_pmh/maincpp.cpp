#include "myHeader.h"
// ham dung cho 5 dong.
void my_cat(char *dest, char*source);
int main() {
/*
	int row = 5;
	char **mych = new char*[row];
	loop(i, 0, row)
		mych[i] = new char[255];
	myArr<my_string> res(row);
	mych =_get_data_from_file_2("mytext_2.txt", "r+");
	loop(i, 0, row)
		res.bang_gia_tri[i] = mych[i];
	
	res._xu_Ly();*/
	
	/*myArr<float> myar(9);
	myar.bang_gia_tri = _get_data_from_file(2.1f, "mytext.txt", "r+");
	cout << myar._get_sum();

	myar._xu_Ly();*/
	/*int n = 20;
	char *str_1 = new char[n];
	char *str_2 = new char[n];
	str_1 = "abcd efg 123";
	int j = 0;
	int len = strlen(str_1);
	for (int i = 0; i < len; i++)
	{
		if (str_1[i+j] == ' ') {
			j++;
		}
			str_2[i] = str_1[i + j];
	}
	printf("%s", str_2);*/
	char s1[7] = "av";
	//s1[0] = '\0';
	char *s2 = new char[3];
	s2 = "xy";
	my_cat(s1, s2);
	printf("%s", s1);
	system("pause");
	return 0;
}
int myfun(int n) {
	return (n == 1) ? 1 : (n == 0) ? 0: -1;
 
}
void my_cat(char *dest, char*src) {
	(*dest) ? my_cat(++dest, src) : (*dest++ = *src++) ? my_cat(dest,src) : 0;
}
