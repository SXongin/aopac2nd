/*
* 输入正整数n<=20, 输出一个n层的倒三角形。例如，n=5时输出如下：
* #########
*  #######
*   #####
*    ###
*     #
*/

#include <cstdio>
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2*n - i - 1; ++j){
            if(j<i){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}