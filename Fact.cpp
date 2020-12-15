// Лабораторная работа №2. Факториальная система исления
// Автор: Петров К. (04.12.2020)  и еще новый комментарий второй уже
// Компилятор: g++.exe (gcc-2.95.2 (C++98))
// ----------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Десятичная -> Факториальная

vector<int> toFact(int x) {
	vector<int> v;
	if (!x) v.push_back(0);
	for (int i = 2; x; x /= i, i++)
		v.push_back(x % i);
	reverse(v.begin(), v.end());
	return v;
}

// Факториальная -> Десятичная 

int toDec(vector<int>& f) {
	int dec = 0, f0 = 1;
	for (int i = f.size()-1; i >= 0; i--) {
		f0 = f0 * (f.size() - i);
		dec = dec + (f[i] * f0);
	}
	return dec;
}

// Вывод факториального числа на экран

void showFact(vector<int>& f) {
	for (int i = 0; i != f.size(); i++)
		cout << f[i] << " ";
}

// ------------------------------------

int main() {
	cout << "Enter nunber: ";
	int n;
	cin >> n;
	cout << n << " > [ ";
	vector<int> v = toFact(n);
	showFact(v);
	cout << "] > " << toDec(v) << endl;
	return 0;
}