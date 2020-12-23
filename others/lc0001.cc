/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
 **/
#include <iostream>
#include <iomanip>
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
#ifdef XDebug
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
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

struct Point {
    Point(int _t, int _u, int _v, int _r, int _no): type(_t), u(_u), v(_v), r(_r), no(_no) {}
    int type;
    int u,v,r;
    int no;
    friend bool operator<(struct Point &a, struct Point &b) {
        if (a.r != b.r) return a.r < b.r;
        else return a.type > b.type;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<Point> pts;
        DisjointSet ds(n);
        int m = edgeList.size();
        for (int i = 0; i < m; ++i) {
            pts.push_back(Point(1, edgeList[i][0], edgeList[i][1], edgeList[i][2], 0));
        }
        m = queries.size();
        for(int i = 0; i < m; ++i) {
            pts.push_back(Point(2, queries[i][0], queries[i][1], queries[i][2], i));
        }

        vector<bool> ans(m);
        sort(pts.begin(), pts.end());
        m = pts.size();
        for(int i = 0; i < m; ++i) {
            if (pts[i].type == 1) {
                ds.join(pts[i].u, pts[i].v);
            }
            else {
                ans[pts[i].no] = ds.inSame(pts[i].u, pts[i].v);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    return 0;
}
