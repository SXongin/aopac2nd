/*UVa 1585
* 给出一个由O和X组成的字符串（长度为 1~80），统计得分，每个O的得分为目前连续出现的O的个数，
* X的得分为0。例如，OOXXOXXOOO的得分为 1+2+0+0+1+0+0+1+2+3。
*/

#define LOCAL
#include <cstdio>

int main(){
#ifdef LOCAL
    freopen("score_input.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while(T!=0 && getchar()!='\n'){
        ;
    }
    while(T>0){
        --T;
        int c;
        int scores = 0;
        int hits = 0;
        while((c=getchar()) != EOF && c != '\n'){
            if(c == 'O'){
                ++hits;
                scores += hits;
            }else if(c == 'X'){
                hits = 0;
            }
        }
        printf("%d\n", scores);
    }
    return 0;
} 