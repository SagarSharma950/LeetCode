class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        unordered_map<char, int> ans;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (ans.count(s[right]) && ans[s[right]] >= left) {
                left = ans[s[right]] + 1; 
            }
            ans[s[right]] = right;
            maxLen = max(maxLen, right - left + 1); 
        }
        return maxLen;
    }
};
