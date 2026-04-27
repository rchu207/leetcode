class Node {
public:
    int val;
    int count;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->count = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class KthLargestBst {
public:
    KthLargestBst(int k, vector<int>& nums) : target(k) {
        for (auto& val : nums) {
            root = insert(root, val);
        }
    }
    
    int add(int val) {
        root = insert(root, val);
        return find(root, target);
    }

private:
    Node* root = nullptr;
    int target;
    
    int getCount(Node* node) {
        if (node)
            return node->count;
        else
            return 0;
    }
    
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val <= node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        
        node->count = 1 + getCount(node->left) + getCount(node->right);
        return node;
    }
    
    int find(Node* node, int k) {
        int rightCount = getCount(node->right);
        
        if (k == rightCount + 1) {
            return node->val;
        } else if (k <= rightCount) {
            return find(node->right, k);
        } else {
            return find(node->left, k - (rightCount + 1));
        }
    }
};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for (auto& v : nums) {
            add(v);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > kSize)
            pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kSize;
};
