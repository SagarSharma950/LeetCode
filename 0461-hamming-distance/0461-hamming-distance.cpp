class Solution {
public:
    int hammingDistance(int x, int y) {
        x=x^y;
        int cnt=0;
        while(x!=0){
            if(x%2==1) cnt++;
            x=x/2;
        }
        return cnt;
    }
};