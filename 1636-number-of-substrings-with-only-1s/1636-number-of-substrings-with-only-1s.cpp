class Solution {
public:
    int numSub(string s) {
        long long mod=1e9+7;
        long long cnt=0;
        long long curr=0;
        for(char c:s){
            if(c=='1') curr++;
            else{
                cnt=(cnt+curr*(curr+1)/2)%mod;
                curr=0;
            }
        }
        cnt=(cnt+curr*(curr+1)/2)%mod;
        return cnt;
    }
};