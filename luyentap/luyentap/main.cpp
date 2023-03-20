#include "myLibrary.h"


int main() {
	cout << "\t\t\tWelcome to the endless era!!!!\n";
	int row,column;
	vector<vector<int> >vec_a;
	vector<vector<int> >vec_b;
	cout << "enter row of matrix: ";
	cin >> row;
	cout << "enter column of matrix: ";
	cin >> column;
	vec_a=getMatrix(row, column);  
	maTran mtrix_1 = xuLyMatrix(vec_a);
	/*a.Khoi_Tao_Matrix();
	a.display_Matrix();
	Matrix_AI();*/
	
	/*Matrixx a;
	a.timCAC();*/





	
	
	/*int r = 7, cl = 6;
	vector<vector<int> > vec(r, vector<int>(cl));
	//vector<vector<int> > res(r, vector<int>(cl));
	loop(i, 0, r)
		loop(j, 0, cl)
		cin >> vec[i][j];
	TimMtrixNghichNgom(vec);*/
	
	//GetDaThuc_0VecTor(vec);
	system("pause");
	return 0;

}
