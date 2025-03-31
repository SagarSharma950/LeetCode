class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }
        int gcdValue = 0;
        for (auto& [_, freq] : count) {
            gcdValue = gcd(gcdValue, freq);
        }
        return gcdValue > 1;
    }
};