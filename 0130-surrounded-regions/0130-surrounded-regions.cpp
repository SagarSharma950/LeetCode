class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=board.size()|| j>=board[0].size() || board[i][j]!='O') return;
        board[i][j]='#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[board.size()-1][j]=='O') dfs(board,board.size()-1,j);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=board[i][j]!= '#' ? 'X' : 'O';
            }
        }
    }
};