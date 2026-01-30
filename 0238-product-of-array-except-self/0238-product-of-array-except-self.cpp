class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int pre=1;
        int suff=1;
        for(int i=0;i<nums.size();i++){
            res[i]=pre;
            pre*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            res[i]*=suff;
            suff*=nums[i];
        }
        return res;
    }
};