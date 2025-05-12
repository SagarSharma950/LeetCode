class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int top=0, bottom=mat.size()-1,left=0,right=mat[0].size()-1, num=1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++) mat[top][i]=num++;
            top++;
            for(int i=top;i<=bottom;i++) mat[i][right]=num++;
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--) mat[bottom][i]=num++;
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--) mat[i][left]=num++;
                left++;
            }
        }   
        return mat;
    }
};