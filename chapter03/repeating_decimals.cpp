/*UVa 202
* 输入整数 a 和 b（0<=a<=3000, 1<=b<=3000），输出 a/b 的循环小数表示以及循环节长度。例如 a=5，b=43，
* 小数表示为 0.(116279069767441860465)，循环节长度为21.
*/

#include <cstdio>
#include <cstring>
#define MAX 3100
char tmp[MAX];
char int_result[10];
char result[56];
int remainders[MAX] = {0};
int sites[MAX] = {0};
int length = 0;
int main(void){
#ifndef ONLINE_JUDGE
    freopen("repeating_decimals_input.txt", "r", stdin);
    freopen("repeating_decimals_output.txt", "w", stdout);
#endif
    int a,b;
    while(scanf("%d%d", &a, &b) == 2){
        memset(remainders, 0, MAX*sizeof(int));
        memset(sites, 0, MAX*sizeof(int));
        sprintf(int_result, "%d", a/b);
        int remainder = a%b;
        ++remainders[remainder];
        remainder *= 10;
        int site = 1;
        for( ; ; remainder *= 10, ++site){
            tmp[site - 1] = remainder/b + 48;
            remainder  %= b;
            ++remainders[remainder];
            if(remainders[remainder] > 1){
                length = site - sites[remainder];
                break;
            }else{
                sites[remainder] = site;
            }
        }
        tmp[site] = '\0';
        if(sites[remainder] >= 50){
            strncpy(result,tmp,50);
        }else{
            strncpy(result,tmp,sites[remainder]);
            result[sites[remainder]] = '(';
            if(site > 50){
                strncpy(&result[sites[remainder] + 1],&tmp[sites[remainder]], 50 - sites[remainder]);
                strcpy(&result[51],"...)");
            }else{
                strcpy(&result[sites[remainder] + 1],&tmp[sites[remainder]]);
                strcat(result,")");
            }
        }
        printf("%d/%d = %s.%s\n", a, b, int_result, result);
        printf("   %d = number of digits in repeating cycle\n\n", length);
    }
    return 0;
}
