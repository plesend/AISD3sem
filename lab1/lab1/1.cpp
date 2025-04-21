#include <iostream>
using namespace std;

void HanoiTower(int N, int k, int i);

int main() {
	int N, k;
	setlocale(0, "");

	cout << "������� ����� ��������� �������: ";
	cin >> k;

	if (k < 2 || k > 3) {
		cout << "������� ���������� ������!!";
		return 0;
	}

	cout << "������� ���������� ���������:  ";
	cin >> N;

	if (N < 1) {
		cout << "������� ���������� ������!!";
		return 0;
	}
	else {
		HanoiTower(N, k, 1); 
	}
}

void HanoiTower(int N, int k, int i) {
	if (N == 1)
		cout << "����������� ���� 1 � " << i << " �� " << k << " ��������\n";
	else {
		int tmp = 6 - i - k;
		HanoiTower(N - 1, tmp, i);
		cout << "����������� ���� " << N << " � " << i << " �� " << k << " ��������\n";
		HanoiTower(N - 1, k, tmp);
	}
}
