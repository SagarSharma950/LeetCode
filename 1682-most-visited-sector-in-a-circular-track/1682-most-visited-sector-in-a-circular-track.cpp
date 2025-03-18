class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        if(rounds[0]<=rounds[rounds.size()-1]){
            for(int i=rounds[0];i<=rounds[rounds.size()-1];i++) res.push_back(i);
            return res;
        }
        else{
            for(int i=1;i<=rounds[rounds.size()-1];i++) res.push_back(i);
            for(int i=rounds[0];i<=n;i++) res.push_back(i);
        }
        return res;
    }
};