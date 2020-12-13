/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://www.luogu.com.cn/problem/P2880
 * tag: 倍增
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
#define MAXN 50010
#define MAXN_LOG_N 16

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
int A[MAXN];
int next1[MAXN_LOG_N][MAXN];
int next2[MAXN_LOG_N][MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int x;
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1) {
            next1[0][i] = -1;
            next2[0][i] = -1;
        }
        else {
            x = i + 1;
            while (x != -1 && A[x] < A[i]) {
                x = next1[0][x];
            }
            next1[0][i] = x;
            x = i + 1;
            while (x != -1 && A[x] > A[i]) {
                x = next2[0][x];
            }
            next2[0][i] = x;
            // cout << "next2: " << i << " = " << x << endl;
        }
    }
    

    for (int k = 0; k + 1 < MAXN_LOG_N; ++k) {
        for (int i = 0; i < n; ++i) {
            if (next1[k][i] < 0) next1[k+1][i] = -1;
            else next1[k+1][i] = next1[k][next1[k][i]];
        }
    }
    for (int k = 0; k + 1 < MAXN_LOG_N; ++k) {
        for (int i = 0; i < n; ++i) {
            if (next2[k][i] < 0) next2[k+1][i] = -1;
            else next2[k+1][i] = next2[k][next2[k][i]];
        }
    }

    int a, b;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        int maxV = A[a-1];
        int minV = A[a-1];
        int j = a-1;
        for(int k = MAXN_LOG_N-1; k >= 0; --k) {
            int j2 = next1[k][j];
            if (j2 >= 0 && j2 < b) {
                maxV = max(maxV, A[j2]);
                j = j2;
            }
        }
        j = a - 1;
        for(int k = MAXN_LOG_N-1; k >= 0; --k) {
            int j2 = next2[k][j];
            if (j2 >= 0 && j2 < b) {
                minV = min(minV, A[j2]);
                j = j2;
            }
        }
        cout << maxV - minV << endl;
    }

    return 0;
}