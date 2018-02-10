/*UVa 227
* 有一个 5*5 的网格，其中恰好有一个格子是空的，其他格子各有一个字母。
* 一共有4中指令：A，B，L，R，分别把空格上、下、左、右的相邻字母移到空格中。
* 输入初始网格和指令序列（以数字0结束），输出指令完毕后的网格。如果有非法指令，
* 应输出“This puzzle has no final configuration.”，例如：
* TRGSJ
* XDOKI
* M VLM
* WPABE
* UQHCF
* 执行ARRBBL0以后
* TRGSJ
* XOKLI
* MDVBN
* WP AE
* UQHCF
*/

#define LOCAL
#include <cstdio>
#define scale 5
char p[scale][scale];
const char msg[] = "This puzzle has no final configuration.";

int main(void){
#ifdef LOCAL
    freopen("puzzle_input.txt", "r", stdin);
    freopen("puzzle_output.txt", "w", stdout);
#endif
    int space_i = -1;
    int space_j = -1;
    int c;
    for(int i = 0; i < scale; ++i){
        for(int j = 0; j < scale; ++j){
            p[i][j] = getchar();
            if(p[i][j] == ' '){
                space_i = i;
                space_j = j;
            }
        }
        while(((c=getchar()) != EOF) && (c != '\n'));
    }
    while(((c=getchar()) != EOF) && (c!= '0')){
        switch(c){
        case 'A': {
            if(space_i - 1 >= 0){
                char t = p[space_i - 1][space_j];
                p[space_i - 1][space_j] = p[space_i][space_j];
                p[space_i][space_j] = t;
                --space_i;
            }else{
                printf(msg);return 0;
            }
            break;
        }

        case 'B': {
            if(space_i + 1 < scale){
                char t = p[space_i + 1][space_j];
                p[space_i + 1][space_j] = p[space_i][space_j];
                p[space_i][space_j] = t;
                ++space_i;
            }else{
                printf(msg);return 0;
            }
            break;
        }

        case 'R': {
            if(space_j + 1 < scale){
                char t = p[space_i][space_j + 1];
                p[space_i][space_j + 1] = p[space_i][space_j];
                p[space_i][space_j] = t;
                ++space_j;
            }else{
                printf(msg);return 0;
            }
            break;
        }

        case 'L': {
            if(space_j - 1 >= 0){
                char t = p[space_i][space_j - 1];
                p[space_i][space_j - 1] = p[space_i][space_j];
                p[space_i][space_j] = t;
                --space_j;
            }else{
                printf(msg);return 0;
            }
            break;
        }

        default: printf(msg);return 0;
        }
    }

    for(int i = 0; i < scale; ++i){
        for(int j = 0; j < scale; ++j){
            putchar(p[i][j]);
        }
        putchar('\n');
    }
    return 0;
}