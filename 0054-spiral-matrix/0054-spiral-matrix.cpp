class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> mat;
        int top=0, bottom=matrix.size()-1, left=0, right=matrix[0].size()-1;
        if(matrix.empty()) return mat;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++) mat.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bottom;i++) mat.push_back(matrix[i][right]);
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--) mat.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--) mat.push_back(matrix[i][left]);
                left++;
            }
        }
        return mat;
    }
};