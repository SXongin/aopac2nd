/*UVa 1588
* 给出两个长度为n_1，n_2（n_1,n_2<=100）且每列高度职位1或2的长条。需要将它们放入一个高度为3的容器，
* 问能够容纳它们的最短容器长度。
*/

#include <cstdio>
#include <cstring>
#define MAX 100 + 10

int container[3* MAX];
int strip1[MAX];
int strip2[MAX];
char s1[MAX];
char s2[MAX];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("kickdown_input.txt", "r", stdin);
    freopen("kickdown_output.txt", "w", stdout);
#endif
    while(scanf("%s", s1) == 1){
        scanf("%s", s2);
        int n1 = strlen(s1);
        int n2 = strlen(s2);
        for(int i = 0; i < n1; ++i){
           strip1[i] = s1[i] - '0';
        }
        for(int i = 0; i < n2; ++i){
            strip2[i] = s2[i] - '0';
        }
        int min = n1+n2;
        for(int offset = 0; offset < n1+n2-1; ++offset){
            int start = 0;
            int end = offset;
            if(offset >= n2){
                end = n2 -1;
            }
            if(offset >= n1){
                start = offset - n1 + 1;
            }

            bool ok = false;
            int j;
            for(j = start ; j <= end; ++j){
                if(strip2[j] + strip1[n1 - offset + j -1] > 3) break; 
            }
            if(j > end){
                ok = true;
            }/*else{
                for(j = start ; j <= end; ++j){
                    if(strip2[j] + strip1[offset - j] > 3) break; 
                }
                if(j > end){
                    ok = true;
                }
            }*/

            if(ok){
                int length =n1 + n2 -(end - start + 1);
                if(length < min) min = length;
            }

        }
        printf("%d\n", min);
    }
    return 0;
}
