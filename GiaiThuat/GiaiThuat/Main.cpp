#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int>a, pair<int, int>b) {
	return (a.second - a.first) <= (b.second - b.first);
}
int mettingRoom(std::vector<int> s, std::vector<int> e)
{
	int sz = s.size();
	bool(*ck)(pair<int, int>, pair<int, int>) = cmp;
	vector<pair<int, int>>temp;
	for (size_t i = 0; i < sz; i++)
	{
		temp.push_back(pair<int, int>(s[i], e[i]));
	}
	sort(temp.begin(), temp.end(),ck);
	pair<int, int>p;
	int res = 1;
	vector<pair<int, int>>itr;
	itr.push_back(temp.front());
	bool check = true;
	for (size_t i = 1; i < sz; i++)
	{
		check = true;
		p = temp[i];
		for (size_t j = 0; j < res; j++)
		{
			if (!(p.first >= itr[j].second || p.second <= itr[j].first)) {
				check = false;
				break;
			}
		}
		if (check) {
			itr.push_back(temp[i]);
			res++;
		}
	}
	return res;
}
/*
bool beautifulArray(std::vector<int> arr)
{
	int sz = arr.size();
	int m = sz / 2;
	int s1 = 0, s2 = 0;
	for (int i = 0;  i < m;  i++)
	{
		s1 += arr[i];
	}
	for (int i = m+1; i < sz; i++)
	{
		s2 += arr[i];
	}
	while (s1 < s2) {
		s1 += arr[m++];
		s2 -= arr[m];
	}
	return(s1 == s2);
}
int searchElement02(std::vector<std::vector<int>> a, int k)
{
	bool ok = true;
	int i, j, d,sz=a.size()+2;
	int temp = a[0][0];
	vector<int> init(sz, temp);
	a.insert(a.begin(), init);
	a.push_back(init);
	for (size_t i = 1; i < sz-1; i++)
	{
		a[i].push_back(temp);
		a[i].push_back(temp);
	}
	j = 0;
	i = d=1;
	while (d < k&&ok) {
		ok = false;
		if (a[i][j] >= a[i][j + 1]) {
			for (size_t t = 0; t < sz-2; t++)
			{
				if (a[i + 1][t]>a[i][j]) {
					ok = true;
					i++; j = t;
					d++;
				}
				break;
			}
			
		}
		else if (a[i - 1][j + 1] <= a[i][j] && a[i][j] < a[i][j + 1]) {
			for (size_t t = 0; t < sz - 2; t++)
			{
				if (a[i + 1][t]>a[i][j]) {
					ok = true;
					d++;
					if (a[i + 1][t] < a[i][j + 1]) {
						i++; j = t;
					}
					else {
						j++;
					}
					break;
				}
			}
			
		}
		else {
			for (size_t t = 0; t < sz - 2; t++)
			{
				if (a[i + 1][t]>a[i][j]) {
					ok = true;
					d++;
					if (a[i + 1][t] < a[i-1][j+1]) {
						i++; j = t;
					}
					else {
						i--; j++;
					}
					break;
				}
			}
		}
	}
	if (d != k) return -1;
	return a[i][j];
}
int searchElement(std::vector<int> a, int n)
{
	int sz = a.size(),d=1;
	stack<int> st1, st2;
	st1.push(a[0]);
	for (size_t i = 1; i < sz; i++)
	{
		if (st1.top() == a[i]) continue;
		if (st1.top() >= a[i] && d < n) {
			st1.push(a[i]);
			d++;
		}
		else {
			while (d != 0&&st1.top() < a[i]) {
				st2.push(st1.top());
				st1.pop();
				d--;
			}
			if (st1.empty()||st1.top() != a[i]) {
				st1.push(a[i]); d++;
			}
			while (d < n&&!st2.empty()) {
				st1.push(st2.top()); d++;
				st2.pop();
			}
			while (!st2.empty())
				st2.pop();
		}
		cout << d << '\n';
	}
	if (d < n) return -1;
	else {
		while (d>n)
		{
			st1.pop(); d--;
		}
	}
	return st1.top();
}
int cmp(int a, int b) {
	int x = a, y = b;
	int s_a = 0, s_b = 0;
	while (a) {
		s_a += a % 10;
		a /= 10;
	}
	while (b) {
		s_b += b % 10;
		b /= 10;
	}
	if (s_a < s_b) return -1;
	else if (s_a>s_b) return 1;
	else return x - y;
}
void sortMerger(std::vector<int> &arr, int l, int r);
void GopMang(std::vector<int> &arr, int l, int m, int r);
std::vector<int> digitalSumSort(std::vector<int> a)
{
	int sz = a.size();
	sortMerger(a, 0, sz - 1);
	return a;
}


void sortMerger(std::vector<int> &arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		sortMerger(arr, l, m);
		sortMerger(arr, m + 1, r);
		GopMang(arr, l, m, r);
	}
}
void GopMang(std::vector<int> &arr, int l, int m, int r) {
	int sz1 = m - l + 1, sz2 = r - m;
	int *a = new int[sz1];
	int *b = new int[sz2];
	for (size_t i = 0; i < sz1; i++)
	{
		a[i] = arr[l + i];
	}
	for (size_t i = 0; i < sz2; i++)
	{
		b[i] = arr[m + 1 + i];
	}
	int i, j, k;
	i = j = 0;
	k = l;
	while (i < sz1&&j < sz2)
	{
		
		if (cmp(a[i], b[j]) < 0) {
			arr[k++] = a[i++];
		}
		else {
			arr[k++] = b[j++];
		}
	}
	while (i < sz1) {
		arr[k++] = a[i++];
	}
	while (j < sz2) {
		arr[k++] = b[j++];
	}
	delete[]a;
	delete[]b;
}*/
int main() {
	vector<int> a{ 98,14,70,19,59,17,27,27,22,92,10,0,75,28,23,12,47,51,50,81 };
	vector<int> b{ 139,32,93,44,78,65,61,29,115,107,41,84,98,68,32,85,75,81,123,151 };
	cout<<mettingRoom(a, b);
 	system("pause");
	return 0;
}
