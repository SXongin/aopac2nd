/*UVa 1368
* 输入m个长度为n的DNA序列，求一个DNA序列，到所有序列的 Hamming 距离尽量小。两个等长字符串的 Hamming 距离等于
* 字符不同位置的个数，例如，ACGT 和 GCGA 的距离为2（左数第1，4个字符不同）。
* 输入整数 m 和 n（4<=m<=50, 4<=n<=1000），以及 m 个长度为 n 的 DNA 序列（只包含字母A，C，G，T），输出到 m 个序列
* Hamming 距离和最小的DNA序列和对应的距离。如有多解，要求为字典序最小的解。
* 例如，对于下面5个 DNA 序列，最优解为 TAAGATGAC。
* TATGATAC
* TAAGCTAC
* AAAGATCC
* TGAGATAC
* TAAGATGT
*/

#include <cstdio>

#define MAXR 50
#define MAXC 1001

char DNAs[MAXR][MAXC];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("DNA_consensus_string_input.txt", "r", stdin);
    freopen("DNA_consensus_string_output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int m = 0,n = 0;
        char result[MAXC];
        const char base[] = {'A', 'C', 'G', 'T'};
        scanf("%d", &m);
        scanf("%d", &n);
        for(int i = 0; i < m; ++i){
            scanf("%s", DNAs[i]);
        }

        int hamming = 0;
        for(int j = 0; j < n; ++j){
            int min = m;
            for(int base_i = 0; base_i < 4; ++base_i){
                int temp = 0;
                for(int i = 0; i < m; ++i){
                    if(base[base_i] != DNAs[i][j]){
                        ++temp;
                    }
                }
                if(temp < min){
                    min = temp;
                    result[j] = base[base_i];
                }
            }
            hamming += min;
        }
        result[n] = '\0';
        printf("%s\n%d\n", result, hamming);
    }
    return 0;
}
