// 652. Find Duplicate Subtrees

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return answer;
    }

private:
    unordered_map<string, int> hashmap;
    vector<TreeNode*> answer;
    
    string serialize(TreeNode* node) {
        if (node == nullptr) {
            return "#";
        }
        
        // use pre-order traversal
        string s = std::to_string(node->val) + "-" + serialize(node->left) + "-" + serialize(node->right);
        hashmap[s]++;
        if (hashmap[s] == 2)
            answer.push_back(node);
        return s;
    }
};
