class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> res;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num=='.') continue;
                string rk=string(1,num)+" in row "+to_string(i);
                string ck=string(1,num)+" in col "+to_string(j);
                string bk=string(1,num)+" in box "+to_string(i/3)+"-"+to_string(j/3);
                if(res.count(rk) ||res.count(ck) || res.count(bk)) return false;
                res.insert(rk);
                res.insert(ck);
                res.insert(bk);
            }
        }   
        return true;
    }
};