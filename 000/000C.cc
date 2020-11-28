#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 200;
typedef pair<int, int> pii;
char c[N][N];
bool cnt[N][N];

struct node
{
  int x1, y1, x2, y2, x3, y3;
} p[4];
vector<node> v;

void update(int x, int y, int tp, bool is)
{
  if (is)
  {
    v.push_back({x + p[tp].x1, y + p[tp].y1, x + p[tp].x2, y + p[tp].y2, x + p[tp].x3, y + p[tp].y3});
  }
  else
  {
    cnt[x + p[tp].x1][y + p[tp].y1] ^= 1;
    cnt[x + p[tp].x2][y + p[tp].y2] ^= 1;
    cnt[x + p[tp].x3][y + p[tp].y3] ^= 1;
  }
}

void solve()
{
  int n, m, nOne = 0;
  v.clear();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", &c[i][1]);
    for (int j = 1; j <= m; j++)
    {
      if (c[i][j] == '1')
        nOne++, cnt[i][j] = true;
      else
        cnt[i][j] = false;
    }
  }
  if (nOne == 0)
  {
    printf("0\n");
    return;
  }
  if (n == 1 || m == 1)
  {
    printf("-1\n");
    return;
  }
  for (int i = 1; i <= n - 2; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (cnt[i][j])
      {
        if (j != m)
        {
          v.push_back({i, j, i + 1, j, i + 1, j + 1});
          cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j + 1] ^= 1;
        }
        else
        {
          v.push_back({i, j, i + 1, j, i + 1, j - 1});
          cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j - 1] ^= 1;
        }
      }
    }
  }
  for (int i = 1; i <= m - 2; i++)
  {
    if (cnt[n - 1][i])
    {
      v.push_back({n - 1, i, n - 1, i + 1, n, i + 1});
      cnt[n - 1][i] ^= 1, cnt[n - 1][i + 1] ^= 1, cnt[n][i + 1] ^= 1;
    }
    if (cnt[n][i])
    {
      v.push_back({n, i, n - 1, i + 1, n, i + 1});
      cnt[n][i] ^= 1, cnt[n - 1][i + 1] ^= 1, cnt[n][i + 1] ^= 1;
    }
  }
  for (int msk = 0; msk < (1 << 4); msk++)
  {
    for (int j = 0; j < 4; j++)
      if (msk & (1 << j))
        update(n - 1, m - 1, j, 0);
    if (!cnt[n - 1][m - 1] && !cnt[n - 1][m] && !cnt[n][m - 1] && !cnt[n][m])
    {
      for (int j = 0; j < 4; j++)
        if (msk & (1 << j))
          update(n - 1, m - 1, j, 1);
      break;
    }
    for (int j = 0; j < 4; j++)
      if (msk & (1 << j))
        update(n - 1, m - 1, j, 0);
  }
  
  printf("%d\n", (int)v.size());
  for (auto u : v)
    printf("%d %d %d %d %d %d\n", u.x1, u.y1, u.x2, u.y2, u.x3, u.y3);
}

int main()
{
  p[0] = {0, 0, 0, 1, 1, 0};
  p[1] = {0, 1, 0, 0, 1, 1};
  p[2] = {1, 0, 1, 1, 0, 0};
  p[3] = {1, 1, 0, 1, 1, 0};
  int nCase = 0;
  scanf("%d", &nCase);
  while (nCase--)
  {
    solve();
  }
  return 0;
}
