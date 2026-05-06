#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;  // modern C++
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // smallest freq has highest priority
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // If leaf node
    if (!root->left && !root->right) {
        cout << root->data << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    // Min Heap (Priority Queue)
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Input characters and frequencies
    for (int i = 0; i < n; i++) {
        char ch;
        int f;
        cout << "Character and frequency: ";
        cin >> ch >> f;

        minHeap.push(new Node(ch, f));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); 
        minHeap.pop();

        Node* right = minHeap.top(); 
        minHeap.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}