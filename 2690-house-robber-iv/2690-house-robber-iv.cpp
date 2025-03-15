class Solution {
public:
     bool canRob(vector<int>& nums, int k, int cap) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= cap) { 
                count++;
                i++; 
            }
            if (count >= k) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canRob(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};