class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<=nums.size()-k;i++){
            set<int> uniqueElements;
        for (int j = i; j < i + k; ++j) {
            uniqueElements.insert(nums[j]);
        }
        for (int num : uniqueElements) {
            mp[num]++;
        }
        }
        int largest = -1;
    for (const auto& [num, count] : mp) {
        if (count == 1) {
            largest = max(largest, num);
        }
    }
    
    return largest;
        
    }
};