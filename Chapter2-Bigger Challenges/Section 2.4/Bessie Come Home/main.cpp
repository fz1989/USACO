/*
ID: forusac5
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#define MMset(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x) * (x))
using namespace std;
const int MAXN = 256;
int dist[MAXN], cost[MAXN][MAXN];
bool vis[MAXN];
int N;
int main()
{
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    scanf("%d\n", &N);
    MMset(cost, 0x3f);
    MMset(dist, 0x3f);
    for (int i = 0; i < N; i++) {
        char s, t;
        int val;
        scanf("%c %c %d\n", &s, &t, &val);
        val = min(val, cost[(int)s][(int)t]);
        cost[(int)s][(int)t] = cost[(int)t][(int)s] = val;
    }
    dist[(int)'Z'] = 0;
    for (int i = 0; i < MAXN; i++) {
        int loc = -1;
        for (int j = 0; j < MAXN; j++) {
            if (!vis[j]) {
                if (loc == -1 || dist[loc] > dist[j]) {
                    loc = j;
                }
            }
        }
        vis[loc] = 1;
        for (int j = 0; j < MAXN; j++) {
            if (!vis[j] && dist[j] > dist[loc] + cost[loc][j]) {
                dist[j] = dist[loc] + cost[loc][j];
            }
        }
    }
    int loc = -1;
    for (int i = 'A'; i < 'Z'; i++) {
        if (loc == -1 || dist[loc] > dist[i]) {
            loc = i;
        }
    }
    printf("%c %d\n", (char)loc, dist[loc]);
    return 0;
}
