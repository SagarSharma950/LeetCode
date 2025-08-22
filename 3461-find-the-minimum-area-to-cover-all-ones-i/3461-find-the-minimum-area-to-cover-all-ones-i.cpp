class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = m, minj = n;
        int maxi = 0, maxj = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mini = min(mini, i);
                    minj = min(minj, j);
                    maxi = max(maxi, i);
                    maxj = max(maxj, j);
                }
            }
        }
        int length = maxi - mini + 1;
        int breadth = maxj - minj + 1;
        return length * breadth;
    }
};