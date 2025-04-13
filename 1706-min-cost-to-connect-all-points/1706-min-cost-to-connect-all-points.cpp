class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> mst(n,false);
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        int tc=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!mst[j] && (u==-1 || dist[j]<dist[u])) u=j;
            }
        mst[u]=true;
        tc+=dist[u];
        for(int i=0;i<n;i++){
            if(!mst[i]){
                int d=abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
                dist[i]=min(dist[i],d);
            }
        }
        }
        return tc;
    }
};