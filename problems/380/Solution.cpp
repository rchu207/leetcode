// 380. Insert Delete GetRandom O(1)
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (indices.count(val)) return false;
        indices[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!indices.count(val)) return false;
        int idx = indices[val];
        int last = nums.back();
        nums[idx] = last;
        indices[last] = idx;
        nums.pop_back();
        indices.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> indices; // val -> index in nums
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
