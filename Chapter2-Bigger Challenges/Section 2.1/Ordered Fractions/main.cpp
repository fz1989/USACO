/*
ID:forusac5
LANG:C++
TASK:frac1
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
const int MAXN = 60;
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    else      return gcd(b, a % b);

}
struct Node {
    int a, b;
    Node(int _a = 0, int _b = 0) {
        a = _a, b = _b;
    }
};
bool cmp(Node a, Node b) {
    return a.a * b.b < b.a * a.b;
}
vector <Node> ret;
int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    int N;
    scanf("%d", &N);
    ret.push_back(Node(0, 1));
    ret.push_back(Node(1, 1));
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (gcd(i, j) == 1) {
                ret.push_back(Node(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end(), cmp);
    int len = ret.size();
    for (int i = 0; i < len; i++) {
        printf("%d/%d\n", ret[i].a, ret[i].b);
    }
    return 0;
}
