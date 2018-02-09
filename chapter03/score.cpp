/*UVa 1585
* 给出一个由O和X组成的字符串（长度为 1~80），统计得分，每个O的得分为目前连续出现的O的个数，
* X的得分为0。例如，OOXXOXXOOO的得分为 1+2+0+0+1+0+0+1+2+3。
*/

#include <cstdio>

int main(){
    int scores = 0;
    int hits = 0;
    int c;
    while((c=getchar()) != EOF){
        if(c == 'O'){
            ++hits;
            scores += hits;
        }else if(c == 'X'){
            hits = 0;
        }
    }
    printf("%d\n", scores);
    return 0;
} 