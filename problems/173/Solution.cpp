class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        TreeNode* node = root;
        while (node) {
            nodes.push(node);
            node = node->left;
        }
    }
    
    int next() {
        int value = 0;
        if (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            value = node->val;
            node = node->right;
            while (node) {
                nodes.push(node);
                node = node->left;
            }
        }
        return value;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }

private:
    TreeNode* root;
    stack<TreeNode*> nodes;
};
