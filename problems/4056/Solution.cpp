// 4056. Number of Intersecting Interval Pairs I

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];
        std::sort(starts.begin(), starts.end());

        long long disjoint = 0;
        for (auto& in : intervals)
            disjoint += starts.end() - std::upper_bound(starts.begin(), starts.end(), in[1]);

        return (long long)n * (n - 1) / 2 - disjoint;
    }
};
