#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        if (k == 26) return 1;
        vector<int> p1(n), m1(n), p2(n), m2(n);
        int p = 1, m = 0;
        for (int i = 0; i < n; ++i) {
            int cm = 1 << (s[i] - 'a');
            if (__builtin_popcount(m | cm) > k) {p++; m = cm;} else m |= cm;
            p1[i] = p; m1[i] = m;
        }
        p = 1; m = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cm = 1 << (s[i] - 'a');
            if (__builtin_popcount(m | cm) > k) {p++; m = cm;} else m |= cm;
            p2[i] = p; m2[i] = m;
        }
        int ans = p2[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                int ncm = 1 << j;
                int pb = i ? p1[i-1] : 0, mb = i ? m1[i-1] : 0;
                int pa = i+1<n ? p2[i+1] : 0, ma = i+1<n ? m2[i+1] : 0;
                int cp, cm;
                if (i == 0) {
                    cp = 1; cm = ncm;
                } else {
                    if (__builtin_popcount(mb | ncm) > k) {
                        cp = pb + 1; cm = ncm;
                    } else {
                        cp = pb; cm = mb | ncm;
                    }
                }
                int t = cp + pa;
                if (pa && __builtin_popcount(cm | ma) <= k) t--;
                ans = max(ans, t);
            }
        }
        return ans;
    }
};