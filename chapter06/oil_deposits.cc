/*UVa 572
* 输入一个m行n列的字符矩阵，统计字符“@”组成了多少个八连块。如果两个字符“@”所在的格子相邻（横、竖或者对角线方向），
* 就说他们属于同一个八连块。
* 样例输入：
* 5 5
* ****@
* *@@*@
* *@**@
* @@@*@
* @@**@
* 样例输出：
* 2
*/

#include <cstdio>
#include <cstring>

const int MAXN = 100 + 5;
char pic[MAXN][MAXN];
int idx[MAXN][MAXN];
int m, n;

void dfs(int r, int c, int cnt){
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    if(idx[r][c] > 0 || pic[r][c] != '@') return;
    idx[r][c] = cnt;
    for(int dr = -1; dr < 2; ++dr)
        for(int dc = -1; dc < 2; ++dc){
            if(dr != 0 || dc != 0) dfs(r+dr, c +dc, cnt);
        }
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("oil_deposits_input.txt", "r", stdin);
    freopen("oil_deposits_output.txt", "w", stdout);
#endif
    while(scanf("%d%d", &m, &n) == 2 && m > 0 && n>0){
        for(int i = 0; i < m; ++i){
            scanf("%s", pic[i]);
        }
        memset(idx, 0, MAXN*MAXN*sizeof(int));
        int cnt = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(idx[i][j] == 0 && pic[i][j] == '@'){
                    ++cnt;
                    dfs(i,j,cnt);
                }
            }
        printf("%d\n", cnt);
    }
    return 0;
}
