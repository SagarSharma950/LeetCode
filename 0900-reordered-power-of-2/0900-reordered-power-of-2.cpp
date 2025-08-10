class Solution {
public:
    string countDigits(int n) {
        string cnt(10, '0'); 
        while (n > 0) {
            cnt[n % 10]++;
            n /= 10;
        }
        return cnt;
    }
    bool reorderedPowerOf2(int n) {
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) { 
            int power = 1 << i;
            if (countDigits(power) == target)
                return true;
        }
        return false;
    }
};
