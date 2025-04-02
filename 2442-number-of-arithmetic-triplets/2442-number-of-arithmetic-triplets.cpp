class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int cnt=0;
        for(int i: nums){
            if(mp.count(i+diff) && mp.count(i+2* diff)) cnt++;  
        }
        return cnt;
    }
};