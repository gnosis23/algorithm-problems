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

int prime; 
// CODE HERE
class SegmentTree {
public:
    typedef ll vtype;    
    SegmentTree(int _size) {
        size = _size;
        int n = _size * 4;
        data = std::move(vector<vtype>(n, 0));
        sum = std::move(vector<vtype>(n, 0));
        scale = std::move(vector<vtype>(n, 1));
    }
    inline int lc(int k) { return (k<<1)|1; }
    inline int rc(int k) { return (k<<1)+2; }
    int size;
    vector<vtype> data;
    // lazy data
    vector<vtype> sum;
    vector<vtype> scale;
    // usage: build(data, 0, 0, n)
    void build(vtype *d, int k, int l, int r) {
        if(r - l < 2){	//	l + 1 == r
            data[k] = d[l];
            return;
        }
        int mid = (l + r) / 2;
        build(d, lc(k), l, mid);
        build(d, rc(k), mid, r);
        pushUp(k);
    }
    // usage: update(a, b, v, 0, 0, n)
    //  warn: [a,b] => [a-1, b)
    void update(int a, int b, int type, vtype v, int k, int l, int r) {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            if (type == 1) { // multiply
                scale[k] = (scale[k] * v) % prime;
                sum[k] = (sum[k] * v) % prime;
                data[k] = (data[k] * v) % prime;
            } else {
                sum[k] = (sum[k] + v) % prime;
                data[k] = (data[k] + v * (r - l)) % prime;
            }
            return;
        }
        pushDown(k, l, r);
        int mid = (l + r) / 2;
        if (a<=mid) update(a, b, type, v, lc(k), l, mid);
        if (b>=mid) update(a, b, type, v, rc(k), mid, r);
        pushUp(k);
    }
    inline void foo(int k, int c, int l, int r) {
        scale[c] = (scale[c] * scale[k]) % prime;
        sum[c]  = (sum[c] * scale[k] + sum[k]) % prime;
        data[c] = (data[c] * scale[k] + sum[k] * (r - l)) % prime;
    }
    inline void pushDown(int k, int l, int r) {
        int mid = (l + r) / 2;
        foo(k, lc(k), l, mid);
        foo(k, rc(k), mid, r);
        // clear lazy
        sum[k] = 0;
        scale[k] = 1;
    }
    inline void pushUp(int k) {
        data[k] = data[lc(k)] + data[rc(k)];
    }
    // usage: query(a, b, 0, 0, n)
    //  warn: [a,b] => [a-1, b)
    vtype query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return (data[k]) % prime;
        else {
            pushDown(k, l, r);
            vtype res = 0;
            int mid = (l + r) / 2;
            if (a<=mid) res += query(a, b, lc(k), l, mid);
            if (b>=mid) res += query(a, b, rc(k), mid, r);
            return res % prime;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d %d", &n, &m, &prime);
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
            tree.update(x-1, y, type, k, 0, 0, n);
        }
        else if (type == 2) {
            scanf("%d", &k);
            tree.update(x-1, y, type, k, 0, 0, n);
        } 
        else {
            printf("%lld\n", tree.query(x-1, y, 0, 0, n));
        }
    }
    
    return 0;
}