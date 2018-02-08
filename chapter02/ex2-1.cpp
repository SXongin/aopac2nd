/*
*输出 100~999中所有的水仙花数。若三位数ABC满足ABC=A^3+B^3+C^3，
*则称其为水仙花数。例如 153=1^3+5^3+3^3，所以153是水仙花数。
*/

#include <cstdio>
#include <ctime>

int main(void){
    // for(int n=100; n < 1000; ++n){
    //     int a = n/100;
    //     int b = n%100/10;
    //     int c = n%10;
    //     if(n == a*a*a + b*b*b + c*c*c){
    //         printf("%d\n", n);
    //     }
    // } 
    for(int a = 1; a < 10; ++a)
        for(int b = 0; b < 10; ++b)
            for(int c = 0; c < 10; ++c){
                int n = a*100 + b*10 +c;
                if(n == a*a*a + b*b*b + c*c*c){
                    printf("%d\n", n);
                }
            }
    printf("Time used = %.2fus\n", double(clock()) / CLOCKS_PER_SEC *1000 * 1000);
    return 0;
}