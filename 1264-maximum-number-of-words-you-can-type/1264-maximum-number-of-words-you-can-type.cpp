class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> bro(brokenLetters.begin(), brokenLetters.end());
        int cnt=0;
        bool flag=true;
        for(int i=0;i<text.size();i++){
            if(bro.count(text[i])) flag=false;
            if(i==text.size()-1 || text[i]==' '){
                if(flag) cnt++;
                flag=true;
            }
        }
        return cnt;
    }
};