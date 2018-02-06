/*
*输入华氏温度f, 输出对应的摄氏温度c，保留3位小数。 提示：c=5(f-32)/9
*/

#include <cstdio>

int main(void){
    double f,c;
    scanf("%lf", &f);
    c = 5 * (f - 32) / 9;
    printf("%.3f\n", c);
    return 0;
}