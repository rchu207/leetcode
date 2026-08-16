// 841. Keys and Rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlocked(n, false);
        stack<int> keys;
        keys.push(0);
        unlocked[0] = true;
        while (!keys.empty()) {
            auto key = keys.top();
            keys.pop();
            for (auto& k : rooms[key]) {
                if (!unlocked[k]) {
                    unlocked[k] = true;
                    keys.push(k);
                }
            }
        }
        
        for (auto u : unlocked) {
            if (!u)
                return false;
        }
        return true;
    }
};
