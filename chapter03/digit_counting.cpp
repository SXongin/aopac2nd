/*UVa 1225
* 把前n（n <= 10000)个整数顺次写在一起：123456789101112...数一数 0~9 各出现了多少次
* （输出10个整数，分别时0，1，2，...，9出现的次数）。
*/

#include <cstdio>

int main(void){
#ifndef ONLINE_JUDGE
    freopen("digit_counting_input.txt", "r", stdin);
    freopen("digit_counting_output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T>0){
        --T;
        int n;
        scanf("%d", &n);
        int results[10] = {0};
        for(int i = 1; i <= n; ++i){
            int m;
            int x = i;
            while(x>0){
                m = x%10;
                x = x/10;
                ++results[m];
            }
        }
        for(int i = 0; i < 9; ++i){
            printf("%d ", results[i]);
        }
        printf("%d\n", results[9]);
    }
}