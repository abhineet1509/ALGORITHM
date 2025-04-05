#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
    
    bool removeHelper(TrieNode* node, string word, int depth) {
        if (!node)
            return false;
        
        if (depth == word.size()) {
            if (!node->isEndOfWord)
                return false;
            node->isEndOfWord = false;
            return isEmpty(node);
        }
        
        int index = word[depth] - 'a';
        if (removeHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEndOfWord && isEmpty(node);
        }
        return false;
    }
    
    void remove(string word) {
        removeHelper(root, word, 0);
    }
    
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i])
                return false;
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << "Search apple: " << trie.search("apple") << endl;
    cout << "Search app: " << trie.search("app") << endl;
    trie.remove("apple");
    cout << "Search apple after removal: " << trie.search("apple") << endl;
    cout << "Search app after removal: " << trie.search("app") << endl;
    return 0;
}
