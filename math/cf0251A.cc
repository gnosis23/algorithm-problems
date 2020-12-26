/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/251/A
 * tag:
 */
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
#include <cassert>
#ifdef XDebug
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100
#define all(A) A.begin(), A.end()

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
ll nCk(int n, int k) {
    ll s = 1;
    k = min(k, n-k);
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(all(A));
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int next = upper_bound(all(A), A[i] + d) - A.begin();
        if (next == A.size() || (A[next] - A[i] > d)) next--;
        if (next - i >= 2) {
            ans += nCk(next - i, 2);
        }
    }
    cout << ans << endl;
    return 0;
}
