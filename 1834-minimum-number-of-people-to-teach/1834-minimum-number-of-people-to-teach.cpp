class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        int j=1;
        for(int i=0;i<lang.size();i++){
            mp[j]=lang[i];
            j++;
        }
        unordered_set<int> badUsers;
        for(int i=0;i<nums.size();i++){
            int first=nums[i][0];
            int second=nums[i][1];
            if (mp.find(first) != mp.end() && mp.find(second) != mp.end()) {
                vector<int> &a = mp[first];
                vector<int> &b = mp[second];
                unordered_set<int> s(a.begin(), a.end());
                bool hasCommon = false;
                for (int val : b) {
                    if (s.count(val)) {
                    hasCommon = true;
                    break;
                    }
                }
            if (!hasCommon) {
               badUsers.insert(first);
               badUsers.insert(second);
            }
            }
        }
       if (badUsers.empty()) return 0;
        int ans = INT_MAX;
        for (int langId = 1; langId <= n; langId++) {
            int needTeach = 0;
            for (int user : badUsers) {
                vector<int> &knows = mp[user];
                if (find(knows.begin(), knows.end(), langId) == knows.end()) {
                    needTeach++;
                }
            }
            ans = min(ans, needTeach);
        }
        return ans;
    }
};