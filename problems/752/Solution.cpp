// 752. Open the Lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        int step = 0;
        unordered_set<string> visit;
        for (auto& s : deadends) {
            visit.insert(s);
        }
        
        if (visit.insert("0000").second) {
            q.push("0000");
        }

        while (!q.empty()) {
            auto count = q.size();
            for (int i = 0; i < count; i++) {
                auto digits = q.front();
                q.pop();
                if (digits == target) {
                    return step;
                }
                
                for (int j = 0; j < 4; j++) {
                    auto n = digits[j] - '0';
                    digits[j] = (n + 1) % 10 + '0';
                    if (visit.insert(digits).second) {
                        q.push(digits);
                    }
                    digits[j] = (n == 0) ? '9' : ((n - 1) % 10 + '0');
                    if (visit.insert(digits).second) {
                        q.push(digits);
                    }
                    digits[j] = n + '0';
                }
            }
            step++;
        }
        return -1;
    }
};
