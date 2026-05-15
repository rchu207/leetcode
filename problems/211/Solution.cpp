// 211. Design Add and Search Words Data Structure

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto iter = root;
        for (auto& c : word) {
            if (iter->children.count(c) == 0) {
                iter->children[c] = new TrieNode();
            }
            iter = iter->children[c];
        }
        iter->isWord = true;
    }
    
    bool search(string word) {
        return backtrack(word, 0, root);
    }

private:
    TrieNode* root;
    
    bool backtrack(string& word, int index, TrieNode* iter) {
        if (index >= word.length()) {
            return iter->isWord;
        }
        
        auto& c = word[index];
        if (c == '.') {
            // try all possible children nodes
            for (const auto& pair : iter->children) {
                if (pair.second && backtrack(word, index + 1, pair.second))
                    return true;
            }
            return false;
        } else if (iter->children.count(c) > 0) {
            return backtrack(word, index + 1, iter->children[c]);
        } else {
            return false;
        }
    }
};
