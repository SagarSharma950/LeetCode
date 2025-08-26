class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l=0, maxcnt=0,res=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            maxcnt=max(maxcnt,freq[s[r]-'A']);
            while((r-l+1)-maxcnt>k){
                freq[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};