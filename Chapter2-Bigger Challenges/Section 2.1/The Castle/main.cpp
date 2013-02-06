/*
ID:forusac5
LANG:C++
TASK:castle
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <string>
#define MMset(a,b) memset(a, b, sizeof(a))
const int MAXN = 60;
using namespace std;
bool maze[MAXN][MAXN][4];
int diri[] = {0, -1, 0, 1};
int dirj[] = {-1, 0, 1, 0};
char str[] = {'W','N','E','S'};
bool vis[MAXN][MAXN];
int N, M;
queue <pair<int, int> >Q;

int BFS(int si , int sj) {
    int ret = 0;
    vis[si][sj] = 1;
    Q.push(make_pair(si, sj));
    while (!Q.empty()) {
        int nowi = Q.front().first;
        int nowj = Q.front().second;
        Q.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            if (maze[nowi][nowj][i] == false) {
                int nexti = nowi + diri[i];
                int nextj = nowj + dirj[i];
                if (nexti >= N || nexti < 0 || nextj >= M || nextj < 0) continue;
                if (!vis[nexti][nextj]) {
                    vis[nexti][nextj] = 1;
                    Q.push(make_pair(nexti, nextj));
                }
            }
        }
    }
    return ret;
}

int floodFillAll(int &tot) {
    int ret = 0;
    MMset(vis, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                tot++;
                ret = max(ret, BFS(i, j));
            }
        }
    }
    return ret;
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int n;
            scanf("%d", &n);
            for (int k = 0; k < 4; k++) {
                if ((n & (1 << k))) maze[i][j][k] = true;
            }
        }
    }
    int cnt = 0;
    int maxArea = floodFillAll(cnt);

    printf("%d\n%d\n", cnt, maxArea);

    maxArea = -1;
    int ansi, ansj, ansk;
    for (int j = 1; j <= M; j++) {
        for (int i = N; i >= 1; i--) {
            //printf("%d %d\n",i,j);
            for (int k = 1; k < 3; k++) {
                if (maze[i- 1][j - 1][k]) {
                    maze[i - 1][j - 1][k] = 0;
                    if (k == 1 && i >= 2) maze[i - 2][j - 1][3] = 0;
                    if (k == 2 && j < M) maze[i - 1][j][0] = 0;
                    int tmp = floodFillAll(cnt);
                    if (maxArea < tmp) {
                        maxArea = tmp;
                        ansi = i, ansj = j, ansk = k;
                    }
                    if (k == 1 && i >= 2) maze[i - 2][j - 1][3] = 1;
                    if (k == 2 && j < M) maze[i - 1][j][0] = 1;
                    maze[i - 1][j - 1][k] = 1;
                }
            }
        }
    }
    printf("%d\n%d %d %c\n", maxArea, ansi, ansj, str[ansk]);
    return 0;
}
