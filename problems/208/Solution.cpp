struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool done = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto iter = root;
        for (auto& c : word) {
            if (iter->children.count(c) == 0) {
                iter->children[c] = new TrieNode();
            }
            iter = iter->children[c];
        }
        iter->done = true;
    }
    
    bool search(string word) {
        auto iter = root;
        for (auto& c : word) {
            if (iter->children.count(c) > 0) {
                iter = iter->children[c];
            } else {
                return false;
            }
        }
        
        return iter->done;
    }
    
    bool startsWith(string prefix) {
        auto iter = root;
        for (auto& c : prefix) {
            if (iter->children.count(c) > 0) {
                iter = iter->children[c];
            } else {
                return false;
            }
        }
        
        return true;
    }

private:
    TrieNode* root;
    unordered_map<char, TrieNode*> children;
};
