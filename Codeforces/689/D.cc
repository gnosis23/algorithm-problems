/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1461/problem/D
 * tag: 分治 set
 **/
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
#ifdef XDebug
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100010

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
ll sum[MAXN];
vector<ll> num(MAXN);
vector<ll> code(MAXN<<2);
int bd = 0;

inline void loop(int l, int r) {
    if ((r - l < 0)) return;
    ll s = sum[r] - sum[l];
    code[bd++] = s;
    if(num[l] == num[r-1]) return;
    ll mid = num[l] + (num[r-1] - num[l]) / 2;
    int pos = upper_bound(num.begin() + l, num.begin() + r, mid) - num.begin();
    if (pos == r || pos == l) return;
    loop(l, pos);
    loop(pos, r);
}

int main(int argc, char const *argv[])
{
    int ncases;
    scanf("%d", &ncases);
    while (ncases--)
    {
        int n, q;
        memset(sum, 0, sizeof(sum));
        bd = 0;

        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &num[i]);
        }
        sort(num.begin(), num.begin() + n);

        for(int i = 0; i < n; ++i) {
            sum[i+1] = sum[i] + num[i];
        }
        
        loop(0, n);
        sort(code.begin(), code.begin() + bd);
        // dumpArray(&code[0], bd);

        ll s;
        for(int i = 0; i < q; ++i) {
            scanf("%lld", &s);
            int off = lower_bound(code.begin(), code.begin() + bd, s) - code.begin();
            if (off < bd && code[off] == s) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    
    return 0;
}
