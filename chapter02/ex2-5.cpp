/*
* 输入正整数a，b，c，输出a/b的小数形式，精确到小数点后c位。a,b<=10^6，c<=100。
* 输入包含多组数据，结束标志为a=b=c=0。
* 样例输入：
* 1 6 4
* 0 0 0
* 样例输出：
* Case 1: 0.1667
*/

#define LOCAL
#include <cstdio>

int main(void){
#ifdef LOCAL
    freopen("input2-5.txt", "r", stdin);
    freopen("output2-5.txt", "w", stdout);
#endif
    int a, b, c, kase = 1;
    while(scanf("%d", &a)==1 && scanf("%d", &b)==1 && scanf("%d", &c)==1 &&
          b != 0 && (a!=0 || b!=0 || c!=0)){
        printf("Case %d: %.*f\n", kase, c, double(a)/double(b));
        ++kase;
    }
    return 0;
}