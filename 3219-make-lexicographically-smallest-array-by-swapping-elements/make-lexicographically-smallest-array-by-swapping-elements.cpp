class DisjointSet {
    vector<int> parent, size;
  public:
    DisjointSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void dsu(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);

        if(par_u == par_v) return ;

        if(size[par_u] > size[par_v]) {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        } else {
            parent[par_u] = parent[par_v];
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DisjointSet ds(n);

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        for(int i = 1; i < n; i++) {
            if(nums[indices[i]] - nums[indices[i-1]] <= limit) {
                ds.dsu(indices[i], indices[i-1]);
            }
        }

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[ds.find(i)].push_back(i);
        }
        
        for(auto& i : mp) {
            vector<int> indices = i.second;
            vector<int> val;
            for(int& j : indices) {
                val.push_back(nums[j]);
            }

            sort(indices.begin(), indices.end());
            sort(val.begin(), val.end());

            for(int j = 0; j < indices.size(); j++) {
                nums[indices[j]] = val[j];
            }
        }

        return nums;
    }
};