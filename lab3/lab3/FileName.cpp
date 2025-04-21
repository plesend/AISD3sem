#include <iostream>
#include <limits.h>
#define V 9
using namespace std;

int minDistance(int arr_min[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false && arr_min[v] <= min) {
            min = arr_min[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int arr_min[]) {
    char str[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    for (int i = 0; i < V; i++) {
        cout << "�� ������� " << str[i] << " -> " << arr_min[i] << endl;
    }
}

void dijkstra(int graph[V][V], int start) {
    int arr_min[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        arr_min[i] = INT_MAX;
        visited[i] = false;
    }
    arr_min[start] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(arr_min, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && arr_min[u] != INT_MAX && arr_min[u] + graph[u][v] < arr_min[v]) {
                arr_min[v] = arr_min[u] + graph[u][v];
            }
        }
    }
    printSolution(arr_min);
}

int main() {
    setlocale(LC_ALL, "rus");
    int start;
    int graph[V][V] = {
            {0, 7, 10, 0, 0, 0, 0, 0, 0},//a
            {7, 0, 0, 0, 0, 9, 27, 0, 0},//b
            {10, 0, 0, 0, 31, 8, 0, 0, 0},//c
            {0, 0, 0, 0, 32, 0, 0, 17, 21},//d
            {0, 0, 31, 32, 0, 0, 0, 0, 0},//e
            {0, 9, 8, 0, 0, 0, 0, 11, 0},//f
            {0, 27, 0, 0, 0, 0, 0, 0, 15},//g
            {0, 0, 0, 17, 0, 11, 0, 0, 15},//h
            {0, 0, 0, 21, 0, 0, 15, 15, 0},//i
    };
    do {
        cout << "������� ������ �������:\n";
        cout << "A - 0, B - 1, C - 2, D - 3, E - 4, F - 5, G - 6, H - 7, I - 8" << endl;
        cin >> start;
    } while (start < 0 || start > 8);
    dijkstra(graph, start);
}
