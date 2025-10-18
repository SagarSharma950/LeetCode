class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<long long, int> mp;  
        for (int x : nums) {
            mp[x]++;
        }
        if(k==0){
            return mp.size();
        }
        
        long long minused = 0;  
        long long res = 0;
        bool first = true;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            long long val = it->first;
            long long cnt = it->second;
            long long maxnumber = val + k;
            long long minnumber = val - k;

            if (first) {
                first = false;
                minused = val - k;
                if (cnt >= (2LL * k + 1)) {
                    minused = maxnumber;
                    res += (2LL * k + 1);
                } else {
                    res += cnt;
                    minused = (minnumber + cnt)-1;
                }
            } else {
                if(minused < minnumber){
                    minused=minnumber-1;
                }
                if (cnt >= (maxnumber - minused)) {
                    res += (maxnumber - minused);
                    minused = maxnumber;
                } else {
                    res += cnt;
                    minused = minused + cnt;
                }
            }

            cout<<it->first<<" "<<minused<<" "<<res<<endl;
        }
        return (int)res;  
    }
};