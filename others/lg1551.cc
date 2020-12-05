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
    vector<int> p;
    vector<int> rank;
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
private:
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
    int findSet(int u) {
        if (u != p[u]) {
            p[u] = findSet(p[u]);
        }
        return p[u];
    }
};

// CODE HERE

int main(int argc, char const *argv[])
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    DisjointSet d(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        d.join(u, v);
    }
    for (int i = 0; i < p; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (d.inSame(u, v)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
