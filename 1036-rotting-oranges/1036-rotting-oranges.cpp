class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) cnt++;
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int flag=0;
        while(!q.empty() && cnt>0){
            int s=q.size();
            flag++;
            while(s--){
                auto[x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if(newX >=0 and newX<grid.size() and newY>=0 and newY<grid[0].size() and grid[newX][newY]==1)
                    {
                        grid[newX][newY] = 2;
                        q.push({newX,newY});
                        cnt--;
                    }
                }
            }
        }
        return cnt==0?flag:-1;
    }
};