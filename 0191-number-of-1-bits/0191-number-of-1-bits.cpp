class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n!=0){
            int r=n%2;
            if(r==1) cnt++;
            n=n/2;
        }
        return cnt;
    }
};