#include "myFunction.h"

void GetdataFromfile() {
	FILE *f = fopen("filetowrite.txt", "r+");
	if (f == NULL) cout << "khong doc duoc file";
	else{
		char buffer[100];
		char buffer_2[100]="abc";
		cout << strlen(buffer_2) << '\n';
		int dem = 0;
		cout << "thuc hien doc file: \n";
		
		for (int i = 0; i < 2; i++) {
			dem = fread(buffer, 5, 1, f);
			int x = strlen(buffer);
			buffer[5] = '\0';
			cout << (int)buffer[6] << '\n';
			printf("%d   %s", dem, buffer);
			cout << "luot 2\n\n\n";
		}
			
		//cout << buffer<<'\n';
	}
	system("pause");
	fclose(f);
};