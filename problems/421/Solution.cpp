// 421. Maximum XOR of Two Numbers in an Array
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[2] = {};
};

class Solution {

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int n : nums) {
            TrieNode* node = root;
            for (int bit = 31; bit >= 0; bit--) {
                int b = (n >> bit) & 1;
                if (!node->children[b])
                    node->children[b] = new TrieNode();
                node = node->children[b];
            }
        }

        int answer = 0;
        for (int n : nums) {
            TrieNode* node = root;
            int xorVal = 0;
            for (int bit = 31; bit >= 0; bit--) {
                int b = (n >> bit) & 1;
                int want = 1 - b;
                if (node->children[want]) {
                    xorVal |= (1 << bit);
                    node = node->children[want];
                } else {
                    node = node->children[b];
                }
            }
            answer = max(answer, xorVal);
        }

        return answer;
    }
};
