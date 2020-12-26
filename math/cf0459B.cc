/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/459/B
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

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int diff = A[n-1] - A[0];
    ll ans = 0;
    if (diff == 0) {
        ans = (ll)n * (n - 1) / 2;
    }
    else {
        int n1 = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == A[0]) n1++;
            else break;
        }
        for (int i = n-1; i >= 0; --i) {
            if (A[i] == A[n-1]) ans += n1;
            else break;
        }
    }
    
    cout << diff << " " << ans << endl;
    return 0;
}
