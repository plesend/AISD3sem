#include <iostream>
using namespace std;

void HanoiTower(int N, int k, int i);

int main() {
	int N, k;
	setlocale(0, "");

	cout << "¬ведите номер конечного стержн€: ";
	cin >> k;

	if (k < 2 || k > 3) {
		cout << "¬ведите корректные данные!!";
		return 0;
	}

	cout << "¬ведите количество блинчиков:  ";
	cin >> N;

	if (N < 1) {
		cout << "¬ведите корректные данные!!";
		return 0;
	}
	else {
		HanoiTower(N, k, 1); 
	}
}

void HanoiTower(int N, int k, int i) {
	if (N == 1)
		cout << "ѕереместить диск 1 с " << i << " на " << k << " стержень\n";
	else {
		int tmp = 6 - i - k;
		HanoiTower(N - 1, tmp, i);
		cout << "ѕереместить диск " << N << " с " << i << " на " << k << " стержень\n";
		HanoiTower(N - 1, k, tmp);
	}
}
