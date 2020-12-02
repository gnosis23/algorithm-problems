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
#define MAXN 30

// CODE HERE
// 巴比伦塔
int dp[MAXN][3];
struct Pt {
    Pt(int a, int b, int c):x(a),y(b),z(c) {}
    int x,y,z;
};

inline int getHeight(Pt &block, int type) {
    int ans;
    if (type == 0) {
        ans = block.x;
    } else if (type == 1) {
        ans = block.y;
    } else {
        ans = block.z;
    }
    return ans;
}

pair<int,int> getWH(Pt &block, int type) {
    if (type == 0) {
        return {block.y, block.z};
    } else if (type == 1) {
        return {block.x, block.z};
    } else {
        return {block.x, block.y};
    }
}

bool cmp(Pt &a, int type1, Pt &b, int type2) {
    int a1,b1,a2,b2;
    auto p1 = getWH(a, type1);
    auto p2 = getWH(b, type2);
    a1 = p1.first;
    b1 = p1.second;
    a2 = p2.first;
    b2 = p2.second;
    if ((a1 > a2) && (b1 > b2)) return true;
    if ((a1 > b2) && (b1 > a2)) return true;
    return false;
}

int solve(int id, int type, int n, vector<Pt> &blocks) {
    if (dp[id][type] > 0) return dp[id][type];
    int &ans = dp[id][type];
    Pt &target = blocks[id];
    int height = getHeight(blocks[id], type);
    ans = height;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (cmp(target, type, blocks[i], j)) {
                ans = max(ans, solve(i, j, n, blocks) + height);
            }
        }
    }
    // cout << "dp[" << id << "][" << type << "] = " << ans << endl; 
    return ans;
}

int main(int argc, char const *argv[])
{
    int ncase = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<Pt> blocks;
        int a, b, c;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            blocks.push_back(Pt(a, b, c));
        }
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 3; ++j) {
                solve(i, j, n, blocks);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 3; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }

        cout << "Case " << ncase++ << ": maximum height = " << ans << endl;
    }
    return 0;
}
