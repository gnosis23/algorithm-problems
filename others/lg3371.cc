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
#include <climits>
using namespace std;

typedef long long ll;

// CODE HERE
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

int main(int argc, char const *argv[])
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    vector<int> d(n);
    Edges edges(n);
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u-1].push_back(LNode(u-1, v-1, w));
    }
    dijk(n, s-1, edges, &d[0]);
    for (int i = 0; i < n; ++i) {
        printf("%d", d[i]);
        if (i != n-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
