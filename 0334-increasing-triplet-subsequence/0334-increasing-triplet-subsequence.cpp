class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one=INT_MAX, sec=INT_MAX;
        for(int num:nums){
            if(num<=one) one =num;
            else if(num<=sec) sec=num;
            else return true;
        }
        return false;
    }
};