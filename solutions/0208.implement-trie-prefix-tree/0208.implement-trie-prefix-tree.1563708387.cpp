struct TrieNode {
    bool tailHere;
    TrieNode* children[26];
    
    TrieNode() {
        tailHere = false;
        for (auto& c : children) {
            c = nullptr;
        }
    }
    
    TrieNode* addChar(char c) {
        int i = c - 'a';
        if (children[i] == nullptr) {
            children[i] = new TrieNode();
        }
        return children[i];
    }
    
    bool hasChar(char c) {
        int i = c - 'a';
        return children[i] != nullptr;
    }
    
    TrieNode* forwardChar(char c) {
        int i = c - 'a';
        return children[i];
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            p = p->addChar(c);
        }
        p->tailHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (!p->hasChar(c)) {
                return false;
            }
            p = p->forwardChar(c);
        }
        return p->tailHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            if (!p->hasChar(c)) {
                return false;
            }
            p = p->forwardChar(c);
        }
        return true;
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
