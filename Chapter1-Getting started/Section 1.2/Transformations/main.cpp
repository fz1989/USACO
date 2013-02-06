/*
ID: forusac5
PROG: transform
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
int N;
char src[20][20], dest[20][20], tmp[20][20], out[20][20], buf[20][20];

void Rotate(int l, char s[][20], char d[][20]) {
    MMset(d, '\0');
    MMset(buf, '\0');
    memcpy(buf, s, sizeof(src));
    for (int t = 0; t < l; t++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[j][N - 1 - i] = buf[i][j];
            }
        }
        memcpy(buf, d, sizeof(src));
    }
}

void Mirror(char s[][20], char d[][20]) {
    MMset(d, '\0');
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = s[i][N - 1 - j];
        }
    }
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    scanf("%d", &N);
    MMset(src, '\0');
    MMset(dest, '\0');
    for (int i = 0; i < N; i++) {
        scanf("%s", src[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", dest[i]);
    }
    for (int i = 1; i <= 6; i++) {
        if (i != 5) {
            if (i <= 3) {
                Rotate(i, src, out);
            } else if (i == 4) {
                Mirror(src, out);
            } else {
                memcpy(out, src, sizeof(src));
            }
            if (memcmp(out, dest, sizeof(dest)) == 0) {
                printf("%d\n", i);
                return 0;
            }
        } else {
            Mirror(src, tmp);
            for (int j = 1; j <= 3; j++) {
                Rotate(j, tmp, out);
                if (memcmp(out, dest, sizeof(dest)) == 0) {
                    printf("%d\n", i);
                    return 0;
                }
            }
        }
    }
    printf("7\n");
    return 0;
}
