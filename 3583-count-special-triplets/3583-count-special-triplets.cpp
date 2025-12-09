class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7;
        unordered_map<int, int> suff;
        unordered_map<int, int> pre;
        long long res=0;
        for(auto x: nums) suff[x]+=1;
        for(auto x: nums){
            suff[x]-=1;
            res+=(long long) pre[2*x]* suff[2*x];
            pre[x]+=1;
        }
        return res%mod;
        
    }
};