#include "myheader.h"
/*
int cmp(void *a, void *b) {
	return strcmp(*(char **)a, *(char **)b);
}
int ssGiam(void *a, void *b) {
	return -strcmp(*(char **)a, *(char **)b);
}
void swapMem(char *a, char *b, int n) {
	char temp;
	loop(i, 0, n) {
		temp = a[i];
		a[i] = b[i]; b[i] = temp;
	}
}
void mySort(void *a, int nRec, int sRec,int(*cmp)(void *,void *)) {
	char *str1 = (char *)a;
	loop(i, 0, nRec - 1) {
		char *minPtr = str1; char *str2 = str1 + sRec;
		loop(j, i + 1, nRec) {
			if (cmp(minPtr, str2) > 0) {
				minPtr = str2;
			}
			str2 += sRec;
		}
		swapMem(minPtr, str1,sRec);
		str1 += sRec;
	}
}*/
/*
bool cmpp(int *x,int *y) {
	return *x == *y;
}
struct Fraction
{
	int Numerator, Denominator;
};
ostream& operator<<(ostream& out, const Fraction& ps) {
	out << ps.Numerator << '/' << ps.Denominator;
	return out;
}
istream& operator>>(istream& in,Fraction& ps) {
	char ch;
	in >> ps.Numerator;
	in >> ch;
	in >> ps.Denominator;
	return in;
}
bool operator==(Fraction p1, Fraction p2) {
	return (p1.Numerator * p2.Denominator == p1.Denominator*p2.Numerator);
}
bool operator>=(Fraction p1, Fraction p2) {
	if (p1==p2) return true;
	if (p1.Denominator*p2.Denominator > 0) return (p1.Numerator*p2.Denominator > p2.Numerator*p1.Denominator);
	else {
		return (p1.Numerator*p2.Denominator < p2.Numerator*p1.Denominator);
	}
}
bool operator>(Fraction p1, Fraction p2) {
	if (p1 == p2) return false;
	return p1 >= p2;
}
bool operator<(Fraction p1, Fraction p2) {
	return(!(p1 >= p2));
}
bool operator<=(Fraction p1, Fraction p2) {
	return(!(p1 > p2));
}
bool cmpFr(Fraction* p1, Fraction *p2) {
	return (p1->Numerator*p2->Denominator == p1->Denominator*p2->Numerator);
}
bool cmpGiamDan(Fraction *p1, Fraction *p2) {
	return *p1 >*p2;
}  */
/*
int ssmin(void *s1, void *s2) {
	return strcmp(*(char **)s1, *(char **)s2);
}
int ssmaxFloat(void *s1, void *s2) {
	return fabs(*(float*)s1) > fabs(*(float*)s2);
}
void *bestOfArray(void *a, int n, int sz, int(*cmp)(void *, void *)) {
	if (cmp == nullptr) return nullptr;
	void *ptr = a; char *itr = (char *)a+sz;
	loop(i, 0, n-1) {
		if (cmp(itr, ptr) > 0) {
			ptr = (void *)itr;
		}
		itr += sz;
	}
	return ptr;
}
int bestindexOfArray(void *a, int n, int sz, int(*cmp)(void *, void *)) {
	int res = 0;
	if (cmp == nullptr) exit(-1);
	void *ptr = a; char *itr = (char *)a + sz;
	loop(i, 0, n - 1) {
		if (cmp(itr, ptr) > 0) {
			res = i;
			ptr = (void *)itr;
		}
		itr += sz;
	}
	return ++res;
}
int ssmaxFloat2(float *s1,float *s2) {
	return fabs(*s1) > fabs(*s2);
}
template<class T>
int bestindexOfArrayT(T *a, int n,int(*cmp)(void *, void *)) {
	int res = 0;
	if (cmp == nullptr) exit(-1);
	loop(i, 1, n) {
		if (cmp(&a[i],&a[res]) > 0) {
			res = i;
		}
	}
	return res;
}
int binarysearch(void *key, void *a, int n, int sz, int(*cmp)(void *, void *)) {
	if (cmp == nullptr)exit(-1);
	int L = 0, R = n - 1;
	int mid; char *itr = nullptr;
	while (L<=R)
	{
		mid = (L + R) / 2;
		itr = (char *)a + mid*sz; int test = cmp(key, itr);
		if (test > 0) {
			L = mid + 1;
		}
		else if(test < 0){
			R = mid - 1;
		}
		else {
			return mid;
		}
	}
	return NULL;
}
int ssBinary(float *s1, float *s2) {
	float*f1 = (float*)s1;
	float*f2 = (float*)s2;
	if (*f1 > *f2) return 1;
	if (*f1 == *f2) return 0;
	return -1;
}
float &redmin(float &a) {
	return a;
}
char *getBytes(double *d1, int *sItem) {
	*sItem = sizeof(double);
	return (char *)d1;
}
short *getWords(double *d1, int *nw) {
	*nw = sizeof(short);
	return (short *)d1;
}
void listbytes(char bytes[], int nb) {
	loop(i, 0, nb) {
		printf("0x%X", (unsigned char)bytes[i]);
		printf("\n");
	}
}
void listwords(short words[], int nw) {
	loop(i, 0, nw) {
		printf("0x%X", (unsigned short)words[i]);
		printf("\n");
	}
}*/
void swap(int &a, int &b) {
	int temp = a; a = b; b = temp;
}
void sapXepMang(int **a, int m, int n) {
	int k = 2; int i, j, index_min,index_max,p;
	for (k; k != 0; k--) {
		// buoc 2
		for (i = 0; i < m; i = i + 2) {
			
			for (j = 0; j < n-1; j++) {
				index_min = j;
				index_max = n - j - 1;
				for (p = j+1; p < n; p++) {
					if (a[i][p] < a[i][index_min]) index_min = p;
					if (a[i+1][n-p-1] < a[i+1][index_max]) index_max = n - p - 1;
				}
				if (index_min != j) swap(a[i][index_min], a[i][j]);
				if (index_max != n-j-1) swap(a[i+1][index_max], a[i+1][n - j - 1]);
			}
		}
		
		// buoc 3
		for (j = 0; j < n; j++) {
			for (i = 0; i < m-1; i++) {
				index_min = i;
				for (p = i+1; p < m; p++) {
					if (a[index_min][j]>a[p][j]) index_min = p;
				}
				if (index_min != i) swap(a[index_min][j], a[i][j]);
			}
		}
	}
	// buoc 5
	for (i = 0; i < m; i = i + 2) {

		for (j = 0; j < n - 1; j++) {
			index_min = j;
			for (p = j + 1; p < n; p++) {
				if (a[i][p] < a[i][index_min]) index_min = p;
			}
			if (index_min != j) swap(a[i][index_min], a[i][j]);
		}
	}
}

int main() {
	int **a = new int *[4];
	loop(i, 0, 4)
		a[i] = new int[4];
	 int m = 4, n = 4;
	loop(i, 0, m) {
		loop(j, 0, n)
			cin >> a[i][j];
	}
	sapXepMang(a, m, n);
	loop(i, 0, m) {
		loop(j, 0, n)
			cout << a[i][j] << '\t';
		cout << '\n';
	}
	cout << '\n';
	
	loop(i, 0, 4)
		delete a[i];
	delete[]a;
	system("pause");
	return 0;
} 