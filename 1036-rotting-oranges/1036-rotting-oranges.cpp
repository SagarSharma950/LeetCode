class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<pair<int,int>> curr;
        vector<pair<int,int>> newRotten;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if( grid[i][j] == 2 ){
                    curr.push_back( {i,j} );
                }
            }
        }
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if( grid[i][j] == 1 ){
                    fresh++;
                }
            }
        }
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        while( true ){
            if(fresh == 0){
                return count;
            }
            if( curr.empty() ){
                break;
            }
            count++;
            for( auto it : curr ){
                int row = it.first;
                int col = it.second;
                for(int k = 0; k<4; k++){
                    int nrow = row + delrow[k];
                    int ncol = col + delcol[k];
                    if( nrow<0 || ncol<0 || nrow>=m || ncol>=n ){
                        continue;
                    }
                    if( grid[nrow][ncol] == 1 ){
                        newRotten.push_back( {nrow,ncol} );
                        grid[nrow][ncol] = 2;
                        fresh = fresh - 1;
                    }
                }
            }
            curr = newRotten;
            newRotten.clear();
        }
        return -1;
    }
};