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
#include "../../debug.h" 
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
class FenWick {
public:
    FenWick(int n): a(vector<int>(n+1,0)) {}
    // from index 1...x
    int sum(int x) {
        int sum = 0;
        while (x > 0)
            sum ^= a[x], x -= lsb(x);
        return sum;
    }
    void add(int x, int k) {
        int size = a.size() - 1;
        while (x <= size) 
            a[x] ^= k, x += lsb(x);
    }
private:
    inline int lsb(int x) { return x & (-x); }
    vector<int> a;
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    FenWick bit(n);
    int a;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        bit.add(i+1, a);
    }

    int t,x,y;
    for(int i = 0; i < q; ++i) {
        cin >> t >> x >> y;
        if (t == 1) {
            bit.add(x, y);
        } else {
            if (x > 1) {
                cout << (bit.sum(y) ^ bit.sum(x-1)) << endl;
            }
            else {
                cout << bit.sum(y) << endl;
            }
        }
    }
    return 0;
}
