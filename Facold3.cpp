// Лабораторная работа №2
// Факториальная система исчисления
// Автор: Петров К. (04.12.2020)
// Компилятор: gcc-2.95.2 (C++98)
// ------------------------------

#include <iostream>
#include <vector>

using namespace std;

// Десятичная -> Факториальная

vector<int> toFact1(int x, int y) {
	vector<int> v;
	if (x < y) v.push_back(x);
	else {
		v = toFact1((x / y), (y + 1));
		v.push_back(x % y);
	}
	return v;
}

vector<int> toFact(int x) {
	return toFact1(x, 2);
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

// Основная фунция

int main() {
	int n;
	cout << "Enter nunber: ";
	cin >> n;
	cout << n << " (10) => ";
	vector<int> fact = toFact(n);
	for (int i = 0; i != fact.size(); i++) cout << fact[i] << " ";
	cout << "(f) => " << toDec(fact) << " (10)" << endl;
	return 0;
}