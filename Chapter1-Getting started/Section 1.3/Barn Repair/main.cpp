/*
ID: forusac5
PROG: barn1
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
int M, S, C;
int cow[210];

int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    scanf("%d%d%d",&M, &S, &C);
    for (int i = 0; i < C; i++) {
        scanf("%d", cow + i);
    }

    sort(cow, cow + C);
    int ans = cow[C - 1] - cow[0] + 1;

    for (int i = 0; i + 1< C; i++) {
        cow[i] = cow[i + 1] - cow[i] - 1;
    }

    sort(cow, cow + C - 1);
    reverse(cow, cow + C - 1);
    int sum = 0;
    for (int i = 0; i < min(M - 1, C - 1); i++) {
        sum += cow[i];
    }
    printf("%d\n", ans - sum);
    return 0;
}
