class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.length();right++){
            char c=s[right];
            if(mp.find(c)!=mp.end() && left<=mp[c]) left=mp[c]+1;
            mp[c]=right;    
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};