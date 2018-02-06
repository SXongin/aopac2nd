/*
* 输入正整数n（n<360) , 输出n度的正弦、余弦函数值。 提示：数学函数
*/

#include <cstdio>
#include <cmath>

int main(void){
    const double kPi = acos(-1.0);
    int d;
    double s, c;
    scanf("%d", &d);
    printf("%f %f\n", sin(d * kPi / 180), cos(d * kPi / 180));
    return 0;
}