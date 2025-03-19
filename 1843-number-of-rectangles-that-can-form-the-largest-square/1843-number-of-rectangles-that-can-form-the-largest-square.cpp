class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN , cnt;
        for(int i=0;i<rectangles.size();i++){
            int side=min(rectangles[i][0],rectangles[i][1]);
            mp[side]++;
        }
        for(auto it:mp){
            if(it.first>maxi){
                maxi=it.first;
                cnt=it.second;
            }
        }
        return cnt;
    }
};