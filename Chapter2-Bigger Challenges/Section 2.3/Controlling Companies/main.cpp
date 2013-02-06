/*
ID: forusac5
PROG: concom
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
using namespace std;
const int MAXN = 101;
bool con[MAXN][MAXN];
int val[MAXN][MAXN];
int N;

void findNewRule(int A, int B) {
    if (con[A][B]) return;

    con[A][B] = true;

    for (int i = 1; i < MAXN; i++) {
        val[A][i] += val[B][i];
    }
    for (int i = 1; i < MAXN; i++) {
        if (con[i][A]) {
            findNewRule(i, B);
        }
    }
    for (int i = 1; i < MAXN; i++) {
        if (val[A][i] > 50) {
            findNewRule(A, i);
        }
    }
}

void addRule(int A, int B, int C) {

    for (int i = 1; i < MAXN; i++) {
        if (con[i][A]) {
            val[i][B] += C;
        }
    }
    for (int i = 1; i < MAXN; i++) {
        if (val[i][B] > 50) {
            findNewRule(i, B);
        }
    }
}

int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < MAXN; i++) con[i][i] = 1;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addRule(a, b, c);
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            if (i != j && con[i][j]) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
