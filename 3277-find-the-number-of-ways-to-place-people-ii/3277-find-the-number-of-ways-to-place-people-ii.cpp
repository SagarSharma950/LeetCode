class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;

        auto lambda = [](vector<int> point1, vector<int> point2) {
            if (point1[0] == point2[0])
                return point1[1] > point2[1];
            return point1[0] < point2[0];
        };
        sort(points.begin(), points.end(), lambda);
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (y2 <= y1 && y2 > maxY) {
                    cnt++;
                    maxY = y2;
                }
            }
        }
        return cnt;
    }
};