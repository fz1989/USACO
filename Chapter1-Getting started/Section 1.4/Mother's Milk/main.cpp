/*
ID: forusac5
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
struct Node {
    int amount[3];
    Node(int a = 0, int b = 0, int c = 0) {
        amount[0] = a, amount[1] = b, amount[2] = c;
    }
};
int cap[3];
bool vis[21][21][21];

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    for (int i = 0; i < 3; i++) {
        scanf("%d", cap + i);
    }
    queue <Node> Q;
    Q.push(Node(0, 0, cap[2]));
    vis[0][0][cap[2]] = 1;
    while (!Q.empty()) {
        int now[3], next[3];
        for (int i = 0; i < 3; i++) {
            now[i] = Q.front().amount[i];
        }
        Q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                for (int k = 0; k < 3; k++) next[k] = now[k];
                next[i] = max(0, now[i] + now[j] - cap[j]);
                next[j] = min(now[i] + now[j], cap[j]);
                if (!vis[next[0]][next[1]][next[2]]) {
                    vis[next[0]][next[1]][next[2]] = 1;
                    Q.push(Node(next[0], next[1], next[2]));
                }
            }
        }
    }
    vector <int> ret;
    for (int i = 0; i <= cap[2]; i++) {
        for (int j = 0; j <= cap[1]; j++) {
            if (vis[0][j][i]) {
                ret.push_back(i);
            }
        }
    }
    int len = ret.size();
    for (int i = 0; i < len; i++) {
        printf("%d%c", ret[i], (i + 1 == len) ? '\n' : ' ');
    }
    return 0;
}
