class Solution {
private:
    void recursion(TreeNode* root, int val) {
        if (root) {
            if (val < root->val) {
                if (root->left) {
                    recursion(root->left, val);
                } else {
                    root->left = new TreeNode(val);                    
                }
            } else {
                if (root->right) {
                    recursion(root->right, val);                    
                } else {
                    root->right = new TreeNode(val);                    
                }
            }
        }
    }
    
private:
    void iteration(TreeNode* root, int val) {
        while (root) {
            if (val < root->val) {
                if (root->left) {
                    root = root->left;
                } else {
                    root->left = new TreeNode(val);
                    root = nullptr;
                }
            } else {
                if (root->right) {
                    root = root->right;
                } else {
                    root->right = new TreeNode(val);
                    root = nullptr;
                }
            }
        }
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root) {
            // recursion(root, val);
            iteration(root, val);
        } else {
            root = new TreeNode(val);
        }
        return root;
    }
};
