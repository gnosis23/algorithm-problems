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
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

typedef long long ll;

// CODE HERE
#define MAXN 1001
int sp[MAXN][MAXN];

// LinkedList
typedef struct _Node {
    _Node(int s0,int e0,int w0):s(s0),e(e0),w(w0) {}
    int s,e,w;
} LNode;
typedef vector<list<LNode>> Edges;

void dijk(int n, int start, const Edges& edges, int *d) {
    set<pair<int,int>> st;
    for (int i = 0; i < n; ++i) d[i] = INT_MAX;
    st.insert({0, start});
    d[start] = 0;
    while (!st.empty()) {
        int s = st.begin()->second;
        st.erase(st.begin());
        for (const auto& edge : edges[s]) {
            if (d[s] + edge.w < d[edge.e]) {
                st.erase({d[edge.e], edge.e});
                d[edge.e] = d[s] + edge.w;
                st.insert({d[edge.e], edge.e});
            }
        }
    }
}

void ndijk(int n, const Edges& edges) {
    for (int i = 0; i < n; ++i) {
        dijk(n, i, edges, sp[i]);
    }
}

void findMin(const Edges& edges, const vector<pair<int, int>>& paths) {
    ll result = INT_MAX;
    int n = edges.size();
    for (int i = 0; i < n; ++i) {
        for (const auto &edge : edges[i]) {
            ll sum = 0;
            for (const auto &path : paths) {
                int start = path.first;
                int end = path.second;
                int value = sp[start][end];

                int x = i;
                int y = edge.e;
                value = min(value, sp[start][x] + sp[y][end]);
                value = min(value, sp[start][y] + sp[x][end]);
                sum += value;
            }
            result = min(result, sum);
        }
    }
    printf("%lld\n", result);
}

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    Edges edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[a-1].push_back(LNode(0, b-1, w));
        edges[b-1].push_back(LNode(0, a-1, w));
    }
    ndijk(n, edges);

    vector<pair<int, int>> paths;
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        paths.push_back({a-1, b-1});
    }
    findMin(edges, paths);

    return 0;
}
