class Solution {
private:
    TreeNode* recursion(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = recursion(root->left, key);
        } else if (key > root->val) {
            root->right = recursion(root->right, key);
        } else if (root->left == nullptr) {
            auto tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            auto tmp = root->left;
            delete root;
            return tmp;
        } else {
            auto successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            std::swap(root->val, successor->val);
            root->right = recursion(root->right, key);            
        }

        return root;
    }
    
    TreeNode* iteration(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* iter = root;
        
        while (iter != nullptr && iter->val != key) {
            parent = iter;
            if (key < iter->val)
                iter = iter->left;
            else
                iter = iter->right;
        }
        if (iter == nullptr) {
            return root;
        }
        
        TreeNode* replacement = nullptr;
        
        if (iter->left == nullptr || iter->right == nullptr) {
            replacement = (iter->left) ? iter->left : iter->right;
        } else {
            auto successorParent = iter;
            auto successor = iter->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }            
            
            iter->val = successor->val;
            
            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;;
            }
            delete successor;
            return root;
        }
        
        if (parent == nullptr) {
            delete iter;
            return replacement;
        }
        if (parent->left == iter) {
            parent->left = replacement;
        } else {
            parent->right = replacement;
        }
        
        delete iter;
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // return recursion(root, key);
        return iteration(root, key);
    }
};
