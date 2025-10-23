class Solution {
public:
    bool hasSameDigits(string s) {
           vector<int> digits;
        for (char c : s) {
            digits.push_back(c - '0');
        }
        while (digits.size() > 2) {
            vector<int> new_digits;
            for (size_t i = 0; i < digits.size() - 1; i++) {
                new_digits.push_back((digits[i] + digits[i + 1]) % 10);
            }
            digits = move(new_digits); 
        }
        return digits[0] == digits[1];
    }
};