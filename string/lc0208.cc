/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: LEETCODE 208
 * tag: trie
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
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
/**
 * Trie
 * 注意太大要放在全局
 * maxnode参考：最大长度 2^(L)-1
 * 
 */
template <size_t maxnode = 100, size_t sigma_size = 26>
class Trie {
public:
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    Trie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
    inline int idx(char c) { return c - 'a'; }
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int find(char *s) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                return -1;
            }
            u = ch[u][c];
        }
        return val[u];
    }
};

Trie<1000, 26> trie;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    trie.insert("apple", 1);
    cout << trie.find("apple") << endl;
    return 0;
}
