/*
* 韩信点兵：输入包含多组数据，每组数据包含3个非负整数a,b,c，表示总数模3、5、7的余数，
* 输出总数的最小值（或报告无解）。已知总数不小于10，不超过100.输入到文件结束为止。
* 样例输入：
* 2 1 6
* 2 1 3
* 样例输出：
* Case 1: 41
* Case 2: No answer
*/

#define LOCAL
#include <cstdio>

int main(void){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, c, kase = 1;
    while(scanf("%d", &a) == 1){
        scanf("%d", &b);
        scanf("%d", &c);
        int answer = (a*70 + b*21 + c*15)%105;
        if(answer >= 10 && answer <= 100){
            printf("Case %d: %d\n", kase, answer);
        }else{
            printf("Case %d: No answer\n", kase);
        }
        
        ++kase;
    }
    return 0;
}