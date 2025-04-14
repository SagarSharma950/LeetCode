class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int cnt=0;               // a+b=d-c
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]+nums[j]].push_back(j);
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                int sum=nums[i]-nums[j];
                for(int k:mpp[sum]){
                    if(k<j) cnt++;
                }
            }
        }
        return cnt;
    }
};