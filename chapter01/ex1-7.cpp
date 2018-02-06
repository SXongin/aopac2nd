/*
* 输入年份，判断是否为闰年，如果是，则输出yes， 否则输出no。
*/

#include <cstdio>

int main(void){
    int y;
    scanf("%d", &y);
    if(y%4 != 0){
        printf("no\n");
    }else if((y%100 ==0) && (y%400 !=0)){
        printf("no\n");
    }else{
        printf("yes\n");
    }
    return 0;
}