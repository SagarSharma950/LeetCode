class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fre(26,0);
        int left=0, maxlen=0, maxfre=0;
        for(int right=0;right<s.size();right++){
            fre[s[right]-'A']++;
            maxfre=max(maxfre,fre[s[right]-'A']);
            while((right-left+1)-maxfre>k){
                fre[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};