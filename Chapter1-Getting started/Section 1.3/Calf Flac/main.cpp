/*
ID: forusac5
PROG: calfflac
LANG: C++
*/
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
int M, S, C, len = 0, newlen = 0, ret = 1,left = 0, right = 0;
char str[20100], newstr[20100];
int  pos[20100];

void calc(int l, int r) {
    while (l > -1 && r <newlen) {
        if (newstr[l] == newstr[r]) {
            l--, r++;
        } else {
            break;
        }
    }
    if (r - l + 1 - 2 > ret) {
        ret = r - l + 1 - 2;
        left = pos[l + 1];
        right = pos[r - 1];
    }
}
int main()
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    char ch;
    while (scanf ("%c", &ch) != EOF) {
       str[len++] = ch;
    }
    str[len] = '\0';
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            pos[newlen] = i;
            newstr[newlen++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            pos[newlen] = i;
            newstr[newlen++] = str[i] - 'A' + 'a';
        }
    }
    newstr[newlen] = '\0';

    for (int i = 0; i < newlen; i++) {
        calc(i,i + 1);
        calc(i - 1, i + 1);
    }
    printf("%d\n", ret);
    for (int i = left; i <= right; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
