/*UVa 10474
* 现有N个大理石，每个大理石上写了一个非负整数。首先把各数从小到大排序，然后回答Q个问题。
* 每个问题问是否有某一个大理石上写着整数x，如果是，还要回答哪个大理石上写着x。排序后的
* 大理石编号为1~N。
* 样例输入：
* 4 1
* 2 3 5 1
* 5
* 5 2
* 1 3 3 3 1
* 2 3
* 样例输出：
* CASE# 1：
* 5 found at 4
* CASE# 2：
* 2 not found
* 3 found at 3
*/

#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;
using std::lower_bound;
using std::sort;

int main(void){
    vector<int> marbles;
    marbles.reserve(50);
    int n, q, kase = 1;
    int x;
    while(scanf("%d%d", &n, &q) == 2 && n != 0){
        printf("CASE$ %d\n", kase);
        ++kase;
        marbles.clear();
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            marbles.push_back(x);
        }
        sort(marbles.begin(), marbles.end());
        for(; q > 0; --q){
            scanf("%d", &x);
            auto it = lower_bound(marbles.cbegin(), marbles.cend(), x);
            if(*it == x){
                printf("%d found at %d\n", x, it - marbles.cbegin() + 1);
            }else{
                printf("%d not found\n", x);
            }
        }
    }
    return 0;
}