#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;
struct Node {
    int frequency;
    string symbol = "";
    Node* left, * right;
};

Node* HuffmanAlgorithm(list<Node*>& nodes) {
    while (nodes.size() != 1) {
        nodes.sort([](Node* firstNode, Node* secondNode) -> bool { return firstNode->frequency < secondNode->frequency; });

        Node* left = nodes.front();
        nodes.pop_front();
        Node* right = nodes.front();
        nodes.pop_front();

        Node* parent = new Node;
        parent->left = left;
        parent->right = right;
        parent->symbol += left->symbol + right->symbol;
        parent->frequency = left->frequency + right->frequency;

        nodes.push_back(parent);
    }

    return nodes.front();
}

void doTable(Node* root, vector<bool>& code, map<char, vector<bool>>& matchingTable) {
    if (root->left != nullptr) {
        code.push_back(0);
        doTable(root->left, code, matchingTable);
    }

    if (root->right != nullptr) {
        code.push_back(1);
        doTable(root->right, code, matchingTable);
    }

    if (root->left == nullptr && root->right == nullptr) {
        matchingTable[root->symbol[0]] = code;
    }

    if (!code.empty()) {
        code.pop_back();
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<char, int> counter;
    map<char, vector<bool>> matchingTable;
    list<Node*> nodes;
    vector<bool> code;
    string text;

    getline(cin, text);
    int size = text.size();
    for (int i = 0; i < size; i++) {
        counter[text[i]]++;
    }
    cout << "\nЧастота:\n";
    for (auto it = counter.begin(); it != counter.end(); it++) {
        cout << '\'' << it->first << '\'' << " -> " << it->second << endl;
        Node* node = new Node;
        node->symbol += it->first;
        node->frequency = it->second;
        node->left = nullptr;
        node->right = nullptr;
        nodes.push_back(node);
    }
    cout << endl;
    Node* root = HuffmanAlgorithm(nodes);
    doTable(root, code, matchingTable);



    cout << "\nКоды символов:\n";
    for (const auto& itm : matchingTable) {
        cout << '\'' << itm.first << '\'' << " = ";
        int tempSize = itm.second.size();
        for (int i = 0; i < tempSize; i++) {
            cout << itm.second[i];
        }
        cout << endl;
    }
    cout << "\nКод строки: ";
    for (int i = 0; i < size; i++) {
        const vector<bool>& temp = matchingTable.at(text[i]);
        int sizeTemp = temp.size();
        for (int j = 0; j < sizeTemp; j++) {
            cout << temp[j];
        }
    }
    cout << endl;


    return 0;
}