/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: UVa1625 - Color Length
 * tag: DP
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
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 5001

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

// CODE HERE
char text[2][MAXN];
int dp[MAXN][MAXN];
int openCnt[MAXN][MAXN];

void solve() {
    cin >> text[0];
    cin >> text[1];
    int len[2];
    len[0] = strlen(text[0]);
    len[1] = strlen(text[1]);

    // word [start, end]
    vector<PII> posInfo[2];
    posInfo[0].resize(26);
    posInfo[1].resize(26);
    
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < len[i]; ++j) {
            int index = text[i][j] - 'A';
            if (posInfo[i][index].first == 0) {
                posInfo[i][index].first = j+1;
                posInfo[i][index].second = j+1;
            } else {
                posInfo[i][index].second = j+1;
            }        
        }
    }

    for(int i = 0; i <= len[0]; ++i) {
        for (int j = 0; j <= len[1]; ++j) {
            dp[i][j] = (i==0 && j==0) ? 0 : INF;
            // dp[i][j]: take i colors from text[0], take j colors from text[1]
            // openCnt: 颜色和它们的顺序其实不重要，因为每次加入只考虑已经开始但是没有结束的颜色个数就行了。
            if (i-1>=0) dp[i][j] = min(dp[i][j], dp[i-1][j] + openCnt[i-1][j]);
            if (j-1>=0) dp[i][j] = min(dp[i][j], dp[i][j-1] + openCnt[i][j-1]);
            // update cnt
            if (i-1 >= 0) {
                openCnt[i][j] = openCnt[i-1][j];
                // add text[0][i-1]
                // cnt+1 if first color
                // cnt-1 if last color
                int chIndex = text[0][i-1] - 'A';
                if (
                    (posInfo[0][chIndex].first == i) && 
                    ((posInfo[1][chIndex].first == 0) || (posInfo[1][chIndex].first  > j))
                ) {
                    openCnt[i][j]++;
                }
                if (
                    (posInfo[0][chIndex].second == i) && 
                    ((posInfo[1][chIndex].second == 0) || (posInfo[1][chIndex].second <= j))
                ) {
                    openCnt[i][j]--;
                }
            } 
            else if (j-1 >= 0) {
                openCnt[i][j] = openCnt[i][j-1];
                // add text[1][j-1]
                int chIndex = text[1][j-1] - 'A';
                if (
                    ((posInfo[0][chIndex].first == 0) || (posInfo[0][chIndex].first  > i)) &&
                    (posInfo[1][chIndex].first == j)
                ) {
                    openCnt[i][j]++;
                }
                if (
                    ((posInfo[0][chIndex].second == 0) || (posInfo[0][chIndex].second <= i)) && 
                    (posInfo[1][chIndex].second == j)
                ) {
                    openCnt[i][j]--;
                }
            } 
            else {
                openCnt[i][j] = 0;
            }
        }
    }
    // dumpGraph(openCnt, len[0]+1, len[1]+1);
    cout << dp[len[0]][len[1]] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncase;
    cin >> ncase;
    while (ncase--) {
        solve();
    }
    return 0;
}
