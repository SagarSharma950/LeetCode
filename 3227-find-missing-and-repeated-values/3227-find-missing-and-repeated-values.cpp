class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int a=grid.size();int b=grid[0].size();
        int s=a*b;     
        vector<int> res(2,0);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                mp[grid[i][j]]++;
            }
        }
        for(auto it: mp){
            if(it.second==2) res[0]=it.first;
        }
        for(int i=1;i<=s;i++){
            if(mp.find(i)==mp.end()) res[1]=i;
        }
        return res;
    }
};