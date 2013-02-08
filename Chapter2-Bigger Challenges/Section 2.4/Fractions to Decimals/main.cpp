/*
ID: forusac5
PROG: fracdec
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
const int MAXN = 110000;
char ret[MAXN], buf[MAXN];
int last[MAXN];
int main()
{
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int N, D;
    scanf("%d %d", &N, &D);
    sprintf(ret, "%d.", N / D);
    MMset(last, -1);

    int remain = N % D, pos = 0;
    while (true) {
        if (remain == 0) {
            if (pos == 0) {
                strcat(ret, "0");
            } else {
                strcat(ret, buf);
            }
            break;
        }
        if (last[remain] != -1) {
            int start = last[remain];
            sprintf(ret + strlen(ret), "%.*s(%s)", start, buf, buf + start);
            break;
        }

        last[remain] = pos;
        buf[pos] = remain * 10 / D + '0';
        remain = remain * 10 % D;
        pos++;
    }
    int len = strlen(ret);
    for (int i = 0; i < len; i += 76) {
        printf("%.76s\n", ret+i);
    }
    return 0;
}
