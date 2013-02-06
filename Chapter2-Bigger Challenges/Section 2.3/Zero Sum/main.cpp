/*
ID: forusac5
PROG: zerosum
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
#define empty 0
#define add 1
#define minus 2
using namespace std;
const int MAXN = 30;
int N;
int array[MAXN];
bool calc(int len) {
    int sum = 0, tmp = 0, op = 1;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i & 1) {
            if (array[i] == empty) {
                continue;
            } else if (op == add) {
                sum +=tmp;
            } else if (op == minus) {
                sum -=tmp;
            }
            tmp = 0;
            op = array[i];
        } else {
            tmp = tmp * 10 + array[i];
        }
    }
    if (op == add) sum +=tmp;
    if (op == minus) sum -=tmp;
    return sum == 0;
}

void printAns() {
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i & 1) {
            if (array[i] == 0) printf(" ");
            if (array[i] == 1) printf("+");
            if (array[i] == 2) printf("-");
        }
        else {
            printf("%d", array[i]);
        }
    }
    puts("");
}

void DFS(int deep) {
    if (deep == N - 1) {
        if (calc(N)) {
            calc(N);
            printAns();
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        array[deep * 2 + 1] = i;
        DFS(deep + 1);
    }
}

int main()
{
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        array[2 * i] = i + 1;
    }
    DFS(0);
    return 0;
}
