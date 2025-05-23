class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> cnt;
        for(auto it:mp){
            if(it.second>(n/3)) cnt.push_back(it.first);
        }
        return cnt;;
    }
};