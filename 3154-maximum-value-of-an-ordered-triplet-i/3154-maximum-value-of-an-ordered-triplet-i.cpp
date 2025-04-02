class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxdiff=0;
        long maxtri=0;
        long maxele=0;
        for(long num:nums){
            maxtri=max(maxtri,maxdiff*num);
            maxdiff=max(maxdiff,maxele-num);
            maxele=max(maxele,num);
        }
        return maxtri;
    }
};