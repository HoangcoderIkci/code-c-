#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int timkiem(int arr[], int k, int val);
void printfArr(int arr[], int n);
void sapxep(int[], int n);
void sapxep2(int[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int main() {
	int arr[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 0,n-1);
	printfArr(arr, n);
	cout << '\n';
//	system("pause");
	return 0;
}
void mergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int>L(n1);
	vector<int>R(n2);
	for (size_t i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = arr[m + i+1];
	}
	int i, j, k = l; i = j = 0;
	while (i < n1&&j < n2)
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j]; j++;
		}
		++k;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++; k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++; k++;
	}
}
void printfArr(int arr[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}