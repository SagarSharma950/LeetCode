class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        map<int,int> map;
        for(int i=0;i<n;i++) 
        {
            if(nums[i]<0){
                int d=abs(nums[i])/value;
                int rem=abs(nums[i])%value;
                nums[i]+=(value*d);
                if(rem) nums[i]+=value;
            }
            map[nums[i]%value]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(map.count(i%value)){
                ans++;
                map[i%value]--;
                if(map[i%value]==0) map.erase(i%value);
            }
            else break;
        }
        return ans;
    }
};