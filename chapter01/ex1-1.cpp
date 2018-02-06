/*
*输入3个整数，输出它们的平均值， 保留3位小数
*/

#include <cstdio>

int main(void){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    float ave = (a + b + c)/3;
    printf("%.3f\n", ave);
    return 0;
}