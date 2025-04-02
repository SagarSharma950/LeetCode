class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return "";
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+"#"+rev;
        vector<int>lps(temp.size(),0);
        for(int i=1,j=0;i<temp.size();i++){
            while(j>0 && temp[i]!=temp[j]) j=lps[j-1];
            if(temp[i]==temp[j]) j++;
            lps[i]=j;
        }
        int lps_len=lps.back();
        string suffix=s.substr(lps_len);
        reverse(suffix.begin(),suffix.end());
        return suffix+s;
    }
};