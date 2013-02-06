/*
ID: forusac5
PROG: milk2
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
struct Point {
    int start, end;
    void input() {
        scanf("%d%d", &start, &end);
    }
}point[5001];
int N;

bool cmp(Point a, Point b) {
    if (a.start == b.start) return a.end < b.end;
    return                  a.start < b.start;
}
int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        point[i].input();
    }
    sort(point, point + N, cmp);
    int ans = point[0].end - point[0].start;
    int ret = 0;
    int start = point[0].start, end = point[0].end;
    for (int i = 1; i < N; i++) {
        if (point[i].start > end) {
            ret = max(ret, point[i].start - end);
            start = point[i].start;
            end = point[i].end;
        } else {
            end = max(end, point[i].end);
            ans = max(ans, end - start);
        }
    }
    printf("%d %d\n", ans, ret);
    return 0;
}
