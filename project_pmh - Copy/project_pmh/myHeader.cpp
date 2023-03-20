#include "myHeader.h"


char **_get_data_from_file_2(char name[],char typ[]) {
	int row = 5;
	int column = 255;
	char **my_str = new char*[row];
	loop(i, 0, row)
		my_str[i] = new char[column];
	int i = 0;
	FILE *f = fopen(name, typ);
	if (f == NULL) {
		cout << "not file";
		return nullptr;
	}
	while (!feof(f))
	{
		fgets(my_str[i], 254, f);
		i++;
	}
	fclose(f);
	return my_str;
}

my_string::my_string(char *str)
{
	strcpy(my_tr, str);
}

my_string my_string::operator+(const my_string & str_2)
{
	//my_string dest;
	
	strcat(my_tr, str_2.my_tr);
	return *this;
}

bool my_string::operator<(const my_string & str_2)
{
	int res;
	res = strcmp(my_tr, str_2.my_tr);
	if (res < 0) return true;
	else return false;
}

bool my_string::operator==(const my_string & str_2)
{
	int res;
	res = strcmp(my_tr, str_2.my_tr);
	if (res == 0) return true;
	else return false;
}

bool my_string::operator>(const my_string & str_2)
{
	int res;
	res = strcmp(my_tr, str_2.my_tr);
	if (res > 0) return true;
	else return false;
}


