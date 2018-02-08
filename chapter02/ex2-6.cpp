/*
* 用 1,2,3,...,9 组成三个三位数 abc,def 和 ghi，每个数字恰好用一次，
* 要求 abc:def:ghi = 1:2:3。按照 “abc def ghi” 的格式输出所有解。
* 每行一个解。提示：不必太动脑筋。
*/

#include <cstdio>

int main(void){
    for(int abc = 123; abc < 330; ++abc){
        int def = abc * 2;
        int ghi = abc * 3;
        const int numbers[9]={abc/100, abc%100/10, abc%10, def/100, def%100/10,
                              def%10, ghi/100, ghi%100/10, ghi%10};
        int counts[10]={1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        bool ok = true;
        for(int i=0; i<9; ++i){
            ++counts[numbers[i]];
            if(counts[numbers[i]] > 1){
                ok = false;
                break;
            }
        }
        if(ok){
            printf("%d %d %d\n", abc, def, ghi);
        }
    }
    return 0;
}