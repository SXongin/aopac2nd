/*
*输入正整数n，输出 1+2+3+...+n 的值。 提示：目标是解决问题，而不是联系编程。
*/

#include <cstdio>

int main(void){
    int n;
    int s;
    scanf("%d", &n);
    s = n * (n + 1) / 2;
    printf("%d\n", s);
    return 0;
}