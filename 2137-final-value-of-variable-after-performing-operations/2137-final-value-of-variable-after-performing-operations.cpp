class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i].contains('-')) res--;
            if(operations[i].contains('+')) res++;
        }   
        return res;
    }
};