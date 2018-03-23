/*UVa 1587
* 给定六个矩形的长和宽 w_i 和 h_i（1<=w_i, h_i<=1000)，判断他们能否构成长方体的6个面。
*/

#include <cstdio>

typedef struct {
    int w;
    int h;
} Rect;

bool Less(Rect l, Rect r){
    if(l.h == r.h){
        return l.w < r.w;
    }else{
        return l.h < r.h;
    }
}

void SwapRect(Rect* l, Rect* r){
    Rect t;
    t = *l;
    *l = *r;
    *r = t;
}

bool EqualRect(Rect l, Rect r){
    return l.w == r.w && l.h == r.h;
}
Rect rects[6];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("box_input.txt", "r", stdin);
    freopen("box_output.txt", "w", stdout);
#endif
    int w,h;
    while(scanf("%d%d", &w, &h) == 2){
        for(int i = 0; i < 6; ++i){
            if(i != 0) scanf("%d%d", &w, &h);
            if(w<h){
                int t = w;
                w = h;
                h = t;
            }
            rects[i].w = w;
            rects[i].h = h;
        }

        for(int i = 0; i < 6 -1; ++i){
            for(int j = 0; j < 6-i-1; ++j){
                if(Less(rects[j+1], rects[j])){
                    SwapRect(&rects[j+1], &rects[j]);
                }
            }
        }

        bool ok = true;
        for(int i = 0; i < 6; i+=2){
            if(!EqualRect(rects[i], rects[i+1])){
                ok = false;
            }
        }

        if(rects[0].h != rects[2].h) ok = false;
        if(rects[0].w != rects[4].h) ok = false;
        if(rects[2].w != rects[4].w) ok = false;

        if(!ok){
            printf("IMPOSSIBLE\n");
        }else{
            printf("POSSIBLE\n");
        }
    }
}

