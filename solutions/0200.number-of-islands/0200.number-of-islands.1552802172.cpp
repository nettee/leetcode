class UnionFind {
public:
    UnionFind(int M, int N) {
        this->M = M;
        this->N = N;
        for (int k = 0; k < M * N; k++) {
            parent.push_back(k);
        }
    }
    
    void union_(int i1, int j1, int i2, int j2) {
        int r1 = get_root(i1, j1);
        int r2 = get_root(i2, j2);
        parent[r1] = r2;
    }
    
    int get_root(int i, int j) {
        int k = get_index(i, j);
        int p = k;
        while (parent[p] != p) {
            p = parent[p];
        }
        return p;
    }
private:
    vector<int> parent;
    int M;
    int N;
    
    int get_index(int i, int j) {
        return i * N + j;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size();
        int N = grid[0].size();
        UnionFind uf(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1') {
                    if (i > 0 && grid[i-1][j] == '1') {
                        uf.union_(i, j, i-1, j);
                    }
                    if (j > 0 && grid[i][j-1] == '1') {
                        uf.union_(i, j, i, j-1);
                    }
                }
            }
        }
        unordered_set<int> islands;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1') {
                    islands.insert(uf.get_root(i, j));
                }
            }
        }
        return islands.size();
    }
};
