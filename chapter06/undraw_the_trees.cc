/*UVa 10562
* 你的任务是将多叉树转化为括号表示法。每个结点用除了“-”、“|”和空格的其他字符表示，每个非叶结点的正下方总会有一个“|”字符，
* 然后下方是一排“-”字符，恰好覆盖所有子结点的上方。单独的一行“#”为数据的结束标记。
* 样例输入：
* 2
*     A
*     |
* --------
* B  C   D
*    |   |
*  ----- -
*  E   F G
* #
* e
* |
* ----
* f g
* #
* 样例输出：
* (A(B()C(E()F())D(G())))
* (e(f()g()))
*/

#include <cstdio>
#include <cstring>
#include <cctype>

const int kMax = 100+10;
char tree[kMax][kMax];
int height;

void dfs(int r, int c){
    printf("%c(", tree[r][c]);
    if(r+3 < height && tree[r+1][c] == '|'){
        int i = c;
        while(tree[r+2][i-1] >= 0 && tree[r+2][i-1] == '-') --i;
        for( ;tree[r+2][i] == '-' && tree[r+3][i] != '\0'; ++i){
            if(!isspace(tree[r+3][i]) && tree[r+3][i] != '|' && tree[r+3][i] != '-' && tree[r+3][i] != '#') dfs(r+3, i);
        }
    }
    printf(")");
}

void start(void){
    height = 0;
    while(true){
        fgets(tree[height],kMax,stdin);
        if(tree[height][0] == '#') break;
        ++height;
    }
    putchar('(');
    if(height > 0) {
        for(int i = 0; i < strlen(tree[0]); ++i){
            if(tree[0][i] != ' ' && tree[0][i] != '|' && tree[0][i] != '-' && tree[0][i] != '#') {
                dfs(0, i);
                break;
            }
        }
    }
    putchar(')');
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("undraw_the_trees_input.txt", "r", stdin);
    freopen("undraw_the_trees_output.txt", "w", stdout);
#endif
    memset(tree, 0, kMax*kMax*sizeof(char));
    fgets(tree[0], kMax, stdin);
    int T;
    sscanf(tree[0], "%d", &T);
    while(T>0){
        --T;
        start();
        putchar('\n');
    }
    return 0;
}
