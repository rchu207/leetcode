// 3955. Valid Binary Strings With Cost Limit

class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<char> sequence(16);
        vector<string> answer;

        backtrack(n, k, 0, 0, sequence, answer);
        return answer;
    }

private:
    void backtrack(int n, int k, int length, int cost, vector<char>& sequence, vector<string>& answer) {
        if (cost > k) {
            return;
        }
        if (length == n) {
            string s(sequence.begin(), sequence.end());
            answer.push_back(s);
            return;
        }
        
        // use 0
        sequence[length] = '0';
        backtrack(n, k, length + 1, cost, sequence, answer);

        // use 1
        if (length == 0 || sequence[length - 1] != '1') {
            sequence[length] = '1';
            backtrack(n, k, length + 1, cost + length, sequence, answer);
        }
    }
};
