// 2265. Count Nodes Equal to Average of Subtree

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    pair<int, int> dfs(TreeNode* root, int& answer) {
        if (!root) {
            return {0, 0};
        }

        auto left = dfs(root->left, answer);
        auto right = dfs(root->right, answer);
        auto sum = root->val + left.first + right.first;
        auto count = 1 + left.second + right.second;
        int average = (int)(sum / count);
        if (root->val == average) {
            answer++;
        }
        return {sum, count};
    }
};
