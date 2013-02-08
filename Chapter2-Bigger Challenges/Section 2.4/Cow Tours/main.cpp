/*
ID: forusac5
PROG: cowtour
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
const int MAXN = 160;
struct Point {
    long long x, y;
    void input() {
        int _x, _y;
        scanf("%d %d\n",&_x, &_y);
        x = _x;
        y = _y;
    }
    double calcDist(Point p) {
        return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }
}point[MAXN];
int N;
double dist[MAXN][MAXN];
double rad[MAXN], far[MAXN];
int par[MAXN], rank[MAXN];
char incon[MAXN][MAXN];

int findset(int u) {
    if (u!= par[u]) {
        par[u] = findset(par[u]);
    }
    return par[u];
}

void unionset(int u, int v) {
    int ru = findset(u), rv = findset(v);
    if (ru == rv) return;
    if (rank[ru] < rank[rv]) {
        par[ru] = rv;
        rank[rv] += rank[ru];
    } else {
        par[rv] = par[ru];
        rank[ru] += rank[rv];
    }
}

int main()
{
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rank[i] = 1;
        point[i].input();
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", incon[i]);
        for (int j = 0; j < N; j++) {
            dist[i][j] = 1e20;
            if (incon[i][j] == '1') {
                unionset(i, j);
                dist[i][j] = point[i].calcDist(point[j]);
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        findset(i);
        dist[i][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (par[i] == par[j]) {
                rad[par[i]] = max(rad[par[i]], dist[i][j]);
                rad[par[j]] = max(rad[par[j]], dist[i][j]);
                far[i] = max(far[i], dist[i][j]);
                far[j] = max(far[j], dist[i][j]);
            }
        }
    }
    double ret = 1e20;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (par[i] != par[j]) {
                double ans = max(max(rad[par[i]], rad[par[j]]), point[j].calcDist(point[i]) + far[i] + far[j]);
                ret = min(ans, ret);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (rank[par[i]] != 1) {
            ret = max(ret, rad[par[i]]);
        }
    }
    printf("%.6f\n", ret);
    return 0;
}
