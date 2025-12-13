#include <bits/stdc++.h>
using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Traverse tree and store codes
void huffmanCodes(Node* root, string str, unordered_map<char,string>& codes) {
    if(!root) return;
    if(!root->left && !root->right) {
        codes[root->ch] = str;
    }
    huffmanCodes(root->left, str+"0", codes);
    huffmanCodes(root->right, str+"1", codes);
}

// Build Huffman Tree
unordered_map<char,string> buildHuffman(string text) {
    // Count frequency
    unordered_map<char,int> freq;
    for(char c:text) freq[c]++;

    // Min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto it:freq) pq.push(new Node(it.first, it.second));

    while(pq.size()>1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    // Generate codes
    unordered_map<char,string> codes;
    huffmanCodes(root, "", codes);
    return codes;
}

int main() {
    string text = "huffman coding example";

    auto codes = buildHuffman(text);

    cout << "Huffman Codes:\n";
    for(auto it: codes)
        cout << it.first << ": " << it.second << "\n";

    // Encode text
    string encoded = "";
    for(char c:text) encoded += codes[c];
    cout << "Encoded text: " << encoded << "\n";

    return 0;
}
