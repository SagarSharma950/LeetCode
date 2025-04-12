class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int gap=0;
        for(int i=1;i<nums.size();i++){
            int sub=nums[i]-nums[i-1];
            if(sub>gap) gap=sub;
        }
        return gap;
    }
};