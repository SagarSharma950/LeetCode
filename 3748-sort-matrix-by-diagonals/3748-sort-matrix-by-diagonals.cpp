class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int key = i - j;
                mp[key].push_back(grid[i][j]);
            }
        }
        for(auto &p : mp) {
            int key = p.first;
            if(key < 0) {
                sort(p.second.begin(), p.second.end());
            } else {
                sort(p.second.begin(), p.second.end(), greater<int>()); 
            }
        }
        unordered_map<int, int> idx; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int key = i - j;
                grid[i][j] = mp[key][idx[key]++];
            }
        }
        return grid;
    }
};