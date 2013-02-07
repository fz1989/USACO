/*
ID: forusac5
PROG: ttwo
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
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXN = 10;
const int MAXS = 400;
char farm[MAXN][MAXN];
bool vis[MAXS][MAXS];
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
struct State {
    int x, y, dir, state;

    void set(int _x, int _y, int _dir) {
        x = _x;
        y = _y;
        dir = _dir;
        state = dir * 100 + x * 10 + y;
    }

    void getNext() {
        int nx = x + dirx[dir];
        int ny = y + diry[dir];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || farm[nx][ny] == '*') {
            set(x, y, (dir + 1) % 4);
        } else {
            set(nx, ny, dir);
        }
    }

    bool equals(State b) {
        return (x == b.x) && (y == b.y);
    }
} Cow, John;

int main()
{
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    for (int i = 0; i < 10; i++) {
        scanf("%s", farm[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (farm[i][j] == 'F') {
                John.set(i, j, 0);
            }
            if (farm[i][j] == 'C') {
                Cow.set(i, j, 0);
            }
        }
    }
    int ans = 0, step = 0;
    vis[John.state][Cow.state] = true;
    while (true) {
        step++;
        John.getNext();
        Cow.getNext();
        if (John.equals(Cow)) {
            ans = step;
            break;
        }
        if (vis[John.state][Cow.state]) {
            break;
        } else {
            vis[John.state][Cow.state] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
