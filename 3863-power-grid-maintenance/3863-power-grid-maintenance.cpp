class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);
        vector<int> rank(c + 1, 1);
        unordered_map<int, set<int>> online;  // root -> set of online station IDs

        // DSU init
        for (int i = 1; i <= c; ++i) {
            parent[i] = i;
            online[i].insert(i); // All stations initially online
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (rank[ra] < rank[rb]) swap(ra, rb);
            parent[rb] = ra;
            rank[ra] += rank[rb];

            // Merge online sets
            if (online[ra].size() < online[rb].size()) swap(online[ra], online[rb]);
            online[ra].insert(online[rb].begin(), online[rb].end());
            online.erase(rb);
        };

        // Build components
        for (auto& e : connections) {
            unite(e[0], e[1]);
        }

        vector<int> ans;

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);

            if (type == 1) {
                if (online[root].count(x)) {
                    ans.push_back(x);
                } else if (!online[root].empty()) {
                    ans.push_back(*online[root].begin());
                } else {
                    ans.push_back(-1);
                }
            } else { // type == 2
                online[root].erase(x);
            }
        }

        return ans;
    }
};