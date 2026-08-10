// 94. Binary Tree Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == nullptr)
            return answer;

        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});

        while (!s.empty()) {
            auto [node, visited] = s.top();
            s.pop();

            if (!visited) {
                if (node->right) {
                    s.push({node->right, false});
                }
                s.push({node, true});
                if (node->left) {
                    s.push({node->left, false});
                }
            } else {
                answer.push_back(node->val);
            }
        }
        return answer;
    }
};
