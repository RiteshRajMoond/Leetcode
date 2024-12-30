class DisjointSet {
    vector<int> parent, size;
    int len;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        len = n;
    }

    // find UPar
    int find(int n) {
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void unionBySize(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if(up == vp) return;

        if(size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size()) return -1;

        DisjointSet ds(n);
        for(auto& i : connections) {
            ds.unionBySize(i[0], i[1]);
        }

        int res = 0;
        for(int i = 0; i < n-1; i++) {
            if(ds.find(i) != ds.find(i+1)) {
                res++;
                ds.unionBySize(i, i+1);
            }
        }
        return res;
    }
};