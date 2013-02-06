/*
ID: forusac5
PROG: ariprog
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
int N, M;
bool vis[250 * 250 * 2 + 1];
vector <pair<int, int> > ret;

bool check(int d, int start, int cnt) {
    for (int i = 0; i < cnt; i++, start += d) {
        if (start > 2 * M * M || !vis[start])
            return false;
    }
    return true;
}

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d%d", &N, &M);
    vector <int> s;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            s.push_back(i * i + j * j);
            vis[i * i + j * j] = 1;
        }
    }
    sort(s.begin(), s.end());
    int len = unique(s.begin(), s.end()) - s.begin();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (check(s[j] - s[i], s[i], N)) {
                ret.push_back(make_pair(s[j] - s[i], s[i]));
            }
        }
    }
    sort(ret.begin(), ret.end());
    len = ret.size();
    if (len == 0)   puts("NONE");
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", ret[i].second, ret[i].first);
    }
    return 0;
}
