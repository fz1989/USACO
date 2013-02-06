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
using namespace std;
const int MAXN = 101;
int N, C, num;
char out[MAXN];
int dist[256], goalon = 0, goaloff = 0;
int op[4] = {63, 42, 21, 36};
bool inq[256];

void print(int num) {
    int digs[10];
    for (int i = 0; i < 6; i++) {
        digs[i] = num % 2;
        num /= 2;
    }
    reverse(digs, digs + 6);
    for (int i = 0; i < N; i++) {
        printf("%d", digs[i % 6]);
    }
    printf("\n");
}

int main()
{
    scanf("%d%d",&N, &C);
    while (scanf("%d", &num) && num != -1) {
        num--;
        num = num % 6;
        goalon = goalon | (1 << (5 - num));
    }
    while (scanf("%d", &num) && num != -1) {
        num--;
        num = num % 6;
        goaloff = goaloff | (1 <<(5 - num));
    }
    MMset(dist, -1);
    dist[63] = 0;
    inq[63] = 1;
    queue <int> Q;
    Q.push(63);
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        inq[now] = 0;
        for (int i = 0; i < 4; i++) {
            int next = now ^ op[i];
            if (dist[next] == -1 || dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                if (!inq[next]) {
                    inq[next] = 1;
                    Q.push(next);
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 64; i++) {
        if ( (i & goalon) == goalon && dist[i] != -1 && (i & goaloff) == 0) {
            if (dist[i] > C) continue;
            if (dist[i] == C - 1
                && dist[i] != dist[i^op[1]] + 1
                && dist[i] != dist[i^op[2]] + 1
				&& dist[i] != dist[i^op[0]] + 1) continue;
            print(i);
            cnt++;
        }
    }
    if (cnt == 0) puts("IMPOSSIBLE");
    return 0;
}
