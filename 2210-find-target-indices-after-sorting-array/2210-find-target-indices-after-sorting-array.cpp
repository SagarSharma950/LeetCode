class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> res;
        if(first==nums.size() || nums[first]!=target) return res;
        for(int i=first;i<last;i++) res.push_back(i);
        return res;
    }
};