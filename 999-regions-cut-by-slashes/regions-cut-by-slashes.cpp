#include <vector>
#include <string>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(4 * n * n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (i * n + j);
                
                // Connect internal parts of the square
                if (grid[i][j] == '/') {
                    uf.unite(base, base + 3);  // top-left to bottom-right
                    uf.unite(base + 1, base + 2);  // top-right to bottom-left
                } else if (grid[i][j] == '\\') {
                    uf.unite(base, base + 1);  // top-left to top-right
                    uf.unite(base + 2, base + 3);  // bottom-left to bottom-right
                } else {
                    uf.unite(base, base + 1);
                    uf.unite(base + 1, base + 2);
                    uf.unite(base + 2, base + 3);
                }
                
                // Connect squares horizontally
                if (j + 1 < n) {
                    uf.unite(base + 1, 4 * (i * n + j + 1) + 3);  // Right square
                }
                
                // Connect squares vertically
                if (i + 1 < n) {
                    uf.unite(base + 2, 4 * ((i + 1) * n + j));  // Bottom square
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (uf.find(i) == i) {
                regions++;
            }
        }
        
        return regions;
    }
};
