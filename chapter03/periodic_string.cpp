/*UVa 455
* 如果一个字符串可以用某个长度为k的字符串重复多次得到，则称该串以k为周期。
* 例如，abcabcabc以3为周期（注意，它也以6和12为周期）。
* 输入一个长度不超过80的字符串，输出其最小周期。
*/

#include <cstdio>
#include <cstring>
#define MAXN 100
char s[MAXN];
int main(void){
#ifndef ONLINE_JUDGE
    freopen("periodic_string_input.txt", "r", stdin);
    freopen("periodic_string_output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    bool first = true;
    while(T-->0){
        scanf("%s", s);
        int length = strlen(s);
        int period;
        for(period = 1; period <= length/2; ++period){
            if(length%period != 0) continue;
            int times = length/period;
            bool ok = true;
            for(int i = 1; i < times; ++i){
                if(strncmp(&s[0], &s[i*period], period) != 0){
                    ok = false;
                    break;
                }
            }
            if(ok) break;
        }
        
        if(period > length/2) period = length;

        if(first){
            first = false;
        }else{
            printf("\n");
        }
        printf("%d\n", period);
    }
    return 0;
}
