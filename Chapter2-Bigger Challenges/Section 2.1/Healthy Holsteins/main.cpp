/*
ID:forusac5
LANG:C++
TASK:holstein
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <string>
#define MMset(a,b) memset(a, b, sizeof(a))
const int MAXN = 20;

using namespace std;
int V, N;
struct Node {
    int val[30];
    void input() {
        for (int i = 0; i < V; i++) {
            scanf("%d", val + i);
        }
    }
}good[MAXN], goal;
int sum[30];

bool checkMin(vector <int> a, vector <int> b) {
    if (a.size() > b.size()) return false;
    else if (a.size() == b.size()) {
        int len = a.size();
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return true;
    }
    return true;
}

bool check() {
    for (int i = 0; i < V; i++) {
        if (goal.val[i] > sum[i])   return false;
    }
    return true;
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    scanf("%d", &V);
    goal.input();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        good[i].input();
    }
    vector <int> ret, tmp;
    if ((1 << N) < 0) while (1);
    for (int i = 0; i < (1 << N); i++) {
        memset(sum, 0, sizeof(sum));
        tmp.clear();
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < V; k++) {
                    sum[k] += good[j].val[k];
                }
                tmp.push_back(j + 1);
            }
        }
        if (check()) {
            if (ret.size() == 0 || checkMin(tmp, ret)) {
                ret.clear();
                int len = tmp.size();
                for (int j = 0; j < len; j++) {
                    ret.push_back(tmp[j]);
                }
            }
        }
    }
    printf("%d", ret.size());
    for (int i = 0; i < ret.size(); i++) {
        printf(" %d", ret[i]);
    }
    printf("\n");
    return 0;
}
