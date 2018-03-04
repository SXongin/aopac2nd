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

#include <cstdio>
#include <cctype>
#define scale 5
char p[scale][scale];
const char msg[] = "This puzzle has no final configuration.\n";

int main(void){
#ifndef ONLINE_JUDGE
    freopen("puzzle_input.txt", "r", stdin);
    freopen("puzzle_output.txt", "w", stdout);
#endif
    int space_i = -1;
    int space_j = -1;
    int c;
    int kase = 1;
    while((c = getchar())!=EOF && c != 'Z'){
        if(c == ' '){
            space_i = 0;
            space_j = 0;
        }
        p[0][0] = c;
        for(int i = 0; i < scale; ++i){
            for(int j = 0; j < scale; ++j){
                if((i == 0)&&(j == 0)) continue;
                p[i][j] = getchar();
                if(p[i][j] == ' '){
                    space_i = i;
                    space_j = j;
                }
            }
            while(((c=getchar()) != EOF) && (c != '\n'));
        }
        bool ligal = true;
        char o;
        while(scanf("%c", &o)){
            if(isspace(o)) continue;
            if(o == '0') break;
            switch(o){
            case 'A': {
                if(space_i - 1 >= 0){
                    char t = p[space_i - 1][space_j];
                    p[space_i - 1][space_j] = p[space_i][space_j];
                    p[space_i][space_j] = t;
                    --space_i;
                }else{
                    ligal = false;
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
                    ligal = false;
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
                    ligal = false;
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
                    ligal = false;
                }
                break;
            }

            default: ligal = false; break;
            }
            if(!ligal) break;
        }
        if(o!='0'){
            while(((c=getchar()) != EOF) && (c != '0'));
        }
            while(((c=getchar()) != EOF) && (c != '\n'));
        if(kase > 1){
            printf("\n");
        }

        printf("Puzzle #%d:\n", kase);
        ++kase;

        if(!ligal){
            printf(msg);
        }else{
            for(int i = 0; i < scale; ++i){
                for(int j = 0; j < scale; ++j){
                    printf("%c", p[i][j]);
                    if(j != scale - 1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}