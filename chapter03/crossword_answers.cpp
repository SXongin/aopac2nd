/*UVa 232
* 输入一个r行c列（1<=r,c<=10)的网格，黑格用“*”表示，每个白格都填有一个字母。如果一个白格的左边相邻位置或者
* 上边相邻位置没有白格。则称这个白格是一个起始格。接下来找出所有的横向单词（Across）。这些单词必须从一个起始格开始，
* 向右延伸到一个黑格的左边或者整个网格的最右列。最后找出所有竖向单词（Down）。这些单词必须从一个起始格开始，向下延伸
* 到一个黑格的上边或者整个网格的最下行。
*/

#define LOCAL
#include <cstdio>
#define MAX 10
char cw[MAX][MAX];

int main(void){
#ifdef LOCAL
    freopen("crossword_answers_input.txt", "r", stdin);
    freopen("crossword_answers_output.txt", "w", stdout);
#endif
    int r,c, game = 1;
    int isword = 0;
    while((scanf("%d", &r)==1) && (r > 0) && (scanf("%d", &c)==1) && (c > 0)){
        for(int i = 0; i < r; ++i){
            scanf("%s",cw[i]);
        }
        printf("Game %d:\n", game);
        ++game;
        printf("Across:\n  ");
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(cw[i][j] == '*'){
                    if(isword){
                        printf("\n  ");
                        isword = 0;
                    }
                }else{
                    putchar(cw[i][j]);
                    isword = 1;
                }
            }
            if(isword){
                printf("\n  ");
                isword = 0;
            }
        }

        printf("\nDown:\n  ");
        for(int j = 0; j < c; ++ j){
            for(int i = 0; i < r; ++i){
                if(cw[i][j] == '*'){
                    if(isword){
                        printf("\n  ");
                        isword = 0;
                    }
                }else{
                    putchar(cw[i][j]);
                    isword = 1;
                }
            }
            if(isword){
                printf("\n  ");
                isword = 0;
            }
        }
    }
    return 0;
}
