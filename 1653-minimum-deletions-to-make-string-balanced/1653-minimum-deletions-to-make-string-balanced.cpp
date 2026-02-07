class Solution {
public:
    int minimumDeletions(string s) {
        int bcnt=0;
        int del=0;
        for(char c:s){
            if(c=='b') bcnt++;
            else del=min(del+1, bcnt);
        }
        return del;
    }
};