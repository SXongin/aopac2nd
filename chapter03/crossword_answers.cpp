/*UVa 232
* 输入一个r行c列（1<=r,c<=10)的网格，黑格用“*”表示，每个白格都填有一个字母。如果一个白格的左边相邻位置或者
* 上边相邻位置没有白格。则称这个白格是一个起始格。接下来找出所有的横向单词（Across）。这些单词必须从一个起始格开始，
* 向右延伸到一个黑格的左边或者整个网格的最右列。最后找出所有竖向单词（Down）。这些单词必须从一个起始格开始，向下延伸
* 到一个黑格的上边或者整个网格的最下行。
*/

#include <cstdio>
#include <vector>
#define MAX 10+2
char cw[MAX][MAX];//for '\0'

struct Word{
    char cs[MAX];
    int order;
};

std::vector<Word> across;
std::vector<Word> down;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("crossword_answers_input.txt", "r", stdin);
    freopen("crossword_answers_output.txt", "w", stdout);
#endif
    int r,c, puzzle = 1;
    bool isfirst = true;
    int isword = 0;
    across.reserve(MAX*MAX);
    down.reserve(MAX*MAX);
    while((scanf("%d", &r)==1) && (r > 0) && (scanf("%d", &c)==1) && (c > 0)){
        for(int i = 0; i < r; ++i){
            scanf("%s",cw[i]);
        }
        int order = 0;
        across.clear();
        down.clear();
        if(isfirst){
            isfirst = false;
        }else{
            printf("\n");
        }
        printf("puzzle #%d:\n", puzzle);
        ++puzzle;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if((cw[i][j] != '*') && ((i-1 < 0 || cw[i-1][j] == '*') || (j-1 < 0 || cw[i][j-1] == '*'))){
                    ++order;
                    Word aword;
                    aword.order = order;
                    aword.cs[0] = cw[i][j];
                    if(j-1 < 0 || cw[i][j-1] == '*'){
                        int index = 1;
                        while( j+index < c && cw[i][j+index] != '*'){
                            aword.cs[index] = cw[i][j+index];
                            ++index;
                        }
                        aword.cs[index] = '\0';
                        across.push_back(aword);
                    }
                    Word dword;
                    dword.order = order;
                    dword.cs[0] = cw[i][j];
                    if(i-1 < 0 || cw[i-1][j] == '*'){
                        int index = 1;
                        while( i+index < r && cw[i+index][j] != '*'){
                            dword.cs[index] = cw[i+index][j];
                            ++index;
                        }
                        dword.cs[index] = '\0';
                        down.push_back(dword);
                    }
                }
            }
        }
        printf("Across\n");
        for(auto &answer : across){
            printf("%3d.%s\n", answer.order, answer.cs);
        }
        printf("Down\n");
        for(auto &answer : down){
            printf("%3d.%s\n", answer.order, answer.cs);
        }
    }
    return 0;
}
