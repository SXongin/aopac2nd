/*UVa 10340
* 输入两个字符串 s 和 t，判断是否可以从t中删除 0 个或多个字符（顺序字符不变）,得到字符串s。
* 例如，abcde 可以得到 bce，但得不到dc。
*/

#include <cstdio>
#define MAX 100005
char s[MAX];
char t[MAX];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("all_in_all_input.txt", "r", stdin);
    freopen("all_in_all_output.txt", "w", stdout);
#endif
    while(scanf("%s", s) != EOF){
        scanf("%s", t);
        int j = 0;
        int i = 0;
        for( ; s[i] != '\0'; ++i ){
            for( ; s[i]!=t[j] && t[j] !='\0'; ++j) {;}
            if(t[j] == '\0'){
                printf("No\n");break;
            }
            ++j;
        }
        if(s[i] == '\0'){
            printf("Yes\n");
        }//*/
        /*int i = 0;
        int j = 0;
        for(; t[j] != '\0'; ++j){
            if (s[i] == t[j]){
                ++i;
            }
            if(s[i]=='\0'){
                printf("Yes\n");
                break;
            }
        }
        if(s[i] != '\0'){
            printf("No\n");
        }//*/
    }
    return 0;
}
