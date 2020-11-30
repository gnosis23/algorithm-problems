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

#define INF 1e9
#define MAXN 100

inline void dumpGraph(int graph[][MAXN], int r, int c) {
#ifdef XDebug    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
}

inline void dumpArray(ll *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
/**
 * 线段树
 * 支持区间加法，区间求和
 * 根结点从0开始，区间左闭右开从0开始。
 */
class SegmentTree {
public:
    typedef ll vtype;    
    SegmentTree(int _size) {
        size = _size;
        int n = _size * 4;
        data = std::move(vector<vtype>(n, 0));
        sum = std::move(vector<vtype>(n, 0));
    }
    inline int lc(int k) { return (k<<1)|1; }
    inline int rc(int k) { return (k<<1)+2; }
    vector<vtype> data;
    vector<vtype> sum;
    int size;    
    // usage: build(data, 0, 0, n)
    void build(vtype *d, int k, int l, int r) {
        if(r - l < 2){	//	l + 1 == r
            data[k] = d[l];
            return;
        }
        int mid = (l + r) / 2;
        build(d, lc(k), l, mid);
        build(d, rc(k), mid, r);
        data[k] = data[lc(k)] + data[rc(k)];
    }
    // usage: update(a, b, v, 0, 0, n)
    //  warn: [a,b] => [a-1, b)
    void update(int a, int b, vtype v, int k, int l, int r) {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            data[k] += v * (r - l);
            sum[k] += v;
            return;
        }
        pushDown(k, l, r);
        int mid = (l + r) / 2;
        if (a<=mid) update(a, b, v, lc(k), l, mid);
        if (b>=mid) update(a, b, v, rc(k), mid, r);
        pushUp(k);
    }
    inline void foo(int k, int c, int l, int r) {
        sum[c] += sum[k];
        data[c] += sum[k] * (r - l);
    }
    inline void pushDown(int k, int l, int r) {
        int mid = (l + r) / 2;
        foo(k, lc(k), l, mid);
        foo(k, rc(k), mid, r);
        sum[k] = 0;
    }
    inline void pushUp(int k) {
        data[k] = data[lc(k)] + data[rc(k)];
    }
    // usage: query(a, b, 0, 0, n)
    //  warn: [a,b] => [a-1, b)
    vtype query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return data[k];
        else {
            pushDown(k, l, r);
            vtype res = 0;
            int mid = (l + r) / 2;
            if (a<=mid) res += query(a, b, lc(k), l, mid);
            if (b>=mid) res += query(a, b, rc(k), mid, r);
            return res;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<ll> nums(n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &nums[i]);
    }
    SegmentTree tree(n);
    tree.build(&nums[0], 0, 0, n);

    int type, x,y,k;
    while (m--)
    {
        scanf("%d %d %d", &type, &x, &y);
        if (type == 1) {
            scanf("%d", &k);
            tree.update(x-1, y, k, 0, 0, n);
        } else {
            printf("%lld\n", tree.query(x-1, y, 0, 0, n));
        }
    }
    
    return 0;
}