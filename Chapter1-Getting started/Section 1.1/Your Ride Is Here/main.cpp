/*
ID: forusac5
PROG: ride
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
char str1[10], str2[10];
int calc(char *s) {
    int ret = 1, len = strlen(s);
    for (int i = 0; i < len; i++) {
        ret = (ret * (s[i] - 'A' + 1)) % 47;
    }
    return ret % 47;
}
int main()
{
    freopen("ride.in", "r",stdin);
    freopen("ride.out", "w",stdout);
    scanf("%s", str1);
    scanf("%s", str2);
    if (calc(str1) == calc(str2))   puts("GO");
    else                            puts("STAY");
    return 0;
}
