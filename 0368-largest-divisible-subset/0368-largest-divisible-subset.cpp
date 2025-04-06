class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=0;
        int lastind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastind=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            temp.push_back(nums[lastind]);
        }
        return temp;
    }
};