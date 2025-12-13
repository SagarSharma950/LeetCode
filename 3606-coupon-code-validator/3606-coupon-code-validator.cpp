class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    int n = code.size();
    vector<tuple<string, string>> validCoupons;
    static unordered_map<string, int> categoryOrder = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    auto isValidCode = [](const string& code) {
        if (code.empty()) return false;
        for (char c : code) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (isActive[i] &&
            isValidCode(code[i]) &&
            categoryOrder.count(businessLine[i])) {
            validCoupons.emplace_back(businessLine[i], code[i]);
        }
    }

    sort(validCoupons.begin(), validCoupons.end(), [&](auto& a, auto& b) {
        if (categoryOrder[get<0>(a)] != categoryOrder[get<0>(b)])
            return categoryOrder[get<0>(a)] < categoryOrder[get<0>(b)];
        return get<1>(a) < get<1>(b);
    });

    vector<string> result;
    for (auto& [line, c] : validCoupons)
        result.push_back(c);

    return result;
}
};