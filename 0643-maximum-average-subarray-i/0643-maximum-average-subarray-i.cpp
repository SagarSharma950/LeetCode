class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        long long csum=0;
        for(int i=0;i<k;i++) csum+=nums[i];
        long long maxsum=csum;
        for(int i=k;i<n;i++){
            csum+=nums[i]-nums[i-k];
            maxsum=max(maxsum, csum);
        }
        return (double) maxsum/k;
    }
};