#include <iostream>
using namespace std;

const int V = 6;
const int INF = INT_MAX;

int distanceMatrix[V][V] = {
	{0, 28, 21, 59, 12, 27},
	{7, 0, 24, INF, 21, 9},
	{9, 32, 0, 13, 11, INF},
	{8, INF, 5, 0, 16, INF},
	{14, 13, 15, 10, 0, 22},
	{15, 18, INF, INF, 6, 0}
};

int pathsMatrix[V][V] = {
	{0, 2, 3, 4, 5, 6},
	{1, 0, 3, 4, 5, 6},
	{1, 2, 0, 4, 5, 6},
	{1, 2, 3, 0, 5, 6},
	{1, 2, 3, 4, 0, 6},
	{1, 2, 3, 4, 5, 0}
};

void floyd() {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			if (distanceMatrix[i][k] == INF) continue;
			for (int j = 0; j < V; j++) {
				if (distanceMatrix[k][j] == INF) continue;
				if (distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j]) {
					distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
					pathsMatrix[i][j] = pathsMatrix[i][k];
				}
			}
		}
	}
}

void printMatrices() {
	cout << "Длины путей:\n\t1.\t2.\t3.\t4.\t5.\t6.\n";
	for (int i = 0; i < V; i++) {
		cout << i + 1 << ".\t";
		for (int j = 0; j < V; j++) {
			if (distanceMatrix[i][j] == INF) cout << "INF\t";
			else cout << distanceMatrix[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\nМатрица путей:\n\t1.\t2.\t3.\t4.\t5.\t6.\n";
	for (int i = 0; i < V; i++) {
		cout << i + 1 << ".\t";
		for (int j = 0; j < V; j++) {
			cout << pathsMatrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main() {
	setlocale(0, "");
	floyd();
	printMatrices();
}
