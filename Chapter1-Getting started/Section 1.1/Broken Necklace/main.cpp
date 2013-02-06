/*
ID: forusac5
PROG: beads
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
char str[400];

int calc(int start, int adder, int len) {
    int redCount = 0, blueCount = 0;
    bool redOK = 1, blueOK = 1;
    for (int i = start, j = 0; j < len; i = (i + adder + len) % len, j++) {
        if (!redOK && !blueOK)  break;
        if (str[i] == 'w') {
            if (redOK)  redCount++;
            if (blueOK) blueCount++;
        }
        if (str[i] == 'r') {
            if (redOK)  redCount++;
            blueOK = 0;
        }
        if (str[i] == 'b') {
            if (blueOK) blueCount++;
            redOK = 0;
        }
    }
    return max(redCount, blueCount);
}



int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int N;
    scanf("%d%s", &N, str);
    int len = N, start, ans, ret = 0;
    for (int i = 0; i < len; i++) {
        start = i;
        ans = calc(start, 1, len);
        start = (i - 1 + len) % len;
        ans += calc(start, -1, len);
        ret = min(len, max(ret,ans));
    }
    printf("%d\n", ret);
    return 0;
}
