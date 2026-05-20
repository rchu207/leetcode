// 212. Word Search II
// Trie + DFS: build a trie of all words, then DFS from each cell,
// traversing the trie simultaneously to find all words in one pass.

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (auto& w : words) {
            TrieNode* iter = &root;
            for (char c : w) {
                if (iter->children.count(c) == 0)
                    iter->children[c] = new TrieNode();
                iter = iter->children[c];
            }
            iter->word = w;
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, &root, result);

        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || node->children.count(c) == 0)
            return;

        TrieNode* next = node->children[c];

        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word = ""; // clear to avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        int m = board.size(), n = board[0].size();
        const int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                dfs(board, ni, nj, next, result);
        }

        board[i][j] = c; // restore

        // Prune exhausted trie branches to speed up future searches
        if (next->children.empty()) {
            delete next;
            node->children.erase(c);
        }
    }
};
