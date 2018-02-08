/*
* 输入两个正整数n<m<10^6, 输出1/n^2+1/(n+1)^2+...+1/m^2，保留5位小数。
* 输入包含多组数据，结束标记为n=m=0。提示：本题有陷阱。
*/

#define LOCAL
#include <cstdio>

int main(void){
#ifdef LOCAL
    freopen("input2-4.txt", "r", stdin);
    freopen("output2-4.txt", "w", stdout);
#endif
    int n, m, kase = 1;
    while(scanf("%d", &n)==1 && scanf("%d", &m)==1 && (n!=0 || m!=0) && n<m){
        double s = 0;
        for(int i = n; i<= m; ++i){
            long long int t = i;
            t *= i;
            s+=1.0/t;
        }
        printf("Case %d: %.5f\n", kase, s);
    }
    return 0;
}