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

    void ubs(int u, int v) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int r_max = 0, c_max = 0;
        for (auto& i : stones) {
            r_max = max(r_max, i[0]);
            c_max = max(c_max, i[1]);
        }

        DisjointSet ds(r_max + c_max + 2);
        for (auto& i : stones) {
            int r = i[0];
            int c = i[1] + r_max + 1;

            ds.ubs(r, c);
        }

        set<int> st; // for unique parents
        for (auto& i : stones) {
            int r = i[0];
            int c = i[1] + r_max + 1;

            st.insert(ds.find(r));
            st.insert(ds.find(c));
        }

        return n - st.size();
    }
};