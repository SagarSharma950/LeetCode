class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c = 0;
        for (const string& s : patterns)    c += word.contains(s);
        return c;
    }
};