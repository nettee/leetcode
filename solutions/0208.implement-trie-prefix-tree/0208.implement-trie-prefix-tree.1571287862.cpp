class Trie {
private:
    struct TrieNode {
        TrieNode** children;
        bool tailHere;
        
        TrieNode() {
            children = new TrieNode*[26];
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            tailHere = false;
        }
        
        ~TrieNode() {
            delete[] children;  
        }
    };
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int d = c - 'a';
            if (node->children[d] == nullptr) {
                node->children[d] = new TrieNode();
            }
            node = node->children[d];
        }
        node->tailHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = searchNode(word);
        return node != nullptr && node->tailHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = searchNode(prefix);
        return node != nullptr;
    }
    
    TrieNode* searchNode(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node == nullptr) {
                return nullptr;
            }
            node = node->children[c - 'a'];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
