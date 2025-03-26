class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int j=target-nums[i];
            if(mpp.count(j)) return {mpp[j],i};
            mpp[nums[i]]=i;
        }
        return {};
    }
};
