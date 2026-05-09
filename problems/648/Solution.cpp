// 648. Replace Words

struct TrieNode {
    unordered_map<char, shared_ptr<TrieNode>> children;
    bool isWord = false;
};

class Trie {
public:
    Trie() {
       root = std::make_shared<TrieNode>();
    }
    
    void insert(const string& word) {
        auto iter = root;
        for (auto& c : word) {
            if (iter->children[c] == nullptr) {
                iter->children[c] = std::make_shared<TrieNode>();
            }
            iter = iter->children[c];
        }
        iter->isWord = true;
    }
    
    vector<char> replace(const string& word) {
        vector<char> path;
        auto iter = root;
        int n = word.length();
        int i;
        for (i = 0; i < n; ++i) {
            auto& c = word[i];
            if (iter->isWord) {
                // a root is found
                break;
            } else if (iter->children[c] == nullptr) {
                // no more nodes
                break;
            }

            // move to children
            path.push_back(c);
            iter = iter->children[c];
        }
        
        // a root is found
        if (iter->isWord) {
            return path;
        }

        // a root is not found, use original word
        while (i < n) {
            auto& c = word[i];
            path.push_back(c);
            ++i;
        }
        return path;
    }
    
private:
    shared_ptr<TrieNode> root;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // cut sentence to words
        istringstream iss(sentence);
        string word;
        vector<string> words;
        while (iss >> word) {
            words.push_back(word);
        }

        // build Trie tree
        Trie* trie = new Trie();
        for (auto& w : dictionary) {
            trie->insert(w);
        }
        
        // replace words
        vector<char> answer;
        for (int i = 0; i < words.size(); i++) {
            auto replacedWord = trie->replace(words[i]);
            if (i > 0) {
                answer.push_back(' ');
            }
            answer.insert(answer.end(), replacedWord.begin(), replacedWord.end());
        }
        return string(answer.begin(), answer.end());
    }
};
