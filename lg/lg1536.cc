#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long ll;

class DisjointSet {
public:
    DisjointSet(int n){
        p = vector<int>(n + 1);
        rank = vector<int>(n + 1);
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
            rank[i] = 0;
        }
    }
    bool inSame(int u, int v) {
        return findSet(u) == findSet(v);
    }
    void join(int u, int v) {
        if (findSet(u) != findSet(v)) {
            link(findSet(u), findSet(v));
        }
    }
    int findSet(int u) {
        if (u != p[u]) {
            p[u] = findSet(p[u]);
        }
        return p[u];
    }
    int count() {
        int size = p.size();
        set<int> st;
        for (int i = 1; i != size; ++i) {
            st.insert(findSet(i));
        }
        return st.size() - 1;
    }
private:
    vector<int> p;
    vector<int> rank;
    void link(int u, int v) {
        if (rank[u] > rank[v]) {
            p[v] = u;
        } else {
            p[u] = v;
            if (rank[u] == rank[v]) {
                rank[u] = rank[v] + 1;
            }
        }
    }
};

// CODE HERE

int main(int argc, char const *argv[])
{
    int n, m;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        DisjointSet d(n);
        scanf("%d", &m);
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            d.join(a, b);
        }
        printf("%d\n", d.count());
    }
    return 0;
}
