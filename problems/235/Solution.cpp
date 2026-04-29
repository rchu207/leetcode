class Solution {
private:
    TreeNode* resursion(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root && p && q) {
            if (p->val < root->val && q->val < root->val) {
                return resursion(root->left, p, q);
            } else if (p->val > root->val && q->val > root->val) {
                return resursion(root->right, p, q);
            }
        }
        return root;
    }

    TreeNode* iteration(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto iter = root;
        while (iter && p && q) {
            if (p->val < iter->val && q->val < iter->val) {
                iter = iter->left;
            } else if (p->val > iter->val && q->val > iter->val) {
                iter = iter->right;
            } else {
                return iter;
            }
        }
        return iter;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return resursion(root, p, q);
        return iteration(root, p, q);
    }
};
