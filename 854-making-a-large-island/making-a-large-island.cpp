class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int findUltParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUltParent(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return false;

        int rank_ulp_u = rank[ulp_u];
        int rank_ulp_v = rank[ulp_v];

        if (rank_ulp_u > rank_ulp_v) {
            parent[ulp_v] = ulp_u;
        } else if (rank_ulp_v > rank_ulp_u) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        return true;
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return false;
        int size_ulp_u = size[ulp_u];
        int size_ulp_v = size[ulp_v];
        if (size_ulp_u < size_ulp_v) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size_ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size_ulp_v;
        }
        return true;
    }
};

class Solution {
public:
    int itoN(int i, int j, int n) { return i * n + j; }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // vector<int> areas(n * n + 1, 0);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j]) {
        //             int u = itoN(i, j, n);
        //             areas[u] = 1;
        //         }
        //     }
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int u = itoN(i, j, n);
                    for (int del = 0; del < 4; del++) {
                        int ni = i + dr[del];
                        int nj = j + dc[del];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj]) {
                            int v = itoN(ni, nj, n);
                            ds.unionBySize(u, v);
                        }
                    }
                }
            }
        }
        int ans = ds.size[ds.findUltParent(0)];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int res = 0;
                unordered_set<int> checked;
                if (!grid[i][j]) {
                    for (int del = 0; del < 4; del++) {
                        int ni = i + dr[del];
                        int nj = j + dc[del];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj]) {
                            int u = itoN(ni, nj, n);
                            int pu = ds.findUltParent(u);
                            int pus = ds.size[pu];
                            if (checked.find(pu) == checked.end()) {
                                res += pus;
                                checked.insert(pu);
                            }
                        }
                    }
                }
                ans = max(ans, res + 1);
            }
        }
        // for (int i = 0; i <= n * n; i++) {
        //     if (areas[i]) {
        //         cout << i << " " << areas[i] << ", ";
        //     }
        // }
        return ans;
    }
};