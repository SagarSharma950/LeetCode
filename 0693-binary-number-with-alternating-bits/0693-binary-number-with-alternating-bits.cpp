class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int z=n ^ (n>>1);
        return (z & (z+1))==0;
    }
};