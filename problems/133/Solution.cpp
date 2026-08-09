// 133. Clone Graph

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        vector<Node*> cloned(101, nullptr);
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            auto current = s.top();
            s.pop();
            if (!cloned[current->val]) {
                cloned[current->val] = new Node(current->val);            
            }
            
            for (auto next : current->neighbors) {
                if (!cloned[next->val]) {
                    cloned[next->val] = new Node(next->val);
                    s.push(next);
                }
                cloned[current->val]->neighbors.push_back(cloned[next->val]);
            }
        }        
        
        return cloned[node->val];
    }
};
