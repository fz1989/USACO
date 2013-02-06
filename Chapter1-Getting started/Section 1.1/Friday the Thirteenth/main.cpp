/*
ID: forusac5
PROG: friday
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
int N, ret[10], pre = 3;
int month[12]={31,31,28,31,30,31,30,31,31,30,31,30};

bool isLeapYear(int year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}
int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    scanf("%d", &N);
    MMset(ret, 0);

    for (int i = 0; i < N; i++) {
        if (isLeapYear(1900 + i))   month[2] = 29;
        else                        month[2] = 28;
        for (int j = 0; j < 12; j++) {
            pre = (pre + month[j]) % 7;
            ret[pre]++;
        }
    }

    for (int i = 0; i < 7; i++) {
        printf("%d%c", ret[(i + 6) % 7], i == 6 ? '\n' : ' ');
    }
    return 0;
}
