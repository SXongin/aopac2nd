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
    int c;
    int i = 0;
    int compare = 0;
    int pattern = 1;
    if(((c=getchar()) != EOF) && (c!='\n')){
        s[i++] = c;
    }else{
        return 0;
    }
    while(((c=getchar()) != EOF) && (c!='\n') ){
        s[i++] = c;
        if(c == s[compare]){
            ++compare;
            if(compare == pattern){
                compare = 0;
            }
        }else{
            compare = 0;
            pattern = i;
        }
    }
    if(pattern < strlen(s) && compare == 0){
        printf("%d\n", pattern);
    }else{
        printf("not periodic\n");
    }
    return 0;
}