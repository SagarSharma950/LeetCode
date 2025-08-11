class Solution {
public:
    int m=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> pow;
        for(int i=0;i<32;i++){
            if((n & (1<<i)) != 0) pow.push_back(1<<i);
        }
        for(auto& query:queries){
            int st=query[0];
            int end=query[1];
            long pro=1;
            for(int i=st;i<=end;i++){
                pro=(pro*pow[i])%m;
            }
            res.push_back(pro);
        }
        return res;
    }
};