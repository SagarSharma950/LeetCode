class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;

        long long low = 0;
        long long high = total / n;
        while (low < high) {
            long long mid = low + (high - low + 1) / 2;
            long long usable = 0;
            for (int b : batteries) {
                usable += min<long long>(b, mid);
                if (usable >= mid * n) break;
            }

            if (usable >= mid * n) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};