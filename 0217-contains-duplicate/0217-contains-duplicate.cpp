class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> st;
        for(int i=0;i<nums .size();i++){
            st[nums[i]]++;
        }
        for(auto it: st){
            if(it.second>1) return true;
        }
        return false;
    }
};