class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int lcm(int a, int b, int gcdVal) {
        return (1LL * a * b) / gcdVal; 
    }

    void customPush(stack<int>& st, int num) {
        while (!st.empty()) {
            int g = gcd(st.top(), num);
            if (g == 1) break;
            num = lcm(num, st.top(), g);
            st.pop();
        }
        st.push(num);
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for (int num : nums) {
            customPush(st, num);
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};