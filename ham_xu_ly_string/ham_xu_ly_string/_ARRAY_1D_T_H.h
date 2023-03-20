#pragma once
template<class T>
void arrayOutput(T *arr, const int&sz) {
	loop(i, 0, sz)
		cout << arr[i] << '\t';
	printf("\n");
}

template<class T>
T *arrInPut(int &n) {
	T * arr = nullptr; T *new_arr = NULL;
	T x;
	while (cin >> x)
	{

		new_arr = pushpack(arr, n, x);
		if (new_arr)
			arr = new_arr;
		//cout << sizeof(arr) << '\n'; system("pause")
	}
	return arr;
}


template<class T>
T *pushpack(T *arr, int &sz, T v_lue) {
	T * new_arr = (T *)realloc(arr, (++sz)*sizeof(T));
	new_arr[sz - 1] = v_lue;
	return new_arr;
}