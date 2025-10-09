class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> time(n, 0);
        vector<long long> diffarr(n + 1, 0);
        for (long long i : mana) {
            time[0] += i * skill[0]; 
            for (int j = 1; j < n; ++j) {
                long long diff = max(time[j] - time[j - 1], 0ll);
                time[j] = max(time[j - 1], time[j]) + i * skill[j];
                diffarr[0] += diff;
                diffarr[j] -= diff;
            }
            for (int j = 0; j < n; ++j) {
                diffarr[j + 1] += diffarr[j];
                time[j] += diffarr[j];
                diffarr[j] = 0;
            }
        }
        return time.back();
    }
};