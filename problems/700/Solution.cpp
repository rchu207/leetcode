class Solution {
private:
    TreeNode* recursion(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        
        if (val == root->val) {
            return root;
        } else if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }        
    }
    
    TreeNode* iteration(TreeNode* root, int val) {
        while (root) {
            if (val == root->val) {
                return root;
            } else if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return iteration(root, val);
    }
};
