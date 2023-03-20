#pragma once
void **alloc2D(int m, int n, int sizeItem);
void Free2D(void**a);
void **arrResize(void **a, int m_new, int n_new);
int arrRow(void **a);
int arrColumn(void **a);
template<class T>
void arrIn(T **&a) {
	if (a == nullptr) return;
	size_t m, n;
	n = arrColumn((void**)a);
	m = arrRow((void**)a);
	loop(i, 0, m) {
		loop(j, 0, n) {
			cin >> a[i][j];
		}
	}
}
template<class T>
void arrPrintf(T **&a) {
	if (a == nullptr) return;
	size_t m, n;
	n = arrColumn((void**)a);
	m = arrRow((void**)a);
	loop(i, 0, m) {
		loop(j, 0, n) {
			cout << a[i][j] << '\t';
		}
		cout << '\n';
	}
}