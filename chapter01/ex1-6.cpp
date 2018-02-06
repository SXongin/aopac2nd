/*
* 输入三角形的三条边的长度值（均为正整数），判断是否能为直角三角形的三个边长。
* 如果可以，则输出yes，如果不能则输出no。如果根本无法构成三角形， 则输出not a triangle。
*/

#include <cstdio>

int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    if(b > c){
        int t = b;
        b = c;
        c = t;
    }
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    if(a*a + b*b == c*c){
        printf("yes\n");
    }else if(a + b <= c){
        printf("not a triangle\n");
    }else{
        printf("no\n");
    }
}