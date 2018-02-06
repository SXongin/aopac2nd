/*
* 一件衣服95元，若消费满300元， 可打八五折。输入购买衣服件数， 
* 输出需要支付的金额（单位：元），保留两位小数。
*/

#include <cstdio>

int main(void){
    int n;
    double p;
    scanf("%d", &n);
    p = n * 95;
    if(p > 300){
        p *= 0.85;
    }
    printf("%.2f\n", p);
    return 0;
}