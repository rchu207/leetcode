// 347. Top K Frequent Elements

class Solution {
private:
    vector<int> countingByFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> frequency;
        for (auto& v : nums) {
            frequency[v]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto& f : frequency) {
            buckets[f.second].push_back(f.first);
        }
        
        vector<int> answer;
        for (int i = n; i >= 1; i--) {
            for (auto& b : buckets[i]) {
                answer.push_back(b);
                k--;
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }
        return answer;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return countingByFrequency(nums, k);
    }
};
