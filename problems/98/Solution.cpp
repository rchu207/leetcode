class Solution {
private:
    bool validate(TreeNode* root, pair<long, long> range) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val < range.first || root->val > range.second) {
            return false;
        }

        auto leftRange = std::make_pair(range.first, (long)root->val - 1);
        auto rightRange = std::make_pair((long)root->val + 1, range.second);
        return validate(root->left, leftRange) && validate(root->right, rightRange);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        auto leftRange = std::make_pair(-2147483648, (long)root->val - 1);
        auto rightRange = std::make_pair((long)root->val + 1, 2147483648 - 1);
        return validate(root->left, leftRange) && validate(root->right, rightRange);
    }
};
