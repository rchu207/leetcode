// 3941. Password Strength

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> strength;
        for (auto& c : password) {
            strength.insert(c);
        }
        int points = 0;
        for (auto& c : strength) {
            if (c >= 'a' && c <= 'z') {
                points += 1;
            } else if (c >= 'A' && c <= 'Z') {
                points += 2;
            } else if (c >= '0' && c <= '9') {
                points += 3;
            } else {
                points += 5;
            }
        }
        return points;
    }
};
