/*
ID:forusac5
LANG:C++
TASK:packrec
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

using namespace std;

struct RECT {
    int w, h;
    void input() {
        scanf("%d%d", &w, &h);
    }
    void swap() {
        w = w ^ h;
        h = w ^ h;
        w = w ^ h;
    }
}rect[4], nowrect[4];
int perm[4] = {0, 1, 2, 3};
vector <pair<int, int> > ret;
int maxArea = -1;

void update(int id, int w, int h) {
    if (maxArea == -1 || w * h < maxArea) {
        maxArea = w * h;
        ret.clear();
        ret.push_back(make_pair(min(w, h), max(w, h)));
    } else if (maxArea == w * h) {
        ret.push_back(make_pair(min(w, h), max(w, h)));
    }
}

void swapAndRotate(int state) {
    for (int i = 0; i < 4; i++) {
        nowrect[i] = rect[perm[i]];
    }
    for (int i = 0; i < 4; i++) {
        if (state & (1 << i)) {
            nowrect[i].swap();
        }
    }
    int w1 = nowrect[0].w;
    int w2 = nowrect[1].w;
    int w3 = nowrect[2].w;
    int w4 = nowrect[3].w;
    int h1 = nowrect[0].h;
    int h2 = nowrect[1].h;
    int h3 = nowrect[2].h;
    int h4 = nowrect[3].h;
    int width, height;
    //Case 1;
    //1 2 3 4
    width = w1 + w2 + w3 + w4;
    height = max(max(h1, h2), max(h3, h4));
    update(1, width, height);

    //case 2
    // 1 2 3
    //     4
    width = max(w1 + w2 + w3, w4);
    height = max(h1, max(h2, h3)) + h4;
    update(2, width, height);

    //case 3
    //1 2
    //    4
    //  3
    width = max(w1 + w2, w3) + w4;
    height = max(max(h1, h2) + h3, h4);
    update(3, width, height);

    //case4 and 5
    //1 2 4
    //  3
    width = w1 + max(w2, w3) + w4;
    height = max(h1, max(h2 + h3, h4));
    update(4, width, height);

    //case 6
    /*
        1   3
        2   4
    */
    height = max(h1 + h2, h3 + h4);
    if (h2 < h4) {
        width = max(w1, w2) + max(w3, w4);
    } else if (h2 == h4) {
        width = max(w1 + w3 , w2 + w4);
    }
    else if (h2 > h4 && h2 < h3 + h4) {
        if (w1 <= w2) width = w2 + max(w3, w4);
        else          width = max(w1 + w3, w2 + w4);
    }
    else {
        width = max(w1, max(w3, w4) + w2);
    }
    update(5, width, height);
}

int main()
{
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    for (int i = 0; i < 4; i++) {
        rect[i].input();
    }
    do {
        for (int i = 0; i < 16; i++) {
            swapAndRotate(i);
        }
    } while (next_permutation(perm, perm + 4));

    sort(ret.begin(), ret.end());
    int len = unique(ret.begin(), ret.end()) - ret.begin();
    printf("%d\n", maxArea);
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", ret[i].first, ret[i].second);
    }
    return 0;
}
