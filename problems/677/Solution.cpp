// LeetCode: 677. Map Sum Pairs
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int val = 0;
    int sum = 0;
};

class MapSum {
public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        vector<TrieNode*> path;
        auto iter = root;
        path.push_back(iter);
        for (auto& c : key) {
            if (iter->children.count(c) == 0) {
                iter->children[c] = new TrieNode();
            }
            iter = iter->children[c];
            path.push_back(iter);
        }
        int delta = val - iter->val;
        iter->val = val;
        for (auto* node : path) {
            node->sum += delta;
        }
    }

    int sum(string prefix) {
        auto iter = root;
        for (auto& c : prefix) {
            if (iter->children.count(c) == 0) {
                return 0;
            }
            iter = iter->children[c];
        }
        return iter->sum;
    }

private:
    TrieNode* root;
};
