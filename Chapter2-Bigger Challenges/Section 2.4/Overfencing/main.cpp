/*
ID: forusac5
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXW = 80;
const int MAXH = 250;
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};
int W, H, edgeW, edgeH;
char maze[MAXH][MAXW];
int dist[MAXH][MAXW];
bool in[MAXH][MAXW];
deque<pair<int, int> >Q;

int main()
{
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    scanf("%d %d", &W, &H);
    MMset(dist, -1);
    for (int i = 0; i < 2 * H + 1; i++) {
        getchar();
        for (int j = 0; j < 2 * W + 1; j++) {
            scanf("%c", &maze[i][j]);
        }
    }
    for (int i = 0; i < 2 * W + 1; i++) {
        if (maze[0][i] == ' ') {
            Q.push_back(make_pair(1, i));
            dist[1][i] = 1;
            in[1][i] = 1;
        }
        if (maze[2 * H][i] == ' ') {
            Q.push_back(make_pair(2 * H - 1, i));
            dist[2 * H - 1][i] = 1;
            in[2 * H - 1][i] = 1;
        }
    }
    for (int i = 0; i < 2 * H + 1; i++) {
        if (maze[i][0] == ' ') {
            Q.push_back(make_pair(i, 1));
            dist[i][1] = 1;
            in[i][1] = 1;
        }
        if (maze[i][2 * W] == ' ') {
            Q.push_back(make_pair(i, 2 * W - 1));
            dist[i][2 * W - 1] = 1;
            in[i][2 * W - 1] = 1;
        }
    }
    while (!Q.empty()) {
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop_front();
        in[tx][ty] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = tx + dirx[i] * 2;
            int ny = ty + diry[i] * 2;
            int fx = tx + dirx[i];
            int fy = ty + diry[i];
            if (nx < 0
                || nx >= 2 * H + 1
                || ny < 0
                || ny >= 2 * W + 1
                || maze[fx][fy] != ' ') {
                    continue;
            }
            if (dist[nx][ny] == -1 || dist[nx][ny] > dist[tx][ty] + 1) {
                dist[nx][ny] = dist[tx][ty] + 1;
                if (!in[nx][ny]) {
                    in[nx][ny] = 1;
                    Q.push_back(make_pair(nx, ny));
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret = max(ret, dist[2 * i + 1][2 * j + 1]);
        }
    }
    printf("%d\n", ret);
    return 0;
}
