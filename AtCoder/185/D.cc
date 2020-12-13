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
#define MAXN 200001

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
int A[MAXN];
vector<int> segment;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    if (M == 0) {
        cout << 1 << endl;
        return 0;
    }

    sort(A, A+M);

    int pre = 1;
    for(int i = 0; i < M; ++i) {
        if (i == 0) {
            if (A[i] != 1) segment.push_back(A[i] - pre);
        }
        else if ((A[i] - 1) != pre) {
            segment.push_back(A[i] - pre - 1);
        }
        pre = A[i];
    }
    if (M > 0 && A[M-1] != N) {
        segment.push_back(N - A[M-1]);
    }
    sort(segment.begin(), segment.end());
    // dumpArray(&segment[0], segment.size());
    
    if (segment.empty()) {
        cout << 0 << endl;
    } 
    else {
        int k = segment[0];
        ll ans = 0;
        int size = segment.size();
        for(int i = 0; i < size; ++i) {
            ans += (segment[i] - 1 + k) / k;
        }
        cout << ans << endl;
    }
    return 0;
}
