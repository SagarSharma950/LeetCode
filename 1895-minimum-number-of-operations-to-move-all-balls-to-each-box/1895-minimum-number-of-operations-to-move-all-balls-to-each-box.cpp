class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>box(n,0);
        int lmoves=0, lcnt =0;
        for(int i=0;i<n;i++){
            box[i]+=lmoves;
            if(boxes[i]=='1') lcnt++;
            lmoves+=lcnt;
        }
        int rmoves=0, rcnt=0;
        for(int i=n-1;i>=0;i--){
            box[i]+=rmoves;
            if(boxes[i]=='1') rcnt++;
            rmoves+=rcnt;
        }
        return box;
    }
};