class Solution {
public:
    char findKthBit(int n, unsigned k) {
        return k==1?'0':((k&(k-1))==0?'1':'0'+1-(findKthBit(n, (1<<(bit_width(k)))-k)-'0'));
    }
};
