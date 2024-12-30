class DisjointSet {
    vector<int> parent, size;

 public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = find(parent[n]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        map<string, int> mp; // string: int

        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < acc[i].size(); j++) {
                if(mp.count(acc[i][j])) {
                    ds.unionBySize(i, mp[acc[i][j]]);
                } else {
                    mp[acc[i][j]] = i;
                }
            }
        }

        map<int, vector<string>> mp1; // Node(int): emails
        for(auto& i : mp) {
            string email = i.first;
            int name = ds.find(i.second);
            mp1[name].push_back(email);
        }

        vector<vector<string>> res;
        for(int i = 0; i < n; i++) {
            if(mp1[i].empty()) continue;
            vector<string>temp;
            sort(mp1[i].begin(), mp1[i].end());
            temp.push_back(acc[i][0]);
            for(string& j : mp1[i]) temp.push_back(j);
            res.push_back(temp);
        }
        return res;
    }
};