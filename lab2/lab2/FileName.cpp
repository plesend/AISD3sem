#include <iostream>
#include <queue>
#include <stack>

using namespace std;
const int n = 10;
bool* visited = new bool[n];

void BFS(int start);
void DFS(int start);

int graphMatrix[n][n] = { 
  // 0  1  2  3  4  5  6  7  8  9
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},//0
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},//1
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},//2
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},//3
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},//4
    {0, 0, 0, 1, 1, 0, 0, 0, 1, 0},//5
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},//6
    {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},//7
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},//8
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},//9
};//                                     
//                                   
int main() {
    setlocale(0, "");

    cout << "Матрица смежности:\n";
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nРебра:\n";
    int rebr1[11] = { 1,1,2,2,3,4,4,5,6,7,9 };
    int rebr2[11] = { 2,5,7,8,8,6,9,6,9,8,10 };
    for (int i = 0; i < 11; i++) {
        cout << "(" << rebr1[i] << ", " << rebr2[i] << "),  ";
        cout << "(" << rebr2[i] << ", " << rebr1[i] << ")\n";
    }

    cout << "\nСписок смежности:\n";
    int arrRibs[n][3] = {
        {2,5},
        {1,7,8},
        {8},
        {6,9},
        {1,6},
        {4,5,9},
        {2,8},
        {2,3,7},
        {4,6,10},
        {9},
    };

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " >> ( ";
        for (int j = 0; j < 3; j++) {
            if (arrRibs[i][j] == 0)
                break;
            cout << arrRibs[i][j] << " ";
        }
        cout << ")\n";
    }

    int bfsSearchStart;
    cout << "\nПоиск в ширину\n";
    cout << "Введите первую вершину: "; cin >> bfsSearchStart;
    cout << "Результат поиска: ";
    BFS(bfsSearchStart - 1);

    int dfsSearchStart;
    cout << "\n\nПоиск в глубину\n";
    cout << "Введите первую вершину: "; cin >> dfsSearchStart;
    cout << "Результат поиска: ";
    DFS(dfsSearchStart - 1);
    cout << "\n";

    delete[] visited;
}

void BFS(int start) { //ш
    bool visited[n] = { false };
    queue<int> searchBFS; 
    searchBFS.push(start);
    visited[start] = true;

    while (!searchBFS.empty()) { 
        int viewedPart = searchBFS.front();
        cout << viewedPart + 1 << " ";
        searchBFS.pop();

        for (int i = 0; i < n; i++) {
            if (graphMatrix[viewedPart][i] != 0 && !visited[i]) {
                searchBFS.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int start) { //6
    stack<int> searchDFS;
    searchDFS.push(start);

    while (!searchDFS.empty()) {
        int current = searchDFS.top();
        searchDFS.pop();

        if (!visited[current]) {
            cout << current + 1 << " ";
            visited[current] = true;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (graphMatrix[current][i] != 0 && !visited[i]) {
                searchDFS.push(i);
            }
        }
    }
    
}
