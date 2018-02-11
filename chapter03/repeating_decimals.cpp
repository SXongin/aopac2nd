/*UVa 202
* 输入整数 a 和 b（0<=a<=3000, 1<=b<=3000），输出 a/b 的循环小数表示以及循环节长度。例如 a=5，b=43，
* 小数表示为 0.(116279069767441860465)，循环节长度为21.
*/

#include <cstdio>
#include <cstring>
#define MAX 3100
char result[MAX];
int remainders[MAX] = {0};

int main(void){
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    sprintf(result, "%d", a/b);
    int int_length = strlen(result);
    int remainder = a%b;
    if(remainder == 0){
        printf("not repeating decimals\n");
        return 0;
    }else{
        ++remainders[remainder];
        result[int_length] = '.';
        result[int_length + 1] = '(';
    }
    int length = 1;
    remainder *= 10;
    for( ; ; remainder *= 10, ++length){
        result[int_length + 1 + length] = remainder/b + 48;
        remainder  %= b;
        if(remainder == 0){
            printf("not repeating decimals\n");
            return 0;
        }else{
            ++remainders[remainder];
            if(remainders[remainder] > 1){
                break;
            }
        }
    }
    result[int_length + 1 + length + 1] = ')';
    result[int_length + 1 + length + 2] = '\0';
    printf(result);
    printf("\n%d\n", length);
    return 0;
}
