class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) 
            return a;
        return gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mpp;
        for (auto it : deck) 
            mpp[it]++;
        int ans = 0;
        for (auto it : mpp) 
            ans = gcd(it.second, ans);
        return ans > 1;
    }
};