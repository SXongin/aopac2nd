/*UVa 10340
* 输入两个字符串 s 和 t，判断是否可以从t中删除 0 个或多个字符（顺序字符不变）,得到字符串s。
* 例如，abcde 可以得到 bce，但得不到dc。
*/

#include <cstdio>
#define MAX 10000
char s[MAX];
char t[MAX];

int main(void){
    scanf("%s", s);
    scanf("%s", t);
    int j = 0;
    for(int i = 0; s[i] != '\0'; ++i ){
        for( ; s[i]!=t[j] && t[j] !='\0'; ++j) {;}
        if(t[j] == '\0'){
            printf("no\n");return 0;
        }
    }
    printf("yes\n");
    return 0;
}