// 336. Palindrome Pairs
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        int wordId = -1;

        TrieNode() {
        }

        ~TrieNode() {
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr) {
                    delete children[i];
                }
            }
        }
    };

    TrieNode* root;

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void insert(const string& word, int wordId) {
        TrieNode* curr = root;
        for (int j = word.length() - 1; j >= 0; --j) {
            int idx = word[j] - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->wordId = wordId;
    }

    void dfsFindPalindromes(TrieNode* curr, string& path, int currWordId, vector<vector<int>>& res) {
        if (curr == nullptr) return;

        if (curr->wordId != -1 && curr->wordId != currWordId) {
            if (isPalindrome(path, 0, path.length() - 1)) {
                res.push_back({currWordId, curr->wordId});
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (curr->children[i] != nullptr) {
                path.push_back('a' + i);
                dfsFindPalindromes(curr->children[i], path, currWordId, res);
                path.pop_back();
            }
        }
    }

    void search(const string& word, int wordId, vector<vector<int>>& res) {
        TrieNode* curr = root;
        int n = word.length();

        for (int j = 0; j < n; ++j) {
            if (curr->wordId != -1 && isPalindrome(word, j, n - 1)) {
                res.push_back({wordId, curr->wordId});
            }

            int idx = word[j] - 'a';
            if (curr->children[idx] == nullptr) return;
            curr = curr->children[idx];
        }

        string path = "";
        dfsFindPalindromes(curr, path, wordId, res);
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        vector<vector<int>> res;

        for (int i = 0; i < words.size(); ++i) {
            insert(words[i], i);
        }

        for (int i = 0; i < words.size(); ++i) {
            search(words[i], i, res);
        }

        delete root;
        return res;
    }
};
