class Solution {
public:
    int bsearch(vector<int> &a, long long success, int spell) {
        int s = 0, e = a.size(); 
        while (s < e) {
            int mid = s + (e - s) / 2;
            if ((long long)a[mid] * spell >= success)
                e = mid;
            else
                s = mid + 1;
        }
        return s; 
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            long long curr_succ = 1;
            int idx = bsearch(potions, success, spells[i]);
            if(idx < m && idx >= 0) ans[i] = m - idx;
            else ans[i] = 0;
        }
        return ans;
    }
};