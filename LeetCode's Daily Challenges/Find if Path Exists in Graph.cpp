class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& E, int start, int end) {
        UnionFind uf(n);
        for (auto &e : E) {
            uf.connect(e[0], e[1]);
        }
        return uf.connected(start, end);
    }
};
